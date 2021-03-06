/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>
#include "fsl_common.h"
#include "fsl_debug_console.h"
#include "fsl_elcdif.h"
#include "fsl_cache.h"
#include "board.h"

#include "pin_mux.h"
#include "fsl_gpio.h"
#include "fsl_pit.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define APP_ELCDIF LCDIF

#define APP_IMG_HEIGHT 272
#define APP_IMG_WIDTH 480
#define APP_HSW 41
#define APP_HFP 4
#define APP_HBP 8
#define APP_VSW 10
#define APP_VFP 4
#define APP_VBP 2
#define APP_POL_FLAGS \
    (kELCDIF_DataEnableActiveHigh | kELCDIF_VsyncActiveLow | kELCDIF_HsyncActiveLow | kELCDIF_DriveDataOnRisingClkEdge)

#define APP_LCDIF_DATA_BUS kELCDIF_DataBus16Bit

/* Display. */
#define LCD_DISP_GPIO GPIO1
#define LCD_DISP_GPIO_PIN 2
/* Back light. */
#define LCD_BL_GPIO GPIO2
#define LCD_BL_GPIO_PIN 31

/* Frame buffer data alignment, for better performance, the LCDIF frame buffer should be 64B align. */
#define FRAME_BUFFER_ALIGN 64
/*
 * For better performance, three frame buffers are used in this demo.
 */
#define APP_LCD_FB_NUM 3 /* LCD frame buffer number. */
#define APP_LCD_FB_BPP 3 /* LCD frame buffer byte per pixel, RGB888 format, 24-bit. */

/* Cache line size. */
#ifndef FSL_FEATURE_L2CACHE_LINESIZE_BYTE
#define FSL_FEATURE_L2CACHE_LINESIZE_BYTE 0
#endif
#ifndef FSL_FEATURE_L1DCACHE_LINESIZE_BYTE
#define FSL_FEATURE_L1DCACHE_LINESIZE_BYTE 0
#endif

#if (FSL_FEATURE_L2CACHE_LINESIZE_BYTE > FSL_FEATURE_L1DCACHE_LINESIZE_BYTE)
#define APP_CACHE_LINE_SIZE FSL_FEATURE_L2CACHE_LINESIZE_BYTE
#else
#define APP_CACHE_LINE_SIZE FSL_FEATURE_L1DCACHE_LINESIZE_BYTE
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void BOARD_EnableLcdInterrupt(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

static volatile bool g_lcdFramePending = false;

const uint32_t s_imagePics = 18;
const uint32_t s_imageStartAddr = 0x61000000;

volatile uint32_t s_timerHighCounter = 0;

/*******************************************************************************
 * Code
 ******************************************************************************/
extern void APP_LCDIF_IRQHandler(void);

void LCDIF_IRQHandler(void)
{
    APP_LCDIF_IRQHandler();
    __DSB();
}

/* Enable interrupt. */
void BOARD_EnableLcdInterrupt(void)
{
    EnableIRQ(LCDIF_IRQn);
}

/* Initialize the LCD_DISP. */
void BOARD_InitLcd(void)
{
    gpio_pin_config_t config = {
        kGPIO_DigitalOutput, 0,
    };

    /* Backlight. */
    config.outputLogic = 1;
    GPIO_PinInit(LCD_BL_GPIO, LCD_BL_GPIO_PIN, &config);
}

void BOARD_InitLcdifPixelClock(void)
{
    /*
     * The desired output frame rate is 60Hz. So the pixel clock frequency is:
     * (480 + 41 + 4 + 18) * (272 + 10 + 4 + 2) * 60 = 9.2M.
     * Here set the LCDIF pixel clock to 9.3M.
     */

    /*
     * Initialize the Video PLL.
     * Video PLL output clock is OSC24M * (loopDivider + (denominator / numerator)) / postDivider = 93MHz.
     */
    clock_video_pll_config_t config = {
        .loopDivider = 31, .postDivider = 8, .numerator = 0, .denominator = 0,
    };

    CLOCK_InitVideoPll(&config);

    /*
     * 000 derive clock from PLL2
     * 001 derive clock from PLL3 PFD3
     * 010 derive clock from PLL5
     * 011 derive clock from PLL2 PFD0
     * 100 derive clock from PLL2 PFD1
     * 101 derive clock from PLL3 PFD1
     */
    CLOCK_SetMux(kCLOCK_LcdifPreMux, 2);

    CLOCK_SetDiv(kCLOCK_LcdifPreDiv, 4);

    CLOCK_SetDiv(kCLOCK_LcdifDiv, 1);
}

void APP_LCDIF_IRQHandler(void)
{
    uint32_t intStatus;

    intStatus = ELCDIF_GetInterruptStatus(APP_ELCDIF);

    ELCDIF_ClearInterruptStatus(APP_ELCDIF, intStatus);

    if (intStatus & kELCDIF_CurFrameDone)
    {
        if (g_lcdFramePending)
        {
            g_lcdFramePending = false;
        }
    }
    __DSB();
}

void APP_ELCDIF_Init(void)
{
    const elcdif_rgb_mode_config_t config = {
        .panelWidth = APP_IMG_WIDTH,
        .panelHeight = APP_IMG_HEIGHT,
        .hsw = APP_HSW,
        .hfp = APP_HFP,
        .hbp = APP_HBP,
        .vsw = APP_VSW,
        .vfp = APP_VFP,
        .vbp = APP_VBP,
        .polarityFlags = APP_POL_FLAGS,
        .bufferAddr = (uint32_t)0,
        .pixelFormat = kELCDIF_PixelFormatRGB888,
        .dataBus = APP_LCDIF_DATA_BUS,
    };

    ELCDIF_RgbModeInit(APP_ELCDIF, &config);
}

void PIT_IRQ_HANDLER(void)
{
    /* Clear interrupt flag.*/
    PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
    s_timerHighCounter++;
}

void timer_pit_init(void)
{
    /* Structure of initialize PIT */
    pit_config_t pitConfig;
    PIT_GetDefaultConfig(&pitConfig);
    /* Init pit module */
    PIT_Init(PIT, &pitConfig);
    /* Set max timer period for channel 0 */
    PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, (uint32_t)~0);
    /* Enable timer interrupts for channel 0 */
    PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
    /* Enable at the NVIC */
    EnableIRQ(PIT_IRQn);
    /* Start channel 0 */
    PIT_StartTimer(PIT, kPIT_Chnl_0);

    s_timerHighCounter = 0;
}

/* Porting : Timing functions
    How to capture time and convert to seconds must be ported to whatever is supported by the platform.
    e.g. Read value from on board RTC, read value from cpu clock cycles performance counter etc.
    Sample implementation for standard time.h and windows.h definitions included.
*/
uint64_t timer_pit_get_ticks() {
    uint64_t retVal;
    uint32_t high;
    uint32_t low;
    do
    {
        high = s_timerHighCounter;
        low = ~PIT_GetCurrentTimerCount(PIT, kPIT_Chnl_0);
    } while (high != s_timerHighCounter);
    retVal = ((uint64_t)high << 32U) + low;

    return retVal;
}

/*!
 * @brief Main function
 */
int main(void)
{
    uint8_t *imageAddr = (uint8_t *)s_imageStartAddr;
    uint32_t imageBytes = APP_IMG_HEIGHT * APP_IMG_WIDTH * APP_LCD_FB_BPP;
    bool isTimerEnabled = false;
    bool isTimeRecorded = false;

    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitLcdifPixelClock();
    BOARD_InitDebugConsole();
    BOARD_InitLcd();

    PRINTF("Flash JPEG demo start:\r\n");

    APP_ELCDIF_Init();

    BOARD_EnableLcdInterrupt();

    ELCDIF_EnableInterrupts(APP_ELCDIF, kELCDIF_CurFrameDoneInterruptEnable);
    ELCDIF_RgbModeStart(APP_ELCDIF);

    while (1)
    {
        DCACHE_CleanInvalidateByRange((uint32_t)imageAddr, imageBytes);

        /* Make sure previous set frame buffer is actived and shown. */
        while (g_lcdFramePending)
        {
        }

        ELCDIF_SetNextBufferAddr(APP_ELCDIF, (uint32_t)imageAddr);
        g_lcdFramePending = true;

        imageAddr += imageBytes;
        if ((uint32_t)imageAddr >= (s_imageStartAddr + imageBytes * s_imagePics))
        {
            imageAddr = (uint8_t *)s_imageStartAddr;
            if (isTimerEnabled)
            {
                if (!isTimeRecorded)
                {
                    uint64_t ticks = timer_pit_get_ticks();
                    PIT_StopTimer(PIT, kPIT_Chnl_0);
                    double secs = ticks / 24000000.0;
                    PRINTF("Seconds per Round: %2.6f \r\n", secs);
                    
                    isTimeRecorded = true;
                }
            }
            else
            {
                timer_pit_init();
                isTimerEnabled = true;
            }
        }
    }
}
