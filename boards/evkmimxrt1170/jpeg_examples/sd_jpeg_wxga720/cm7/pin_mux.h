/*
 * Copyright 2018-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_AD_B0_13 (coord L14), UART1_RXD */
#define BOARD_INITPINS_UART1_RXD_PERIPHERAL                              LPUART1   /*!< Device name: LPUART1 */
#define BOARD_INITPINS_UART1_RXD_SIGNAL                                       RX   /*!< LPUART1 signal: RX */

/* GPIO_AD_B0_12 (coord K14), UART1_TXD */
#define BOARD_INITPINS_UART1_TXD_PERIPHERAL                              LPUART1   /*!< Device name: LPUART1 */
#define BOARD_INITPINS_UART1_TXD_SIGNAL                                       TX   /*!< LPUART1 signal: TX */

/* GPIO_B0_00 (coord D7), LCDIF_CLK */
#define BOARD_INITPINS_LCDIF_CLK_PERIPHERAL                                LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_CLK_SIGNAL                                lcdif_clk   /*!< LCDIF signal: lcdif_clk */

/* GPIO_B0_04 (coord C8), LCDIF_D0/BT_CFG[0] */
#define BOARD_INITPINS_LCDIF_D0_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D0_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D0_CHANNEL                                       0U   /*!< LCDIF lcdif_data channel: 00 */

/* GPIO_B0_05 (coord B8), LCDIF_D1/BT_CFG[1] */
#define BOARD_INITPINS_LCDIF_D1_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D1_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D1_CHANNEL                                       1U   /*!< LCDIF lcdif_data channel: 01 */

/* GPIO_B0_06 (coord A8), LCDIF_D2/BT_CFG[2] */
#define BOARD_INITPINS_LCDIF_D2_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D2_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D2_CHANNEL                                       2U   /*!< LCDIF lcdif_data channel: 02 */

/* GPIO_B0_07 (coord A9), LCDIF_D3/BT_CFG[3] */
#define BOARD_INITPINS_LCDIF_D3_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D3_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D3_CHANNEL                                       3U   /*!< LCDIF lcdif_data channel: 03 */

/* GPIO_B0_08 (coord B9), LCDIF_D4/BT_CFG[4] */
#define BOARD_INITPINS_LCDIF_D4_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D4_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D4_CHANNEL                                       4U   /*!< LCDIF lcdif_data channel: 04 */

/* GPIO_B0_09 (coord C9), LCDIF_D5/BT_CFG[5] */
#define BOARD_INITPINS_LCDIF_D5_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D5_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D5_CHANNEL                                       5U   /*!< LCDIF lcdif_data channel: 05 */

/* GPIO_B0_10 (coord D9), LCDIF_D6/BT_CFG[6] */
#define BOARD_INITPINS_LCDIF_D6_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D6_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D6_CHANNEL                                       6U   /*!< LCDIF lcdif_data channel: 06 */

/* GPIO_B0_11 (coord A10), LCDIF_D7/BT_CFG[7] */
#define BOARD_INITPINS_LCDIF_D7_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D7_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D7_CHANNEL                                       7U   /*!< LCDIF lcdif_data channel: 07 */

/* GPIO_B0_12 (coord C10), LCDIF_D8/BT_CFG[8] */
#define BOARD_INITPINS_LCDIF_D8_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D8_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D8_CHANNEL                                       8U   /*!< LCDIF lcdif_data channel: 08 */

/* GPIO_B0_13 (coord D10), LCDIF_D9/BT_CFG[9] */
#define BOARD_INITPINS_LCDIF_D9_PERIPHERAL                                 LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D9_SIGNAL                                lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D9_CHANNEL                                       9U   /*!< LCDIF lcdif_data channel: 09 */

/* GPIO_B0_14 (coord E10), LCDIF_D10/BT_CFG[10] */
#define BOARD_INITPINS_LCDIF_D10_PERIPHERAL                                LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D10_SIGNAL                               lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D10_CHANNEL                                     10U   /*!< LCDIF lcdif_data channel: 10 */

/* GPIO_B0_15 (coord E11), LCDIF_D11/BT_CFG[11] */
#define BOARD_INITPINS_LCDIF_D11_PERIPHERAL                                LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D11_SIGNAL                               lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D11_CHANNEL                                     11U   /*!< LCDIF lcdif_data channel: 11 */

/* GPIO_B1_00 (coord A11), LCDIF_D12 */
#define BOARD_INITPINS_LCDIF_D12_PERIPHERAL                                LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D12_SIGNAL                               lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D12_CHANNEL                                     12U   /*!< LCDIF lcdif_data channel: 12 */

/* GPIO_B1_01 (coord B11), LCDIF_D13 */
#define BOARD_INITPINS_LCDIF_D13_PERIPHERAL                                LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D13_SIGNAL                               lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D13_CHANNEL                                     13U   /*!< LCDIF lcdif_data channel: 13 */

/* GPIO_B1_02 (coord C11), LCDIF_D14 */
#define BOARD_INITPINS_LCDIF_D14_PERIPHERAL                                LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D14_SIGNAL                               lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D14_CHANNEL                                     14U   /*!< LCDIF lcdif_data channel: 14 */

/* GPIO_B1_03 (coord D11), LCDIF_D15 */
#define BOARD_INITPINS_LCDIF_D15_PERIPHERAL                                LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_D15_SIGNAL                               lcdif_data   /*!< LCDIF signal: lcdif_data */
#define BOARD_INITPINS_LCDIF_D15_CHANNEL                                     15U   /*!< LCDIF lcdif_data channel: 15 */

/* GPIO_B0_01 (coord E7), LCDIF_ENABLE */
#define BOARD_INITPINS_LCDIF_ENABLE_PERIPHERAL                             LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_ENABLE_SIGNAL                          lcdif_enable   /*!< LCDIF signal: lcdif_enable */

/* GPIO_B0_02 (coord E8), LCDIF_HSYNC */
#define BOARD_INITPINS_LCDIF_HSYNC_PERIPHERAL                              LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_HSYNC_SIGNAL                            lcdif_hsync   /*!< LCDIF signal: lcdif_hsync */

/* GPIO_B0_03 (coord D8), LCDIF_VSYNC */
#define BOARD_INITPINS_LCDIF_VSYNC_PERIPHERAL                              LCDIF   /*!< Device name: LCDIF */
#define BOARD_INITPINS_LCDIF_VSYNC_SIGNAL                            lcdif_vsync   /*!< LCDIF signal: lcdif_vsync */

/* GPIO_B1_15 (coord B14), USB_HOST_PWR/BACKLIGHT_CTL */
#define BOARD_INITPINS_BACKLIGHT_CTL_GPIO                                  GPIO2   /*!< GPIO device name: GPIO2 */
#define BOARD_INITPINS_BACKLIGHT_CTL_PORT                                  GPIO2   /*!< PORT device name: GPIO2 */
#define BOARD_INITPINS_BACKLIGHT_CTL_PIN                                     31U   /*!< GPIO2 pin index: 31 */

/* GPIO_AD_B0_02 (coord M11), USB_OTG1_PWR/J24[2]/LCD_RST */
#define BOARD_INITPINS_LCD_RST_GPIO                                        GPIO1   /*!< GPIO device name: GPIO1 */
#define BOARD_INITPINS_LCD_RST_PORT                                        GPIO1   /*!< PORT device name: GPIO1 */
#define BOARD_INITPINS_LCD_RST_PIN                                            2U   /*!< GPIO1 pin index: 2 */

/* GPIO_AD_B1_03 (coord M12), SPDIF_IN/J22[8] */
#define BOARD_INITPINS_SPDIF_IN_GPIO                                       GPIO1   /*!< GPIO device name: GPIO1 */
#define BOARD_INITPINS_SPDIF_IN_PORT                                       GPIO1   /*!< PORT device name: GPIO1 */
#define BOARD_INITPINS_SPDIF_IN_PIN                                          19U   /*!< GPIO1 pin index: 19 */

/* GPIO_B1_12 (coord D13), SD_CD_SW */
#define BOARD_INITPINS_SD_CD_SW_GPIO                                       GPIO2   /*!< GPIO device name: GPIO2 */
#define BOARD_INITPINS_SD_CD_SW_PORT                                       GPIO2   /*!< PORT device name: GPIO2 */
#define BOARD_INITPINS_SD_CD_SW_PIN                                          28U   /*!< GPIO2 pin index: 28 */

/* GPIO_SD_B0_01 (coord J3), SD1_CLK/J24[3] */
#define BOARD_INITPINS_SD1_CLK_PERIPHERAL                                 USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_CLK_SIGNAL                                  usdhc_clk   /*!< USDHC1 signal: usdhc_clk */

/* GPIO_SD_B0_00 (coord J4), SD1_CMD/J24[6] */
#define BOARD_INITPINS_SD1_CMD_PERIPHERAL                                 USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_CMD_SIGNAL                                  usdhc_cmd   /*!< USDHC1 signal: usdhc_cmd */

/* GPIO_SD_B0_02 (coord J1), SD1_D0/J24[4]/SPI_MOSI/PWM */
#define BOARD_INITPINS_SD1_D0_PERIPHERAL                                  USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_D0_SIGNAL                                  usdhc_data   /*!< USDHC1 signal: usdhc_data */
#define BOARD_INITPINS_SD1_D0_CHANNEL                                         0U   /*!< USDHC1 usdhc_data channel: 0 */

/* GPIO_SD_B0_03 (coord K1), SD1_D1/J24[5]/SPI_MISO */
#define BOARD_INITPINS_SD1_D1_PERIPHERAL                                  USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_D1_SIGNAL                                  usdhc_data   /*!< USDHC1 signal: usdhc_data */
#define BOARD_INITPINS_SD1_D1_CHANNEL                                         1U   /*!< USDHC1 usdhc_data channel: 1 */

/* GPIO_SD_B0_04 (coord H2), SD1_D2 */
#define BOARD_INITPINS_SD1_D2_PERIPHERAL                                  USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_D2_SIGNAL                                  usdhc_data   /*!< USDHC1 signal: usdhc_data */
#define BOARD_INITPINS_SD1_D2_CHANNEL                                         2U   /*!< USDHC1 usdhc_data channel: 2 */

/* GPIO_SD_B0_05 (coord J2), SD1_D3 */
#define BOARD_INITPINS_SD1_D3_PERIPHERAL                                  USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD1_D3_SIGNAL                                  usdhc_data   /*!< USDHC1 signal: usdhc_data */
#define BOARD_INITPINS_SD1_D3_CHANNEL                                         3U   /*!< USDHC1 usdhc_data channel: 3 */

/* GPIO_B1_14 (coord C14), SD0_VSELECT */
#define BOARD_INITPINS_SD0_VSELECT_PERIPHERAL                             USDHC1   /*!< Device name: USDHC1 */
#define BOARD_INITPINS_SD0_VSELECT_SIGNAL                          usdhc_vselect   /*!< USDHC1 signal: usdhc_vselect */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
