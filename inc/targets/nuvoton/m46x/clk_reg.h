/**************************************************************************//**
 * @file     clk_reg.h
 * @version  V3.00
 * @brief    CLK register definition header file
 *
 * @copyright SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2021 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __CLK_REG_H__
#define __CLK_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/** @addtogroup REGISTER Control Register

  @{

*/



/*---------------------- System Clock Controller -------------------------*/
/**
    @addtogroup CLK_CONST CLK Bit Field Definition
    Constant Definitions for CLK Controller
@{ */

#define CLK_PWRCTL_HXTEN_Pos             (0)                                               /*!< CLK_T::PWRCTL: HXTEN Position          */
#define CLK_PWRCTL_HXTEN_Msk             (0x1ul << CLK_PWRCTL_HXTEN_Pos)                   /*!< CLK_T::PWRCTL: HXTEN Mask              */

#define CLK_PWRCTL_LXTEN_Pos             (1)                                               /*!< CLK_T::PWRCTL: LXTEN Position          */
#define CLK_PWRCTL_LXTEN_Msk             (0x1ul << CLK_PWRCTL_LXTEN_Pos)                   /*!< CLK_T::PWRCTL: LXTEN Mask              */

#define CLK_PWRCTL_HIRCEN_Pos            (2)                                               /*!< CLK_T::PWRCTL: HIRCEN Position         */
#define CLK_PWRCTL_HIRCEN_Msk            (0x1ul << CLK_PWRCTL_HIRCEN_Pos)                  /*!< CLK_T::PWRCTL: HIRCEN Mask             */

#define CLK_PWRCTL_LIRCEN_Pos            (3)                                               /*!< CLK_T::PWRCTL: LIRCEN Position         */
#define CLK_PWRCTL_LIRCEN_Msk            (0x1ul << CLK_PWRCTL_LIRCEN_Pos)                  /*!< CLK_T::PWRCTL: LIRCEN Mask             */

#define CLK_PWRCTL_PDWKDLY_Pos           (4)                                               /*!< CLK_T::PWRCTL: PDWKDLY Position        */
#define CLK_PWRCTL_PDWKDLY_Msk           (0x1ul << CLK_PWRCTL_PDWKDLY_Pos)                 /*!< CLK_T::PWRCTL: PDWKDLY Mask            */

#define CLK_PWRCTL_PDWKIEN_Pos           (5)                                               /*!< CLK_T::PWRCTL: PDWKIEN Position        */
#define CLK_PWRCTL_PDWKIEN_Msk           (0x1ul << CLK_PWRCTL_PDWKIEN_Pos)                 /*!< CLK_T::PWRCTL: PDWKIEN Mask            */

#define CLK_PWRCTL_PDWKIF_Pos            (6)                                               /*!< CLK_T::PWRCTL: PDWKIF Position         */
#define CLK_PWRCTL_PDWKIF_Msk            (0x1ul << CLK_PWRCTL_PDWKIF_Pos)                  /*!< CLK_T::PWRCTL: PDWKIF Mask             */

#define CLK_PWRCTL_PDEN_Pos              (7)                                               /*!< CLK_T::PWRCTL: PDEN Position           */
#define CLK_PWRCTL_PDEN_Msk              (0x1ul << CLK_PWRCTL_PDEN_Pos)                    /*!< CLK_T::PWRCTL: PDEN Mask               */

#define CLK_PWRCTL_HXTGAIN_Pos           (10)                                              /*!< CLK_T::PWRCTL: HXTGAIN Position        */
#define CLK_PWRCTL_HXTGAIN_Msk           (0x3ul << CLK_PWRCTL_HXTGAIN_Pos)                 /*!< CLK_T::PWRCTL: HXTGAIN Mask            */

#define CLK_PWRCTL_HXTSELTYP_Pos         (12)                                              /*!< CLK_T::PWRCTL: HXTSELTYP Position      */
#define CLK_PWRCTL_HXTSELTYP_Msk         (0x1ul << CLK_PWRCTL_HXTSELTYP_Pos)               /*!< CLK_T::PWRCTL: HXTSELTYP Mask          */

#define CLK_PWRCTL_HIRCSTBS_Pos          (16)                                              /*!< CLK_T::PWRCTL: HIRCSTBS Position       */
#define CLK_PWRCTL_HIRCSTBS_Msk          (0x3ul << CLK_PWRCTL_HIRCSTBS_Pos)                /*!< CLK_T::PWRCTL: HIRCSTBS Mask           */

#define CLK_PWRCTL_HIRC48MEN_Pos         (18)                                              /*!< CLK_T::PWRCTL: HIRC48MEN Position      */
#define CLK_PWRCTL_HIRC48MEN_Msk         (0x1ul << CLK_PWRCTL_HIRC48MEN_Pos)               /*!< CLK_T::PWRCTL: HIRC48MEN Mask          */

#define CLK_PWRCTL_HXTMD_Pos             (31)                                              /*!< CLK_T::PWRCTL: HXTMD Position          */
#define CLK_PWRCTL_HXTMD_Msk             (0x1ul << CLK_PWRCTL_HXTMD_Pos)                   /*!< CLK_T::PWRCTL: HXTMD Mask              */

#define CLK_AHBCLK0_PDMA0CKEN_Pos        (1)                                               /*!< CLK_T::AHBCLK0: PDMA0CKEN Position     */
#define CLK_AHBCLK0_PDMA0CKEN_Msk        (0x1ul << CLK_AHBCLK0_PDMA0CKEN_Pos)              /*!< CLK_T::AHBCLK0: PDMA0CKEN Mask         */

#define CLK_AHBCLK0_ISPCKEN_Pos          (2)                                               /*!< CLK_T::AHBCLK0: ISPCKEN Position       */
#define CLK_AHBCLK0_ISPCKEN_Msk          (0x1ul << CLK_AHBCLK0_ISPCKEN_Pos)                /*!< CLK_T::AHBCLK0: ISPCKEN Mask           */

#define CLK_AHBCLK0_EBICKEN_Pos          (3)                                               /*!< CLK_T::AHBCLK0: EBICKEN Position       */
#define CLK_AHBCLK0_EBICKEN_Msk          (0x1ul << CLK_AHBCLK0_EBICKEN_Pos)                /*!< CLK_T::AHBCLK0: EBICKEN Mask           */

#define CLK_AHBCLK0_STCKEN_Pos           (4)                                               /*!< CLK_T::AHBCLK0: STCKEN Position        */
#define CLK_AHBCLK0_STCKEN_Msk           (0x1ul << CLK_AHBCLK0_STCKEN_Pos)                 /*!< CLK_T::AHBCLK0: STCKEN Mask            */

#define CLK_AHBCLK0_EMAC0CKEN_Pos        (5)                                               /*!< CLK_T::AHBCLK0: EMAC0CKEN Position     */
#define CLK_AHBCLK0_EMAC0CKEN_Msk        (0x1ul << CLK_AHBCLK0_EMAC0CKEN_Pos)              /*!< CLK_T::AHBCLK0: EMAC0CKEN Mask         */

#define CLK_AHBCLK0_SDH0CKEN_Pos         (6)                                               /*!< CLK_T::AHBCLK0: SDH0CKEN Position      */
#define CLK_AHBCLK0_SDH0CKEN_Msk         (0x1ul << CLK_AHBCLK0_SDH0CKEN_Pos)               /*!< CLK_T::AHBCLK0: SDH0CKEN Mask          */

#define CLK_AHBCLK0_CRCCKEN_Pos          (7)                                               /*!< CLK_T::AHBCLK0: CRCCKEN Position       */
#define CLK_AHBCLK0_CRCCKEN_Msk          (0x1ul << CLK_AHBCLK0_CRCCKEN_Pos)                /*!< CLK_T::AHBCLK0: CRCCKEN Mask           */

#define CLK_AHBCLK0_CCAPCKEN_Pos         (8)                                               /*!< CLK_T::AHBCLK0: CCAPCKEN Position      */
#define CLK_AHBCLK0_CCAPCKEN_Msk         (0x1ul << CLK_AHBCLK0_CCAPCKEN_Pos)               /*!< CLK_T::AHBCLK0: CCAPCKEN Mask          */

#define CLK_AHBCLK0_SENCKEN_Pos          (9)                                               /*!< CLK_T::AHBCLK0: SENCKEN Position       */
#define CLK_AHBCLK0_SENCKEN_Msk          (0x1ul << CLK_AHBCLK0_SENCKEN_Pos)                /*!< CLK_T::AHBCLK0: SENCKEN Mask           */

#define CLK_AHBCLK0_HSUSBDCKEN_Pos       (10)                                              /*!< CLK_T::AHBCLK0: HSUSBDCKEN Position    */
#define CLK_AHBCLK0_HSUSBDCKEN_Msk       (0x1ul << CLK_AHBCLK0_HSUSBDCKEN_Pos)             /*!< CLK_T::AHBCLK0: HSUSBDCKEN Mask        */

#define CLK_AHBCLK0_HBICKEN_Pos          (11)                                              /*!< CLK_T::AHBCLK0: HBICKEN Position       */
#define CLK_AHBCLK0_HBICKEN_Msk          (0x1ul << CLK_AHBCLK0_HBICKEN_Pos)                /*!< CLK_T::AHBCLK0: HBICKEN Mask           */

#define CLK_AHBCLK0_CRPTCKEN_Pos         (12)                                              /*!< CLK_T::AHBCLK0: CRPTCKEN Position      */
#define CLK_AHBCLK0_CRPTCKEN_Msk         (0x1ul << CLK_AHBCLK0_CRPTCKEN_Pos)               /*!< CLK_T::AHBCLK0: CRPTCKEN Mask          */

#define CLK_AHBCLK0_KSCKEN_Pos           (13)                                              /*!< CLK_T::AHBCLK0: KSCKEN Position        */
#define CLK_AHBCLK0_KSCKEN_Msk           (0x1ul << CLK_AHBCLK0_KSCKEN_Pos)                 /*!< CLK_T::AHBCLK0: KSCKEN Mask            */

#define CLK_AHBCLK0_SPIMCKEN_Pos         (14)                                              /*!< CLK_T::AHBCLK0: SPIMCKEN Position      */
#define CLK_AHBCLK0_SPIMCKEN_Msk         (0x1ul << CLK_AHBCLK0_SPIMCKEN_Pos)               /*!< CLK_T::AHBCLK0: SPIMCKEN Mask          */

#define CLK_AHBCLK0_FMCIDLE_Pos          (15)                                              /*!< CLK_T::AHBCLK0: FMCIDLE Position       */
#define CLK_AHBCLK0_FMCIDLE_Msk          (0x1ul << CLK_AHBCLK0_FMCIDLE_Pos)                /*!< CLK_T::AHBCLK0: FMCIDLE Mask           */

#define CLK_AHBCLK0_USBHCKEN_Pos         (16)                                              /*!< CLK_T::AHBCLK0: USBHCKEN Position      */
#define CLK_AHBCLK0_USBHCKEN_Msk         (0x1ul << CLK_AHBCLK0_USBHCKEN_Pos)               /*!< CLK_T::AHBCLK0: USBHCKEN Mask          */

#define CLK_AHBCLK0_SDH1CKEN_Pos         (17)                                              /*!< CLK_T::AHBCLK0: SDH1CKEN Position      */
#define CLK_AHBCLK0_SDH1CKEN_Msk         (0x1ul << CLK_AHBCLK0_SDH1CKEN_Pos)               /*!< CLK_T::AHBCLK0: SDH1CKEN Mask          */

#define CLK_AHBCLK0_PDMA1CKEN_Pos        (18)                                              /*!< CLK_T::AHBCLK0: PDMA1CKEN Position     */
#define CLK_AHBCLK0_PDMA1CKEN_Msk        (0x1ul << CLK_AHBCLK0_PDMA1CKEN_Pos)              /*!< CLK_T::AHBCLK0: PDMA1CKEN Mask         */

#define CLK_AHBCLK0_TRACECKEN_Pos        (19)                                              /*!< CLK_T::AHBCLK0: TRACECKEN Position     */
#define CLK_AHBCLK0_TRACECKEN_Msk        (0x1ul << CLK_AHBCLK0_TRACECKEN_Pos)              /*!< CLK_T::AHBCLK0: TRACECKEN Mask         */

#define CLK_AHBCLK0_GPACKEN_Pos          (24)                                              /*!< CLK_T::AHBCLK0: GPACKEN Position       */
#define CLK_AHBCLK0_GPACKEN_Msk          (0x1ul << CLK_AHBCLK0_GPACKEN_Pos)                /*!< CLK_T::AHBCLK0: GPACKEN Mask           */

#define CLK_AHBCLK0_GPBCKEN_Pos          (25)                                              /*!< CLK_T::AHBCLK0: GPBCKEN Position       */
#define CLK_AHBCLK0_GPBCKEN_Msk          (0x1ul << CLK_AHBCLK0_GPBCKEN_Pos)                /*!< CLK_T::AHBCLK0: GPBCKEN Mask           */

#define CLK_AHBCLK0_GPCCKEN_Pos          (26)                                              /*!< CLK_T::AHBCLK0: GPCCKEN Position       */
#define CLK_AHBCLK0_GPCCKEN_Msk          (0x1ul << CLK_AHBCLK0_GPCCKEN_Pos)                /*!< CLK_T::AHBCLK0: GPCCKEN Mask           */

#define CLK_AHBCLK0_GPDCKEN_Pos          (27)                                              /*!< CLK_T::AHBCLK0: GPDCKEN Position       */
#define CLK_AHBCLK0_GPDCKEN_Msk          (0x1ul << CLK_AHBCLK0_GPDCKEN_Pos)                /*!< CLK_T::AHBCLK0: GPDCKEN Mask           */

#define CLK_AHBCLK0_GPECKEN_Pos          (28)                                              /*!< CLK_T::AHBCLK0: GPECKEN Position       */
#define CLK_AHBCLK0_GPECKEN_Msk          (0x1ul << CLK_AHBCLK0_GPECKEN_Pos)                /*!< CLK_T::AHBCLK0: GPECKEN Mask           */

#define CLK_AHBCLK0_GPFCKEN_Pos          (29)                                              /*!< CLK_T::AHBCLK0: GPFCKEN Position       */
#define CLK_AHBCLK0_GPFCKEN_Msk          (0x1ul << CLK_AHBCLK0_GPFCKEN_Pos)                /*!< CLK_T::AHBCLK0: GPFCKEN Mask           */

#define CLK_AHBCLK0_GPGCKEN_Pos          (30)                                              /*!< CLK_T::AHBCLK0: GPGCKEN Position       */
#define CLK_AHBCLK0_GPGCKEN_Msk          (0x1ul << CLK_AHBCLK0_GPGCKEN_Pos)                /*!< CLK_T::AHBCLK0: GPGCKEN Mask           */

#define CLK_AHBCLK0_GPHCKEN_Pos          (31)                                              /*!< CLK_T::AHBCLK0: GPHCKEN Position       */
#define CLK_AHBCLK0_GPHCKEN_Msk          (0x1ul << CLK_AHBCLK0_GPHCKEN_Pos)                /*!< CLK_T::AHBCLK0: GPHCKEN Mask           */

#define CLK_APBCLK0_WDTCKEN_Pos          (0)                                               /*!< CLK_T::APBCLK0: WDTCKEN Position       */
#define CLK_APBCLK0_WDTCKEN_Msk          (0x1ul << CLK_APBCLK0_WDTCKEN_Pos)                /*!< CLK_T::APBCLK0: WDTCKEN Mask           */

#define CLK_APBCLK0_RTCCKEN_Pos          (1)                                               /*!< CLK_T::APBCLK0: RTCCKEN Position       */
#define CLK_APBCLK0_RTCCKEN_Msk          (0x1ul << CLK_APBCLK0_RTCCKEN_Pos)                /*!< CLK_T::APBCLK0: RTCCKEN Mask           */

#define CLK_APBCLK0_TMR0CKEN_Pos         (2)                                               /*!< CLK_T::APBCLK0: TMR0CKEN Position      */
#define CLK_APBCLK0_TMR0CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR0CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR0CKEN Mask          */

#define CLK_APBCLK0_TMR1CKEN_Pos         (3)                                               /*!< CLK_T::APBCLK0: TMR1CKEN Position      */
#define CLK_APBCLK0_TMR1CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR1CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR1CKEN Mask          */

#define CLK_APBCLK0_TMR2CKEN_Pos         (4)                                               /*!< CLK_T::APBCLK0: TMR2CKEN Position      */
#define CLK_APBCLK0_TMR2CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR2CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR2CKEN Mask          */

#define CLK_APBCLK0_TMR3CKEN_Pos         (5)                                               /*!< CLK_T::APBCLK0: TMR3CKEN Position      */
#define CLK_APBCLK0_TMR3CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR3CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR3CKEN Mask          */

#define CLK_APBCLK0_CLKOCKEN_Pos         (6)                                               /*!< CLK_T::APBCLK0: CLKOCKEN Position      */
#define CLK_APBCLK0_CLKOCKEN_Msk         (0x1ul << CLK_APBCLK0_CLKOCKEN_Pos)               /*!< CLK_T::APBCLK0: CLKOCKEN Mask          */

#define CLK_APBCLK0_ACMP01CKEN_Pos       (7)                                               /*!< CLK_T::APBCLK0: ACMP01CKEN Position    */
#define CLK_APBCLK0_ACMP01CKEN_Msk       (0x1ul << CLK_APBCLK0_ACMP01CKEN_Pos)             /*!< CLK_T::APBCLK0: ACMP01CKEN Mask        */

#define CLK_APBCLK0_I2C0CKEN_Pos         (8)                                               /*!< CLK_T::APBCLK0: I2C0CKEN Position      */
#define CLK_APBCLK0_I2C0CKEN_Msk         (0x1ul << CLK_APBCLK0_I2C0CKEN_Pos)               /*!< CLK_T::APBCLK0: I2C0CKEN Mask          */

#define CLK_APBCLK0_I2C1CKEN_Pos         (9)                                               /*!< CLK_T::APBCLK0: I2C1CKEN Position      */
#define CLK_APBCLK0_I2C1CKEN_Msk         (0x1ul << CLK_APBCLK0_I2C1CKEN_Pos)               /*!< CLK_T::APBCLK0: I2C1CKEN Mask          */

#define CLK_APBCLK0_I2C2CKEN_Pos         (10)                                              /*!< CLK_T::APBCLK0: I2C2CKEN Position      */
#define CLK_APBCLK0_I2C2CKEN_Msk         (0x1ul << CLK_APBCLK0_I2C2CKEN_Pos)               /*!< CLK_T::APBCLK0: I2C2CKEN Mask          */

#define CLK_APBCLK0_I2C3CKEN_Pos         (11)                                              /*!< CLK_T::APBCLK0: I2C3CKEN Position      */
#define CLK_APBCLK0_I2C3CKEN_Msk         (0x1ul << CLK_APBCLK0_I2C3CKEN_Pos)               /*!< CLK_T::APBCLK0: I2C3CKEN Mask          */

#define CLK_APBCLK0_QSPI0CKEN_Pos        (12)                                              /*!< CLK_T::APBCLK0: QSPI0CKEN Position     */
#define CLK_APBCLK0_QSPI0CKEN_Msk        (0x1ul << CLK_APBCLK0_QSPI0CKEN_Pos)              /*!< CLK_T::APBCLK0: QSPI0CKEN Mask         */

#define CLK_APBCLK0_SPI0CKEN_Pos         (13)                                              /*!< CLK_T::APBCLK0: SPI0CKEN Position      */
#define CLK_APBCLK0_SPI0CKEN_Msk         (0x1ul << CLK_APBCLK0_SPI0CKEN_Pos)               /*!< CLK_T::APBCLK0: SPI0CKEN Mask          */

#define CLK_APBCLK0_SPI1CKEN_Pos         (14)                                              /*!< CLK_T::APBCLK0: SPI1CKEN Position      */
#define CLK_APBCLK0_SPI1CKEN_Msk         (0x1ul << CLK_APBCLK0_SPI1CKEN_Pos)               /*!< CLK_T::APBCLK0: SPI1CKEN Mask          */

#define CLK_APBCLK0_SPI2CKEN_Pos         (15)                                              /*!< CLK_T::APBCLK0: SPI2CKEN Position      */
#define CLK_APBCLK0_SPI2CKEN_Msk         (0x1ul << CLK_APBCLK0_SPI2CKEN_Pos)               /*!< CLK_T::APBCLK0: SPI2CKEN Mask          */

#define CLK_APBCLK0_UART0CKEN_Pos        (16)                                              /*!< CLK_T::APBCLK0: UART0CKEN Position     */
#define CLK_APBCLK0_UART0CKEN_Msk        (0x1ul << CLK_APBCLK0_UART0CKEN_Pos)              /*!< CLK_T::APBCLK0: UART0CKEN Mask         */

#define CLK_APBCLK0_UART1CKEN_Pos        (17)                                              /*!< CLK_T::APBCLK0: UART1CKEN Position     */
#define CLK_APBCLK0_UART1CKEN_Msk        (0x1ul << CLK_APBCLK0_UART1CKEN_Pos)              /*!< CLK_T::APBCLK0: UART1CKEN Mask         */

#define CLK_APBCLK0_UART2CKEN_Pos        (18)                                              /*!< CLK_T::APBCLK0: UART2CKEN Position     */
#define CLK_APBCLK0_UART2CKEN_Msk        (0x1ul << CLK_APBCLK0_UART2CKEN_Pos)              /*!< CLK_T::APBCLK0: UART2CKEN Mask         */

#define CLK_APBCLK0_UART3CKEN_Pos        (19)                                              /*!< CLK_T::APBCLK0: UART3CKEN Position     */
#define CLK_APBCLK0_UART3CKEN_Msk        (0x1ul << CLK_APBCLK0_UART3CKEN_Pos)              /*!< CLK_T::APBCLK0: UART3CKEN Mask         */

#define CLK_APBCLK0_UART4CKEN_Pos        (20)                                              /*!< CLK_T::APBCLK0: UART4CKEN Position     */
#define CLK_APBCLK0_UART4CKEN_Msk        (0x1ul << CLK_APBCLK0_UART4CKEN_Pos)              /*!< CLK_T::APBCLK0: UART4CKEN Mask         */

#define CLK_APBCLK0_UART5CKEN_Pos        (21)                                              /*!< CLK_T::APBCLK0: UART5CKEN Position     */
#define CLK_APBCLK0_UART5CKEN_Msk        (0x1ul << CLK_APBCLK0_UART5CKEN_Pos)              /*!< CLK_T::APBCLK0: UART5CKEN Mask         */

#define CLK_APBCLK0_UART6CKEN_Pos        (22)                                              /*!< CLK_T::APBCLK0: UART6CKEN Position     */
#define CLK_APBCLK0_UART6CKEN_Msk        (0x1ul << CLK_APBCLK0_UART6CKEN_Pos)              /*!< CLK_T::APBCLK0: UART6CKEN Mask         */

#define CLK_APBCLK0_UART7CKEN_Pos        (23)                                              /*!< CLK_T::APBCLK0: UART7CKEN Position     */
#define CLK_APBCLK0_UART7CKEN_Msk        (0x1ul << CLK_APBCLK0_UART7CKEN_Pos)              /*!< CLK_T::APBCLK0: UART7CKEN Mask         */

#define CLK_APBCLK0_OTGCKEN_Pos          (26)                                              /*!< CLK_T::APBCLK0: OTGCKEN Position       */
#define CLK_APBCLK0_OTGCKEN_Msk          (0x1ul << CLK_APBCLK0_OTGCKEN_Pos)                /*!< CLK_T::APBCLK0: OTGCKEN Mask           */

#define CLK_APBCLK0_USBDCKEN_Pos         (27)                                              /*!< CLK_T::APBCLK0: USBDCKEN Position      */
#define CLK_APBCLK0_USBDCKEN_Msk         (0x1ul << CLK_APBCLK0_USBDCKEN_Pos)               /*!< CLK_T::APBCLK0: USBDCKEN Mask          */

#define CLK_APBCLK0_EADC0CKEN_Pos        (28)                                              /*!< CLK_T::APBCLK0: EADC0CKEN Position     */
#define CLK_APBCLK0_EADC0CKEN_Msk        (0x1ul << CLK_APBCLK0_EADC0CKEN_Pos)              /*!< CLK_T::APBCLK0: EADC0CKEN Mask         */

#define CLK_APBCLK0_I2S0CKEN_Pos         (29)                                              /*!< CLK_T::APBCLK0: I2S0CKEN Position      */
#define CLK_APBCLK0_I2S0CKEN_Msk         (0x1ul << CLK_APBCLK0_I2S0CKEN_Pos)               /*!< CLK_T::APBCLK0: I2S0CKEN Mask          */

#define CLK_APBCLK0_HSOTGCKEN_Pos        (30)                                              /*!< CLK_T::APBCLK0: HSOTGCKEN Position     */
#define CLK_APBCLK0_HSOTGCKEN_Msk        (0x1ul << CLK_APBCLK0_HSOTGCKEN_Pos)              /*!< CLK_T::APBCLK0: HSOTGCKEN Mask         */

#define CLK_APBCLK1_SC0CKEN_Pos          (0)                                               /*!< CLK_T::APBCLK1: SC0CKEN Position       */
#define CLK_APBCLK1_SC0CKEN_Msk          (0x1ul << CLK_APBCLK1_SC0CKEN_Pos)                /*!< CLK_T::APBCLK1: SC0CKEN Mask           */

#define CLK_APBCLK1_SC1CKEN_Pos          (1)                                               /*!< CLK_T::APBCLK1: SC1CKEN Position       */
#define CLK_APBCLK1_SC1CKEN_Msk          (0x1ul << CLK_APBCLK1_SC1CKEN_Pos)                /*!< CLK_T::APBCLK1: SC1CKEN Mask           */

#define CLK_APBCLK1_SC2CKEN_Pos          (2)                                               /*!< CLK_T::APBCLK1: SC2CKEN Position       */
#define CLK_APBCLK1_SC2CKEN_Msk          (0x1ul << CLK_APBCLK1_SC2CKEN_Pos)                /*!< CLK_T::APBCLK1: SC2CKEN Mask           */

#define CLK_APBCLK1_I2C4CKEN_Pos         (3)                                               /*!< CLK_T::APBCLK1: I2C4CKEN Position      */
#define CLK_APBCLK1_I2C4CKEN_Msk         (0x1ul << CLK_APBCLK1_I2C4CKEN_Pos)               /*!< CLK_T::APBCLK1: I2C4CKEN Mask          */

#define CLK_APBCLK1_QSPI1CKEN_Pos        (4)                                               /*!< CLK_T::APBCLK1: QSPI1CKEN Position     */
#define CLK_APBCLK1_QSPI1CKEN_Msk        (0x1ul << CLK_APBCLK1_QSPI1CKEN_Pos)              /*!< CLK_T::APBCLK1: QSPI1CKEN Mask         */

#define CLK_APBCLK1_SPI3CKEN_Pos         (6)                                               /*!< CLK_T::APBCLK1: SPI3CKEN Position      */
#define CLK_APBCLK1_SPI3CKEN_Msk         (0x1ul << CLK_APBCLK1_SPI3CKEN_Pos)               /*!< CLK_T::APBCLK1: SPI3CKEN Mask          */

#define CLK_APBCLK1_SPI4CKEN_Pos         (7)                                               /*!< CLK_T::APBCLK1: SPI4CKEN Position      */
#define CLK_APBCLK1_SPI4CKEN_Msk         (0x1ul << CLK_APBCLK1_SPI4CKEN_Pos)               /*!< CLK_T::APBCLK1: SPI4CKEN Mask          */

#define CLK_APBCLK1_USCI0CKEN_Pos        (8)                                               /*!< CLK_T::APBCLK1: USCI0CKEN Position     */
#define CLK_APBCLK1_USCI0CKEN_Msk        (0x1ul << CLK_APBCLK1_USCI0CKEN_Pos)              /*!< CLK_T::APBCLK1: USCI0CKEN Mask         */

#define CLK_APBCLK1_PSIOCKEN_Pos         (10)                                              /*!< CLK_T::APBCLK1: PSIOCKEN Position      */
#define CLK_APBCLK1_PSIOCKEN_Msk         (0x1ul << CLK_APBCLK1_PSIOCKEN_Pos)               /*!< CLK_T::APBCLK1: PSIOCKEN Mask          */

#define CLK_APBCLK1_DACCKEN_Pos          (12)                                              /*!< CLK_T::APBCLK1: DACCKEN Position       */
#define CLK_APBCLK1_DACCKEN_Msk          (0x1ul << CLK_APBCLK1_DACCKEN_Pos)                /*!< CLK_T::APBCLK1: DACCKEN Mask           */

#define CLK_APBCLK1_ECAP2CKEN_Pos        (13)                                              /*!< CLK_T::APBCLK1: ECAP2CKEN Position     */
#define CLK_APBCLK1_ECAP2CKEN_Msk        (0x1ul << CLK_APBCLK1_ECAP2CKEN_Pos)              /*!< CLK_T::APBCLK1: ECAP2CKEN Mask         */

#define CLK_APBCLK1_ECAP3CKEN_Pos        (14)                                              /*!< CLK_T::APBCLK1: ECAP3CKEN Position     */
#define CLK_APBCLK1_ECAP3CKEN_Msk        (0x1ul << CLK_APBCLK1_ECAP3CKEN_Pos)              /*!< CLK_T::APBCLK1: ECAP3CKEN Mask         */

#define CLK_APBCLK1_EPWM0CKEN_Pos        (16)                                              /*!< CLK_T::APBCLK1: EPWM0CKEN Position     */
#define CLK_APBCLK1_EPWM0CKEN_Msk        (0x1ul << CLK_APBCLK1_EPWM0CKEN_Pos)              /*!< CLK_T::APBCLK1: EPWM0CKEN Mask         */

#define CLK_APBCLK1_EPWM1CKEN_Pos        (17)                                              /*!< CLK_T::APBCLK1: EPWM1CKEN Position     */
#define CLK_APBCLK1_EPWM1CKEN_Msk        (0x1ul << CLK_APBCLK1_EPWM1CKEN_Pos)              /*!< CLK_T::APBCLK1: EPWM1CKEN Mask         */

#define CLK_APBCLK1_BPWM0CKEN_Pos        (18)                                              /*!< CLK_T::APBCLK1: BPWM0CKEN Position     */
#define CLK_APBCLK1_BPWM0CKEN_Msk        (0x1ul << CLK_APBCLK1_BPWM0CKEN_Pos)              /*!< CLK_T::APBCLK1: BPWM0CKEN Mask         */

#define CLK_APBCLK1_BPWM1CKEN_Pos        (19)                                              /*!< CLK_T::APBCLK1: BPWM1CKEN Position     */
#define CLK_APBCLK1_BPWM1CKEN_Msk        (0x1ul << CLK_APBCLK1_BPWM1CKEN_Pos)              /*!< CLK_T::APBCLK1: BPWM1CKEN Mask         */

#define CLK_APBCLK1_EQEI2CKEN_Pos        (20)                                              /*!< CLK_T::APBCLK1: EQEI2CKEN Position     */
#define CLK_APBCLK1_EQEI2CKEN_Msk        (0x1ul << CLK_APBCLK1_EQEI2CKEN_Pos)              /*!< CLK_T::APBCLK1: EQEI2CKEN Mask         */

#define CLK_APBCLK1_EQEI3CKEN_Pos        (21)                                              /*!< CLK_T::APBCLK1: EQEI3CKEN Position     */
#define CLK_APBCLK1_EQEI3CKEN_Msk        (0x1ul << CLK_APBCLK1_EQEI3CKEN_Pos)              /*!< CLK_T::APBCLK1: EQEI3CKEN Mask         */

#define CLK_APBCLK1_EQEI0CKEN_Pos        (22)                                              /*!< CLK_T::APBCLK1: EQEI0CKEN Position     */
#define CLK_APBCLK1_EQEI0CKEN_Msk        (0x1ul << CLK_APBCLK1_EQEI0CKEN_Pos)              /*!< CLK_T::APBCLK1: EQEI0CKEN Mask         */

#define CLK_APBCLK1_EQEI1CKEN_Pos        (23)                                              /*!< CLK_T::APBCLK1: EQEI1CKEN Position     */
#define CLK_APBCLK1_EQEI1CKEN_Msk        (0x1ul << CLK_APBCLK1_EQEI1CKEN_Pos)              /*!< CLK_T::APBCLK1: EQEI1CKEN Mask         */

#define CLK_APBCLK1_TRNGCKEN_Pos         (25)                                              /*!< CLK_T::APBCLK1: TRNGCKEN Position      */
#define CLK_APBCLK1_TRNGCKEN_Msk         (0x1ul << CLK_APBCLK1_TRNGCKEN_Pos)               /*!< CLK_T::APBCLK1: TRNGCKEN Mask          */

#define CLK_APBCLK1_ECAP0CKEN_Pos        (26)                                              /*!< CLK_T::APBCLK1: ECAP0CKEN Position     */
#define CLK_APBCLK1_ECAP0CKEN_Msk        (0x1ul << CLK_APBCLK1_ECAP0CKEN_Pos)              /*!< CLK_T::APBCLK1: ECAP0CKEN Mask         */

#define CLK_APBCLK1_ECAP1CKEN_Pos        (27)                                              /*!< CLK_T::APBCLK1: ECAP1CKEN Position     */
#define CLK_APBCLK1_ECAP1CKEN_Msk        (0x1ul << CLK_APBCLK1_ECAP1CKEN_Pos)              /*!< CLK_T::APBCLK1: ECAP1CKEN Mask         */

#define CLK_APBCLK1_I2S1CKEN_Pos         (29)                                              /*!< CLK_T::APBCLK1: I2S1CKEN Position      */
#define CLK_APBCLK1_I2S1CKEN_Msk         (0x1ul << CLK_APBCLK1_I2S1CKEN_Pos)               /*!< CLK_T::APBCLK1: I2S1CKEN Mask          */

#define CLK_APBCLK1_EADC1CKEN_Pos        (31)                                              /*!< CLK_T::APBCLK1: EADC1CKEN Position     */
#define CLK_APBCLK1_EADC1CKEN_Msk        (0x1ul << CLK_APBCLK1_EADC1CKEN_Pos)              /*!< CLK_T::APBCLK1: EADC1CKEN Mask         */

#define CLK_CLKSEL0_HCLKSEL_Pos          (0)                                               /*!< CLK_T::CLKSEL0: HCLKSEL Position       */
#define CLK_CLKSEL0_HCLKSEL_Msk          (0x7ul << CLK_CLKSEL0_HCLKSEL_Pos)                /*!< CLK_T::CLKSEL0: HCLKSEL Mask           */

#define CLK_CLKSEL0_STCLKSEL_Pos         (3)                                               /*!< CLK_T::CLKSEL0: STCLKSEL Position      */
#define CLK_CLKSEL0_STCLKSEL_Msk         (0x7ul << CLK_CLKSEL0_STCLKSEL_Pos)               /*!< CLK_T::CLKSEL0: STCLKSEL Mask          */

#define CLK_CLKSEL0_USBSEL_Pos           (8)                                               /*!< CLK_T::CLKSEL0: USBSEL Position        */
#define CLK_CLKSEL0_USBSEL_Msk           (0x1ul << CLK_CLKSEL0_USBSEL_Pos)                 /*!< CLK_T::CLKSEL0: USBSEL Mask            */

#define CLK_CLKSEL0_EADC0SEL_Pos         (10)                                              /*!< CLK_T::CLKSEL0: EADC0SEL Position      */
#define CLK_CLKSEL0_EADC0SEL_Msk         (0x3ul << CLK_CLKSEL0_EADC0SEL_Pos)               /*!< CLK_T::CLKSEL0: EADC0SEL Mask          */

#define CLK_CLKSEL0_EADC1SEL_Pos         (12)                                              /*!< CLK_T::CLKSEL0: EADC1SEL Position      */
#define CLK_CLKSEL0_EADC1SEL_Msk         (0x3ul << CLK_CLKSEL0_EADC1SEL_Pos)               /*!< CLK_T::CLKSEL0: EADC1SEL Mask          */

#define CLK_CLKSEL0_EADC2SEL_Pos         (14)                                              /*!< CLK_T::CLKSEL0: EADC2SEL Position      */
#define CLK_CLKSEL0_EADC2SEL_Msk         (0x3ul << CLK_CLKSEL0_EADC2SEL_Pos)               /*!< CLK_T::CLKSEL0: EADC2SEL Mask          */

#define CLK_CLKSEL0_CCAPSEL_Pos          (16)                                              /*!< CLK_T::CLKSEL0: CCAPSEL Position       */
#define CLK_CLKSEL0_CCAPSEL_Msk          (0x3ul << CLK_CLKSEL0_CCAPSEL_Pos)                /*!< CLK_T::CLKSEL0: CCAPSEL Mask           */

#define CLK_CLKSEL0_SDH0SEL_Pos          (20)                                              /*!< CLK_T::CLKSEL0: SDH0SEL Position       */
#define CLK_CLKSEL0_SDH0SEL_Msk          (0x3ul << CLK_CLKSEL0_SDH0SEL_Pos)                /*!< CLK_T::CLKSEL0: SDH0SEL Mask           */

#define CLK_CLKSEL0_SDH1SEL_Pos          (22)                                              /*!< CLK_T::CLKSEL0: SDH1SEL Position       */
#define CLK_CLKSEL0_SDH1SEL_Msk          (0x3ul << CLK_CLKSEL0_SDH1SEL_Pos)                /*!< CLK_T::CLKSEL0: SDH1SEL Mask           */

#define CLK_CLKSEL0_CANFD0SEL_Pos        (24)                                              /*!< CLK_T::CLKSEL0: CANFD0SEL Position     */
#define CLK_CLKSEL0_CANFD0SEL_Msk        (0x3ul << CLK_CLKSEL0_CANFD0SEL_Pos)              /*!< CLK_T::CLKSEL0: CANFD0SEL Mask         */

#define CLK_CLKSEL0_CANFD1SEL_Pos        (26)                                              /*!< CLK_T::CLKSEL0: CANFD1SEL Position     */
#define CLK_CLKSEL0_CANFD1SEL_Msk        (0x3ul << CLK_CLKSEL0_CANFD1SEL_Pos)              /*!< CLK_T::CLKSEL0: CANFD1SEL Mask         */

#define CLK_CLKSEL0_CANFD2SEL_Pos        (28)                                              /*!< CLK_T::CLKSEL0: CANFD2SEL Position     */
#define CLK_CLKSEL0_CANFD2SEL_Msk        (0x3ul << CLK_CLKSEL0_CANFD2SEL_Pos)              /*!< CLK_T::CLKSEL0: CANFD2SEL Mask         */

#define CLK_CLKSEL0_CANFD3SEL_Pos        (30)                                              /*!< CLK_T::CLKSEL0: CANFD3SEL Position     */
#define CLK_CLKSEL0_CANFD3SEL_Msk        (0x3ul << CLK_CLKSEL0_CANFD3SEL_Pos)              /*!< CLK_T::CLKSEL0: CANFD3SEL Mask         */

#define CLK_CLKSEL1_WDTSEL_Pos           (0)                                               /*!< CLK_T::CLKSEL1: WDTSEL Position        */
#define CLK_CLKSEL1_WDTSEL_Msk           (0x3ul << CLK_CLKSEL1_WDTSEL_Pos)                 /*!< CLK_T::CLKSEL1: WDTSEL Mask            */

#define CLK_CLKSEL1_CLKOSEL_Pos          (4)                                               /*!< CLK_T::CLKSEL1: CLKOSEL Position       */
#define CLK_CLKSEL1_CLKOSEL_Msk          (0x7ul << CLK_CLKSEL1_CLKOSEL_Pos)                /*!< CLK_T::CLKSEL1: CLKOSEL Mask           */

#define CLK_CLKSEL1_TMR0SEL_Pos          (8)                                               /*!< CLK_T::CLKSEL1: TMR0SEL Position       */
#define CLK_CLKSEL1_TMR0SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR0SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR0SEL Mask           */

#define CLK_CLKSEL1_TMR1SEL_Pos          (12)                                              /*!< CLK_T::CLKSEL1: TMR1SEL Position       */
#define CLK_CLKSEL1_TMR1SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR1SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR1SEL Mask           */

#define CLK_CLKSEL1_TMR2SEL_Pos          (16)                                              /*!< CLK_T::CLKSEL1: TMR2SEL Position       */
#define CLK_CLKSEL1_TMR2SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR2SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR2SEL Mask           */

#define CLK_CLKSEL1_TMR3SEL_Pos          (20)                                              /*!< CLK_T::CLKSEL1: TMR3SEL Position       */
#define CLK_CLKSEL1_TMR3SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR3SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR3SEL Mask           */

#define CLK_CLKSEL1_UART0SEL_Pos         (24)                                              /*!< CLK_T::CLKSEL1: UART0SEL Position      */
#define CLK_CLKSEL1_UART0SEL_Msk         (0x3ul << CLK_CLKSEL1_UART0SEL_Pos)               /*!< CLK_T::CLKSEL1: UART0SEL Mask          */

#define CLK_CLKSEL1_UART1SEL_Pos         (26)                                              /*!< CLK_T::CLKSEL1: UART1SEL Position      */
#define CLK_CLKSEL1_UART1SEL_Msk         (0x3ul << CLK_CLKSEL1_UART1SEL_Pos)               /*!< CLK_T::CLKSEL1: UART1SEL Mask          */

#define CLK_CLKSEL1_WWDTSEL_Pos          (30)                                              /*!< CLK_T::CLKSEL1: WWDTSEL Position       */
#define CLK_CLKSEL1_WWDTSEL_Msk          (0x3ul << CLK_CLKSEL1_WWDTSEL_Pos)                /*!< CLK_T::CLKSEL1: WWDTSEL Mask           */

#define CLK_CLKSEL2_EPWM0SEL_Pos         (0)                                               /*!< CLK_T::CLKSEL2: EPWM0SEL Position      */
#define CLK_CLKSEL2_EPWM0SEL_Msk         (0x1ul << CLK_CLKSEL2_EPWM0SEL_Pos)               /*!< CLK_T::CLKSEL2: EPWM0SEL Mask          */

#define CLK_CLKSEL2_EPWM1SEL_Pos         (1)                                               /*!< CLK_T::CLKSEL2: EPWM1SEL Position      */
#define CLK_CLKSEL2_EPWM1SEL_Msk         (0x1ul << CLK_CLKSEL2_EPWM1SEL_Pos)               /*!< CLK_T::CLKSEL2: EPWM1SEL Mask          */

#define CLK_CLKSEL2_QSPI0SEL_Pos         (2)                                               /*!< CLK_T::CLKSEL2: QSPI0SEL Position      */
#define CLK_CLKSEL2_QSPI0SEL_Msk         (0x3ul << CLK_CLKSEL2_QSPI0SEL_Pos)               /*!< CLK_T::CLKSEL2: QSPI0SEL Mask          */

#define CLK_CLKSEL2_SPI0SEL_Pos          (4)                                               /*!< CLK_T::CLKSEL2: SPI0SEL Position       */
#define CLK_CLKSEL2_SPI0SEL_Msk          (0x7ul << CLK_CLKSEL2_SPI0SEL_Pos)                /*!< CLK_T::CLKSEL2: SPI0SEL Mask           */

#define CLK_CLKSEL2_BPWM0SEL_Pos         (8)                                               /*!< CLK_T::CLKSEL2: BPWM0SEL Position      */
#define CLK_CLKSEL2_BPWM0SEL_Msk         (0x1ul << CLK_CLKSEL2_BPWM0SEL_Pos)               /*!< CLK_T::CLKSEL2: BPWM0SEL Mask          */

#define CLK_CLKSEL2_BPWM1SEL_Pos         (9)                                               /*!< CLK_T::CLKSEL2: BPWM1SEL Position      */
#define CLK_CLKSEL2_BPWM1SEL_Msk         (0x1ul << CLK_CLKSEL2_BPWM1SEL_Pos)               /*!< CLK_T::CLKSEL2: BPWM1SEL Mask          */

#define CLK_CLKSEL2_QSPI1SEL_Pos         (10)                                              /*!< CLK_T::CLKSEL2: QSPI1SEL Position      */
#define CLK_CLKSEL2_QSPI1SEL_Msk         (0x3ul << CLK_CLKSEL2_QSPI1SEL_Pos)               /*!< CLK_T::CLKSEL2: QSPI1SEL Mask          */

#define CLK_CLKSEL2_SPI1SEL_Pos          (12)                                              /*!< CLK_T::CLKSEL2: SPI1SEL Position       */
#define CLK_CLKSEL2_SPI1SEL_Msk          (0x7ul << CLK_CLKSEL2_SPI1SEL_Pos)                /*!< CLK_T::CLKSEL2: SPI1SEL Mask           */

#define CLK_CLKSEL2_I2S1SEL_Pos          (16)                                              /*!< CLK_T::CLKSEL2: I2S1SEL Position       */
#define CLK_CLKSEL2_I2S1SEL_Msk          (0x7ul << CLK_CLKSEL2_I2S1SEL_Pos)                /*!< CLK_T::CLKSEL2: I2S1SEL Mask           */

#define CLK_CLKSEL2_UART8SEL_Pos         (20)                                              /*!< CLK_T::CLKSEL2: UART8SEL Position      */
#define CLK_CLKSEL2_UART8SEL_Msk         (0x3ul << CLK_CLKSEL2_UART8SEL_Pos)               /*!< CLK_T::CLKSEL2: UART8SEL Mask          */

#define CLK_CLKSEL2_UART9SEL_Pos         (22)                                              /*!< CLK_T::CLKSEL2: UART9SEL Position      */
#define CLK_CLKSEL2_UART9SEL_Msk         (0x3ul << CLK_CLKSEL2_UART9SEL_Pos)               /*!< CLK_T::CLKSEL2: UART9SEL Mask          */

#define CLK_CLKSEL2_TRNGSEL_Pos          (27)                                              /*!< CLK_T::CLKSEL2: TRNGSEL Position       */
#define CLK_CLKSEL2_TRNGSEL_Msk          (0x1ul << CLK_CLKSEL2_TRNGSEL_Pos)                /*!< CLK_T::CLKSEL2: TRNGSEL Mask           */

#define CLK_CLKSEL2_PSIOSEL_Pos          (28)                                              /*!< CLK_T::CLKSEL2: PSIOSEL Position       */
#define CLK_CLKSEL2_PSIOSEL_Msk          (0x7ul << CLK_CLKSEL2_PSIOSEL_Pos)                /*!< CLK_T::CLKSEL2: PSIOSEL Mask           */

#define CLK_CLKSEL3_SC0SEL_Pos           (0)                                               /*!< CLK_T::CLKSEL3: SC0SEL Position        */
#define CLK_CLKSEL3_SC0SEL_Msk           (0x3ul << CLK_CLKSEL3_SC0SEL_Pos)                 /*!< CLK_T::CLKSEL3: SC0SEL Mask            */

#define CLK_CLKSEL3_SC1SEL_Pos           (2)                                               /*!< CLK_T::CLKSEL3: SC1SEL Position        */
#define CLK_CLKSEL3_SC1SEL_Msk           (0x3ul << CLK_CLKSEL3_SC1SEL_Pos)                 /*!< CLK_T::CLKSEL3: SC1SEL Mask            */

#define CLK_CLKSEL3_SC2SEL_Pos           (4)                                               /*!< CLK_T::CLKSEL3: SC2SEL Position        */
#define CLK_CLKSEL3_SC2SEL_Msk           (0x3ul << CLK_CLKSEL3_SC2SEL_Pos)                 /*!< CLK_T::CLKSEL3: SC2SEL Mask            */

#define CLK_CLKSEL3_KPISEL_Pos           (6)                                               /*!< CLK_T::CLKSEL3: KPISEL Position        */
#define CLK_CLKSEL3_KPISEL_Msk           (0x3ul << CLK_CLKSEL3_KPISEL_Pos)                 /*!< CLK_T::CLKSEL3: KPISEL Mask            */

#define CLK_CLKSEL3_SPI2SEL_Pos          (9)                                               /*!< CLK_T::CLKSEL3: SPI2SEL Position       */
#define CLK_CLKSEL3_SPI2SEL_Msk          (0x7ul << CLK_CLKSEL3_SPI2SEL_Pos)                /*!< CLK_T::CLKSEL3: SPI2SEL Mask           */

#define CLK_CLKSEL3_SPI3SEL_Pos          (12)                                              /*!< CLK_T::CLKSEL3: SPI3SEL Position       */
#define CLK_CLKSEL3_SPI3SEL_Msk          (0x7ul << CLK_CLKSEL3_SPI3SEL_Pos)                /*!< CLK_T::CLKSEL3: SPI3SEL Mask           */

#define CLK_CLKSEL3_I2S0SEL_Pos          (16)                                              /*!< CLK_T::CLKSEL3: I2S0SEL Position       */
#define CLK_CLKSEL3_I2S0SEL_Msk          (0x7ul << CLK_CLKSEL3_I2S0SEL_Pos)                /*!< CLK_T::CLKSEL3: I2S0SEL Mask           */

#define CLK_CLKSEL3_UART6SEL_Pos         (20)                                              /*!< CLK_T::CLKSEL3: UART6SEL Position      */
#define CLK_CLKSEL3_UART6SEL_Msk         (0x3ul << CLK_CLKSEL3_UART6SEL_Pos)               /*!< CLK_T::CLKSEL3: UART6SEL Mask          */

#define CLK_CLKSEL3_UART7SEL_Pos         (22)                                              /*!< CLK_T::CLKSEL3: UART7SEL Position      */
#define CLK_CLKSEL3_UART7SEL_Msk         (0x3ul << CLK_CLKSEL3_UART7SEL_Pos)               /*!< CLK_T::CLKSEL3: UART7SEL Mask          */

#define CLK_CLKSEL3_UART2SEL_Pos         (24)                                              /*!< CLK_T::CLKSEL3: UART2SEL Position      */
#define CLK_CLKSEL3_UART2SEL_Msk         (0x3ul << CLK_CLKSEL3_UART2SEL_Pos)               /*!< CLK_T::CLKSEL3: UART2SEL Mask          */

#define CLK_CLKSEL3_UART3SEL_Pos         (26)                                              /*!< CLK_T::CLKSEL3: UART3SEL Position      */
#define CLK_CLKSEL3_UART3SEL_Msk         (0x3ul << CLK_CLKSEL3_UART3SEL_Pos)               /*!< CLK_T::CLKSEL3: UART3SEL Mask          */

#define CLK_CLKSEL3_UART4SEL_Pos         (28)                                              /*!< CLK_T::CLKSEL3: UART4SEL Position      */
#define CLK_CLKSEL3_UART4SEL_Msk         (0x3ul << CLK_CLKSEL3_UART4SEL_Pos)               /*!< CLK_T::CLKSEL3: UART4SEL Mask          */

#define CLK_CLKSEL3_UART5SEL_Pos         (30)                                              /*!< CLK_T::CLKSEL3: UART5SEL Position      */
#define CLK_CLKSEL3_UART5SEL_Msk         (0x3ul << CLK_CLKSEL3_UART5SEL_Pos)               /*!< CLK_T::CLKSEL3: UART5SEL Mask          */

#define CLK_CLKDIV0_HCLKDIV_Pos          (0)                                               /*!< CLK_T::CLKDIV0: HCLKDIV Position       */
#define CLK_CLKDIV0_HCLKDIV_Msk          (0xful << CLK_CLKDIV0_HCLKDIV_Pos)                /*!< CLK_T::CLKDIV0: HCLKDIV Mask           */

#define CLK_CLKDIV0_USBDIV_Pos           (4)                                               /*!< CLK_T::CLKDIV0: USBDIV Position        */
#define CLK_CLKDIV0_USBDIV_Msk           (0xful << CLK_CLKDIV0_USBDIV_Pos)                 /*!< CLK_T::CLKDIV0: USBDIV Mask            */

#define CLK_CLKDIV0_UART0DIV_Pos         (8)                                               /*!< CLK_T::CLKDIV0: UART0DIV Position      */
#define CLK_CLKDIV0_UART0DIV_Msk         (0xful << CLK_CLKDIV0_UART0DIV_Pos)               /*!< CLK_T::CLKDIV0: UART0DIV Mask          */

#define CLK_CLKDIV0_UART1DIV_Pos         (12)                                              /*!< CLK_T::CLKDIV0: UART1DIV Position      */
#define CLK_CLKDIV0_UART1DIV_Msk         (0xful << CLK_CLKDIV0_UART1DIV_Pos)               /*!< CLK_T::CLKDIV0: UART1DIV Mask          */

#define CLK_CLKDIV0_EADC0DIV_Pos         (16)                                              /*!< CLK_T::CLKDIV0: EADC0DIV Position      */
#define CLK_CLKDIV0_EADC0DIV_Msk         (0xfful << CLK_CLKDIV0_EADC0DIV_Pos)              /*!< CLK_T::CLKDIV0: EADC0DIV Mask          */

#define CLK_CLKDIV0_SDH0DIV_Pos          (24)                                              /*!< CLK_T::CLKDIV0: SDH0DIV Position       */
#define CLK_CLKDIV0_SDH0DIV_Msk          (0xfful << CLK_CLKDIV0_SDH0DIV_Pos)               /*!< CLK_T::CLKDIV0: SDH0DIV Mask           */

#define CLK_CLKDIV1_SC0DIV_Pos           (0)                                               /*!< CLK_T::CLKDIV1: SC0DIV Position        */
#define CLK_CLKDIV1_SC0DIV_Msk           (0xfful << CLK_CLKDIV1_SC0DIV_Pos)                /*!< CLK_T::CLKDIV1: SC0DIV Mask            */

#define CLK_CLKDIV1_SC1DIV_Pos           (8)                                               /*!< CLK_T::CLKDIV1: SC1DIV Position        */
#define CLK_CLKDIV1_SC1DIV_Msk           (0xfful << CLK_CLKDIV1_SC1DIV_Pos)                /*!< CLK_T::CLKDIV1: SC1DIV Mask            */

#define CLK_CLKDIV1_SC2DIV_Pos           (16)                                              /*!< CLK_T::CLKDIV1: SC2DIV Position        */
#define CLK_CLKDIV1_SC2DIV_Msk           (0xfful << CLK_CLKDIV1_SC2DIV_Pos)                /*!< CLK_T::CLKDIV1: SC2DIV Mask            */

#define CLK_CLKDIV1_PSIODIV_Pos          (24)                                              /*!< CLK_T::CLKDIV1: PSIODIV Position       */
#define CLK_CLKDIV1_PSIODIV_Msk          (0xfful << CLK_CLKDIV1_PSIODIV_Pos)               /*!< CLK_T::CLKDIV1: PSIODIV Mask           */

#define CLK_CLKDIV2_I2S0DIV_Pos          (0)                                               /*!< CLK_T::CLKDIV2: I2S0DIV Position       */
#define CLK_CLKDIV2_I2S0DIV_Msk          (0xful << CLK_CLKDIV2_I2S0DIV_Pos)                /*!< CLK_T::CLKDIV2: I2S0DIV Mask           */

#define CLK_CLKDIV2_I2S1DIV_Pos          (4)                                               /*!< CLK_T::CLKDIV2: I2S1DIV Position       */
#define CLK_CLKDIV2_I2S1DIV_Msk          (0xful << CLK_CLKDIV2_I2S1DIV_Pos)                /*!< CLK_T::CLKDIV2: I2S1DIV Mask           */

#define CLK_CLKDIV2_KPIDIV_Pos           (8)                                               /*!< CLK_T::CLKDIV2: KPIDIV Position        */
#define CLK_CLKDIV2_KPIDIV_Msk           (0xfful << CLK_CLKDIV2_KPIDIV_Pos)                /*!< CLK_T::CLKDIV2: KPIDIV Mask            */

#define CLK_CLKDIV2_EADC1DIV_Pos         (24)                                              /*!< CLK_T::CLKDIV2: EADC1DIV Position      */
#define CLK_CLKDIV2_EADC1DIV_Msk         (0xfful << CLK_CLKDIV2_EADC1DIV_Pos)              /*!< CLK_T::CLKDIV2: EADC1DIV Mask          */

#define CLK_CLKDIV3_VSENSEDIV_Pos        (8)                                               /*!< CLK_T::CLKDIV3: VSENSEDIV Position     */
#define CLK_CLKDIV3_VSENSEDIV_Msk        (0xfful << CLK_CLKDIV3_VSENSEDIV_Pos)             /*!< CLK_T::CLKDIV3: VSENSEDIV Mask         */

#define CLK_CLKDIV3_SDH1DIV_Pos          (24)                                              /*!< CLK_T::CLKDIV3: SDH1DIV Position       */
#define CLK_CLKDIV3_SDH1DIV_Msk          (0xfful << CLK_CLKDIV3_SDH1DIV_Pos)               /*!< CLK_T::CLKDIV3: SDH1DIV Mask           */

#define CLK_CLKDIV4_UART2DIV_Pos         (0)                                               /*!< CLK_T::CLKDIV4: UART2DIV Position      */
#define CLK_CLKDIV4_UART2DIV_Msk         (0xful << CLK_CLKDIV4_UART2DIV_Pos)               /*!< CLK_T::CLKDIV4: UART2DIV Mask          */

#define CLK_CLKDIV4_UART3DIV_Pos         (4)                                               /*!< CLK_T::CLKDIV4: UART3DIV Position      */
#define CLK_CLKDIV4_UART3DIV_Msk         (0xful << CLK_CLKDIV4_UART3DIV_Pos)               /*!< CLK_T::CLKDIV4: UART3DIV Mask          */

#define CLK_CLKDIV4_UART4DIV_Pos         (8)                                               /*!< CLK_T::CLKDIV4: UART4DIV Position      */
#define CLK_CLKDIV4_UART4DIV_Msk         (0xful << CLK_CLKDIV4_UART4DIV_Pos)               /*!< CLK_T::CLKDIV4: UART4DIV Mask          */

#define CLK_CLKDIV4_UART5DIV_Pos         (12)                                              /*!< CLK_T::CLKDIV4: UART5DIV Position      */
#define CLK_CLKDIV4_UART5DIV_Msk         (0xful << CLK_CLKDIV4_UART5DIV_Pos)               /*!< CLK_T::CLKDIV4: UART5DIV Mask          */

#define CLK_CLKDIV4_UART6DIV_Pos         (16)                                              /*!< CLK_T::CLKDIV4: UART6DIV Position      */
#define CLK_CLKDIV4_UART6DIV_Msk         (0xful << CLK_CLKDIV4_UART6DIV_Pos)               /*!< CLK_T::CLKDIV4: UART6DIV Mask          */

#define CLK_CLKDIV4_UART7DIV_Pos         (20)                                              /*!< CLK_T::CLKDIV4: UART7DIV Position      */
#define CLK_CLKDIV4_UART7DIV_Msk         (0xful << CLK_CLKDIV4_UART7DIV_Pos)               /*!< CLK_T::CLKDIV4: UART7DIV Mask          */

#define CLK_PCLKDIV_APB0DIV_Pos          (0)                                               /*!< CLK_T::PCLKDIV: APB0DIV Position       */
#define CLK_PCLKDIV_APB0DIV_Msk          (0x7ul << CLK_PCLKDIV_APB0DIV_Pos)                /*!< CLK_T::PCLKDIV: APB0DIV Mask           */

#define CLK_PCLKDIV_APB1DIV_Pos          (4)                                               /*!< CLK_T::PCLKDIV: APB1DIV Position       */
#define CLK_PCLKDIV_APB1DIV_Msk          (0x7ul << CLK_PCLKDIV_APB1DIV_Pos)                /*!< CLK_T::PCLKDIV: APB1DIV Mask           */

#define CLK_APBCLK2_KPICKEN_Pos          (0)                                               /*!< CLK_T::APBCLK2: KPICKEN Position       */
#define CLK_APBCLK2_KPICKEN_Msk          (0x1ul << CLK_APBCLK2_KPICKEN_Pos)                /*!< CLK_T::APBCLK2: KPICKEN Mask           */

#define CLK_APBCLK2_EADC2CKEN_Pos        (6)                                               /*!< CLK_T::APBCLK2: EADC2CKEN Position     */
#define CLK_APBCLK2_EADC2CKEN_Msk        (0x1ul << CLK_APBCLK2_EADC2CKEN_Pos)              /*!< CLK_T::APBCLK2: EADC2CKEN Mask         */

#define CLK_APBCLK2_ACMP23CKEN_Pos       (7)                                               /*!< CLK_T::APBCLK2: ACMP23CKEN Position    */
#define CLK_APBCLK2_ACMP23CKEN_Msk       (0x1ul << CLK_APBCLK2_ACMP23CKEN_Pos)             /*!< CLK_T::APBCLK2: ACMP23CKEN Mask        */

#define CLK_APBCLK2_SPI5CKEN_Pos         (8)                                               /*!< CLK_T::APBCLK2: SPI5CKEN Position      */
#define CLK_APBCLK2_SPI5CKEN_Msk         (0x1ul << CLK_APBCLK2_SPI5CKEN_Pos)               /*!< CLK_T::APBCLK2: SPI5CKEN Mask          */

#define CLK_APBCLK2_SPI6CKEN_Pos         (9)                                               /*!< CLK_T::APBCLK2: SPI6CKEN Position      */
#define CLK_APBCLK2_SPI6CKEN_Msk         (0x1ul << CLK_APBCLK2_SPI6CKEN_Pos)               /*!< CLK_T::APBCLK2: SPI6CKEN Mask          */

#define CLK_APBCLK2_SPI7CKEN_Pos         (10)                                              /*!< CLK_T::APBCLK2: SPI7CKEN Position      */
#define CLK_APBCLK2_SPI7CKEN_Msk         (0x1ul << CLK_APBCLK2_SPI7CKEN_Pos)               /*!< CLK_T::APBCLK2: SPI7CKEN Mask          */

#define CLK_APBCLK2_SPI8CKEN_Pos         (11)                                              /*!< CLK_T::APBCLK2: SPI8CKEN Position      */
#define CLK_APBCLK2_SPI8CKEN_Msk         (0x1ul << CLK_APBCLK2_SPI8CKEN_Pos)               /*!< CLK_T::APBCLK2: SPI8CKEN Mask          */

#define CLK_APBCLK2_SPI9CKEN_Pos         (12)                                              /*!< CLK_T::APBCLK2: SPI9CKEN Position      */
#define CLK_APBCLK2_SPI9CKEN_Msk         (0x1ul << CLK_APBCLK2_SPI9CKEN_Pos)               /*!< CLK_T::APBCLK2: SPI9CKEN Mask          */

#define CLK_APBCLK2_SPI10CKEN_Pos        (13)                                              /*!< CLK_T::APBCLK2: SPI10CKEN Position     */
#define CLK_APBCLK2_SPI10CKEN_Msk        (0x1ul << CLK_APBCLK2_SPI10CKEN_Pos)              /*!< CLK_T::APBCLK2: SPI10CKEN Mask         */

#define CLK_APBCLK2_UART8CKEN_Pos        (16)                                              /*!< CLK_T::APBCLK2: UART8CKEN Position     */
#define CLK_APBCLK2_UART8CKEN_Msk        (0x1ul << CLK_APBCLK2_UART8CKEN_Pos)              /*!< CLK_T::APBCLK2: UART8CKEN Mask         */

#define CLK_APBCLK2_UART9CKEN_Pos        (17)                                              /*!< CLK_T::APBCLK2: UART9CKEN Position     */
#define CLK_APBCLK2_UART9CKEN_Msk        (0x1ul << CLK_APBCLK2_UART9CKEN_Pos)              /*!< CLK_T::APBCLK2: UART9CKEN Mask         */

#define CLK_CLKDIV5_CANFD0DIV_Pos        (0)                                               /*!< CLK_T::CLKDIV5: CANFD0DIV Position     */
#define CLK_CLKDIV5_CANFD0DIV_Msk        (0xful << CLK_CLKDIV5_CANFD0DIV_Pos)              /*!< CLK_T::CLKDIV5: CANFD0DIV Mask         */

#define CLK_CLKDIV5_CANFD1DIV_Pos        (4)                                               /*!< CLK_T::CLKDIV5: CANFD1DIV Position     */
#define CLK_CLKDIV5_CANFD1DIV_Msk        (0xful << CLK_CLKDIV5_CANFD1DIV_Pos)              /*!< CLK_T::CLKDIV5: CANFD1DIV Mask         */

#define CLK_CLKDIV5_CANFD2DIV_Pos        (8)                                               /*!< CLK_T::CLKDIV5: CANFD2DIV Position     */
#define CLK_CLKDIV5_CANFD2DIV_Msk        (0xful << CLK_CLKDIV5_CANFD2DIV_Pos)              /*!< CLK_T::CLKDIV5: CANFD2DIV Mask         */

#define CLK_CLKDIV5_CANFD3DIV_Pos        (12)                                              /*!< CLK_T::CLKDIV5: CANFD3DIV Position     */
#define CLK_CLKDIV5_CANFD3DIV_Msk        (0xful << CLK_CLKDIV5_CANFD3DIV_Pos)              /*!< CLK_T::CLKDIV5: CANFD3DIV Mask         */

#define CLK_CLKDIV5_UART8DIV_Pos         (16)                                              /*!< CLK_T::CLKDIV5: UART8DIV Position      */
#define CLK_CLKDIV5_UART8DIV_Msk         (0xful << CLK_CLKDIV5_UART8DIV_Pos)               /*!< CLK_T::CLKDIV5: UART8DIV Mask          */

#define CLK_CLKDIV5_UART9DIV_Pos         (20)                                              /*!< CLK_T::CLKDIV5: UART9DIV Position      */
#define CLK_CLKDIV5_UART9DIV_Msk         (0xful << CLK_CLKDIV5_UART9DIV_Pos)               /*!< CLK_T::CLKDIV5: UART9DIV Mask          */

#define CLK_CLKDIV5_EADC2DIV_Pos         (24)                                              /*!< CLK_T::CLKDIV5: EADC2DIV Position      */
#define CLK_CLKDIV5_EADC2DIV_Msk         (0xfful << CLK_CLKDIV5_EADC2DIV_Pos)              /*!< CLK_T::CLKDIV5: EADC2DIV Mask          */

#define CLK_PLLCTL_FBDIV_Pos             (0)                                               /*!< CLK_T::PLLCTL: FBDIV Position          */
#define CLK_PLLCTL_FBDIV_Msk             (0x1fful << CLK_PLLCTL_FBDIV_Pos)                 /*!< CLK_T::PLLCTL: FBDIV Mask              */

#define CLK_PLLCTL_INDIV_Pos             (9)                                               /*!< CLK_T::PLLCTL: INDIV Position          */
#define CLK_PLLCTL_INDIV_Msk             (0x1ful << CLK_PLLCTL_INDIV_Pos)                  /*!< CLK_T::PLLCTL: INDIV Mask              */

#define CLK_PLLCTL_OUTDIV_Pos            (14)                                              /*!< CLK_T::PLLCTL: OUTDIV Position         */
#define CLK_PLLCTL_OUTDIV_Msk            (0x3ul << CLK_PLLCTL_OUTDIV_Pos)                  /*!< CLK_T::PLLCTL: OUTDIV Mask             */

#define CLK_PLLCTL_PD_Pos                (16)                                              /*!< CLK_T::PLLCTL: PD Position             */
#define CLK_PLLCTL_PD_Msk                (0x1ul << CLK_PLLCTL_PD_Pos)                      /*!< CLK_T::PLLCTL: PD Mask                 */

#define CLK_PLLCTL_BP_Pos                (17)                                              /*!< CLK_T::PLLCTL: BP Position             */
#define CLK_PLLCTL_BP_Msk                (0x1ul << CLK_PLLCTL_BP_Pos)                      /*!< CLK_T::PLLCTL: BP Mask                 */

#define CLK_PLLCTL_OE_Pos                (18)                                              /*!< CLK_T::PLLCTL: OE Position             */
#define CLK_PLLCTL_OE_Msk                (0x1ul << CLK_PLLCTL_OE_Pos)                      /*!< CLK_T::PLLCTL: OE Mask                 */

#define CLK_PLLCTL_PLLSRC_Pos            (19)                                              /*!< CLK_T::PLLCTL: PLLSRC Position         */
#define CLK_PLLCTL_PLLSRC_Msk            (0x1ul << CLK_PLLCTL_PLLSRC_Pos)                  /*!< CLK_T::PLLCTL: PLLSRC Mask             */

#define CLK_PLLCTL_STBSEL_Pos            (23)                                              /*!< CLK_T::PLLCTL: STBSEL Position         */
#define CLK_PLLCTL_STBSEL_Msk            (0x1ul << CLK_PLLCTL_STBSEL_Pos)                  /*!< CLK_T::PLLCTL: STBSEL Mask             */

#define CLK_PLLFNCTL0_FBDIV_Pos          (0)                                               /*!< CLK_T::PLLFNCTL0: FBDIV Position       */
#define CLK_PLLFNCTL0_FBDIV_Msk          (0x1fful << CLK_PLLFNCTL0_FBDIV_Pos)              /*!< CLK_T::PLLFNCTL0: FBDIV Mask           */

#define CLK_PLLFNCTL0_INDIV_Pos          (9)                                               /*!< CLK_T::PLLFNCTL0: INDIV Position       */
#define CLK_PLLFNCTL0_INDIV_Msk          (0x1ful << CLK_PLLFNCTL0_INDIV_Pos)               /*!< CLK_T::PLLFNCTL0: INDIV Mask           */

#define CLK_PLLFNCTL0_OUTDIV_Pos         (14)                                              /*!< CLK_T::PLLFNCTL0: OUTDIV Position      */
#define CLK_PLLFNCTL0_OUTDIV_Msk         (0x3ul << CLK_PLLFNCTL0_OUTDIV_Pos)               /*!< CLK_T::PLLFNCTL0: OUTDIV Mask          */

#define CLK_PLLFNCTL0_FRDIV_Pos          (16)                                              /*!< CLK_T::PLLFNCTL0: FRDIV Position       */
#define CLK_PLLFNCTL0_FRDIV_Msk          (0xffful << CLK_PLLFNCTL0_FRDIV_Pos)              /*!< CLK_T::PLLFNCTL0: FRDIV Mask           */

#define CLK_PLLFNCTL1_STBSEL_Pos         (27)                                              /*!< CLK_T::PLLFNCTL1: STBSEL Position      */
#define CLK_PLLFNCTL1_STBSEL_Msk         (0x1ul << CLK_PLLFNCTL1_STBSEL_Pos)               /*!< CLK_T::PLLFNCTL1: STBSEL Mask          */

#define CLK_PLLFNCTL1_PD_Pos             (28)                                              /*!< CLK_T::PLLFNCTL1: PD Position          */
#define CLK_PLLFNCTL1_PD_Msk             (0x1ul << CLK_PLLFNCTL1_PD_Pos)                   /*!< CLK_T::PLLFNCTL1: PD Mask              */

#define CLK_PLLFNCTL1_BP_Pos             (29)                                              /*!< CLK_T::PLLFNCTL1: BP Position          */
#define CLK_PLLFNCTL1_BP_Msk             (0x1ul << CLK_PLLFNCTL1_BP_Pos)                   /*!< CLK_T::PLLFNCTL1: BP Mask              */

#define CLK_PLLFNCTL1_OE_Pos             (30)                                              /*!< CLK_T::PLLFNCTL1: OE Position          */
#define CLK_PLLFNCTL1_OE_Msk             (0x1ul << CLK_PLLFNCTL1_OE_Pos)                   /*!< CLK_T::PLLFNCTL1: OE Mask              */

#define CLK_PLLFNCTL1_PLLSRC_Pos         (31)                                              /*!< CLK_T::PLLFNCTL1: PLLSRC Position      */
#define CLK_PLLFNCTL1_PLLSRC_Msk         (0x1ul << CLK_PLLFNCTL1_PLLSRC_Pos)               /*!< CLK_T::PLLFNCTL1: PLLSRC Mask          */

#define CLK_STATUS_HXTSTB_Pos            (0)                                               /*!< CLK_T::STATUS: HXTSTB Position         */
#define CLK_STATUS_HXTSTB_Msk            (0x1ul << CLK_STATUS_HXTSTB_Pos)                  /*!< CLK_T::STATUS: HXTSTB Mask             */

#define CLK_STATUS_LXTSTB_Pos            (1)                                               /*!< CLK_T::STATUS: LXTSTB Position         */
#define CLK_STATUS_LXTSTB_Msk            (0x1ul << CLK_STATUS_LXTSTB_Pos)                  /*!< CLK_T::STATUS: LXTSTB Mask             */

#define CLK_STATUS_PLLSTB_Pos            (2)                                               /*!< CLK_T::STATUS: PLLSTB Position         */
#define CLK_STATUS_PLLSTB_Msk            (0x1ul << CLK_STATUS_PLLSTB_Pos)                  /*!< CLK_T::STATUS: PLLSTB Mask             */

#define CLK_STATUS_LIRCSTB_Pos           (3)                                               /*!< CLK_T::STATUS: LIRCSTB Position        */
#define CLK_STATUS_LIRCSTB_Msk           (0x1ul << CLK_STATUS_LIRCSTB_Pos)                 /*!< CLK_T::STATUS: LIRCSTB Mask            */

#define CLK_STATUS_HIRCSTB_Pos           (4)                                               /*!< CLK_T::STATUS: HIRCSTB Position        */
#define CLK_STATUS_HIRCSTB_Msk           (0x1ul << CLK_STATUS_HIRCSTB_Pos)                 /*!< CLK_T::STATUS: HIRCSTB Mask            */

#define CLK_STATUS_HIRC48MSTB_Pos        (6)                                               /*!< CLK_T::STATUS: HIRC48MSTB Position     */
#define CLK_STATUS_HIRC48MSTB_Msk        (0x1ul << CLK_STATUS_HIRC48MSTB_Pos)              /*!< CLK_T::STATUS: HIRC48MSTB Mask         */

#define CLK_STATUS_CLKSFAIL_Pos          (7)                                               /*!< CLK_T::STATUS: CLKSFAIL Position       */
#define CLK_STATUS_CLKSFAIL_Msk          (0x1ul << CLK_STATUS_CLKSFAIL_Pos)                /*!< CLK_T::STATUS: CLKSFAIL Mask           */

#define CLK_STATUS_PLLFNSTB_Pos          (10)                                              /*!< CLK_T::STATUS: PLLFNSTB Position       */
#define CLK_STATUS_PLLFNSTB_Msk          (0x1ul << CLK_STATUS_PLLFNSTB_Pos)                /*!< CLK_T::STATUS: PLLFNSTB Mask           */

#define CLK_AHBCLK1_CANFD0CKEN_Pos       (20)                                              /*!< CLK_T::AHBCLK1: CANFD0CKEN Position    */
#define CLK_AHBCLK1_CANFD0CKEN_Msk       (0x1ul << CLK_AHBCLK1_CANFD0CKEN_Pos)             /*!< CLK_T::AHBCLK1: CANFD0CKEN Mask        */

#define CLK_AHBCLK1_CANFD1CKEN_Pos       (21)                                              /*!< CLK_T::AHBCLK1: CANFD1CKEN Position    */
#define CLK_AHBCLK1_CANFD1CKEN_Msk       (0x1ul << CLK_AHBCLK1_CANFD1CKEN_Pos)             /*!< CLK_T::AHBCLK1: CANFD1CKEN Mask        */

#define CLK_AHBCLK1_CANFD2CKEN_Pos       (22)                                              /*!< CLK_T::AHBCLK1: CANFD2CKEN Position    */
#define CLK_AHBCLK1_CANFD2CKEN_Msk       (0x1ul << CLK_AHBCLK1_CANFD2CKEN_Pos)             /*!< CLK_T::AHBCLK1: CANFD2CKEN Mask        */

#define CLK_AHBCLK1_CANFD3CKEN_Pos       (23)                                              /*!< CLK_T::AHBCLK1: CANFD3CKEN Position    */
#define CLK_AHBCLK1_CANFD3CKEN_Msk       (0x1ul << CLK_AHBCLK1_CANFD3CKEN_Pos)             /*!< CLK_T::AHBCLK1: CANFD3CKEN Mask        */

#define CLK_AHBCLK1_GPICKEN_Pos          (24)                                              /*!< CLK_T::AHBCLK1: GPICKEN Position       */
#define CLK_AHBCLK1_GPICKEN_Msk          (0x1ul << CLK_AHBCLK1_GPICKEN_Pos)                /*!< CLK_T::AHBCLK1: GPICKEN Mask           */

#define CLK_AHBCLK1_GPJCKEN_Pos          (25)                                              /*!< CLK_T::AHBCLK1: GPJCKEN Position       */
#define CLK_AHBCLK1_GPJCKEN_Msk          (0x1ul << CLK_AHBCLK1_GPJCKEN_Pos)                /*!< CLK_T::AHBCLK1: GPJCKEN Mask           */

#define CLK_AHBCLK1_BMCCKEN_Pos          (28)                                              /*!< CLK_T::AHBCLK1: BMCCKEN Position       */
#define CLK_AHBCLK1_BMCCKEN_Msk          (0x1ul << CLK_AHBCLK1_BMCCKEN_Pos)                /*!< CLK_T::AHBCLK1: BMCCKEN Mask           */

#define CLK_CLKSEL4_SPI4SEL_Pos          (0)                                               /*!< CLK_T::CLKSEL4: SPI4SEL Position       */
#define CLK_CLKSEL4_SPI4SEL_Msk          (0x7ul << CLK_CLKSEL4_SPI4SEL_Pos)                /*!< CLK_T::CLKSEL4: SPI4SEL Mask           */

#define CLK_CLKSEL4_SPI5SEL_Pos          (4)                                               /*!< CLK_T::CLKSEL4: SPI5SEL Position       */
#define CLK_CLKSEL4_SPI5SEL_Msk          (0x7ul << CLK_CLKSEL4_SPI5SEL_Pos)                /*!< CLK_T::CLKSEL4: SPI5SEL Mask           */

#define CLK_CLKSEL4_SPI6SEL_Pos          (8)                                               /*!< CLK_T::CLKSEL4: SPI6SEL Position       */
#define CLK_CLKSEL4_SPI6SEL_Msk          (0x7ul << CLK_CLKSEL4_SPI6SEL_Pos)                /*!< CLK_T::CLKSEL4: SPI6SEL Mask           */

#define CLK_CLKSEL4_SPI7SEL_Pos          (12)                                              /*!< CLK_T::CLKSEL4: SPI7SEL Position       */
#define CLK_CLKSEL4_SPI7SEL_Msk          (0x7ul << CLK_CLKSEL4_SPI7SEL_Pos)                /*!< CLK_T::CLKSEL4: SPI7SEL Mask           */

#define CLK_CLKSEL4_SPI8SEL_Pos          (16)                                              /*!< CLK_T::CLKSEL4: SPI8SEL Position       */
#define CLK_CLKSEL4_SPI8SEL_Msk          (0x7ul << CLK_CLKSEL4_SPI8SEL_Pos)                /*!< CLK_T::CLKSEL4: SPI8SEL Mask           */

#define CLK_CLKSEL4_SPI9SEL_Pos          (20)                                              /*!< CLK_T::CLKSEL4: SPI9SEL Position       */
#define CLK_CLKSEL4_SPI9SEL_Msk          (0x7ul << CLK_CLKSEL4_SPI9SEL_Pos)                /*!< CLK_T::CLKSEL4: SPI9SEL Mask           */

#define CLK_CLKSEL4_SPI10SEL_Pos         (24)                                              /*!< CLK_T::CLKSEL4: SPI10SEL Position      */
#define CLK_CLKSEL4_SPI10SEL_Msk         (0x7ul << CLK_CLKSEL4_SPI10SEL_Pos)               /*!< CLK_T::CLKSEL4: SPI10SEL Mask          */

#define CLK_CLKOCTL_FREQSEL_Pos          (0)                                               /*!< CLK_T::CLKOCTL: FREQSEL Position       */
#define CLK_CLKOCTL_FREQSEL_Msk          (0xful << CLK_CLKOCTL_FREQSEL_Pos)                /*!< CLK_T::CLKOCTL: FREQSEL Mask           */

#define CLK_CLKOCTL_CLKOEN_Pos           (4)                                               /*!< CLK_T::CLKOCTL: CLKOEN Position        */
#define CLK_CLKOCTL_CLKOEN_Msk           (0x1ul << CLK_CLKOCTL_CLKOEN_Pos)                 /*!< CLK_T::CLKOCTL: CLKOEN Mask            */

#define CLK_CLKOCTL_DIV1EN_Pos           (5)                                               /*!< CLK_T::CLKOCTL: DIV1EN Position        */
#define CLK_CLKOCTL_DIV1EN_Msk           (0x1ul << CLK_CLKOCTL_DIV1EN_Pos)                 /*!< CLK_T::CLKOCTL: DIV1EN Mask            */

#define CLK_CLKOCTL_CLK1HZEN_Pos         (6)                                               /*!< CLK_T::CLKOCTL: CLK1HZEN Position      */
#define CLK_CLKOCTL_CLK1HZEN_Msk         (0x1ul << CLK_CLKOCTL_CLK1HZEN_Pos)               /*!< CLK_T::CLKOCTL: CLK1HZEN Mask          */

#define CLK_CLKDCTL_HXTFDEN_Pos          (4)                                               /*!< CLK_T::CLKDCTL: HXTFDEN Position       */
#define CLK_CLKDCTL_HXTFDEN_Msk          (0x1ul << CLK_CLKDCTL_HXTFDEN_Pos)                /*!< CLK_T::CLKDCTL: HXTFDEN Mask           */

#define CLK_CLKDCTL_HXTFIEN_Pos          (5)                                               /*!< CLK_T::CLKDCTL: HXTFIEN Position       */
#define CLK_CLKDCTL_HXTFIEN_Msk          (0x1ul << CLK_CLKDCTL_HXTFIEN_Pos)                /*!< CLK_T::CLKDCTL: HXTFIEN Mask           */

#define CLK_CLKDCTL_LXTFDEN_Pos          (12)                                              /*!< CLK_T::CLKDCTL: LXTFDEN Position       */
#define CLK_CLKDCTL_LXTFDEN_Msk          (0x1ul << CLK_CLKDCTL_LXTFDEN_Pos)                /*!< CLK_T::CLKDCTL: LXTFDEN Mask           */

#define CLK_CLKDCTL_LXTFIEN_Pos          (13)                                              /*!< CLK_T::CLKDCTL: LXTFIEN Position       */
#define CLK_CLKDCTL_LXTFIEN_Msk          (0x1ul << CLK_CLKDCTL_LXTFIEN_Pos)                /*!< CLK_T::CLKDCTL: LXTFIEN Mask           */

#define CLK_CLKDCTL_HXTFQDEN_Pos         (16)                                              /*!< CLK_T::CLKDCTL: HXTFQDEN Position      */
#define CLK_CLKDCTL_HXTFQDEN_Msk         (0x1ul << CLK_CLKDCTL_HXTFQDEN_Pos)               /*!< CLK_T::CLKDCTL: HXTFQDEN Mask          */

#define CLK_CLKDCTL_HXTFQIEN_Pos         (17)                                              /*!< CLK_T::CLKDCTL: HXTFQIEN Position      */
#define CLK_CLKDCTL_HXTFQIEN_Msk         (0x1ul << CLK_CLKDCTL_HXTFQIEN_Pos)               /*!< CLK_T::CLKDCTL: HXTFQIEN Mask          */

#define CLK_CLKDCTL_HXTFQASW_Pos         (18)                                              /*!< CLK_T::CLKDCTL: HXTFQASW Position      */
#define CLK_CLKDCTL_HXTFQASW_Msk         (0x1ul << CLK_CLKDCTL_HXTFQASW_Pos)               /*!< CLK_T::CLKDCTL: HXTFQASW Mask          */

#define CLK_CLKDSTS_HXTFIF_Pos           (0)                                               /*!< CLK_T::CLKDSTS: HXTFIF Position        */
#define CLK_CLKDSTS_HXTFIF_Msk           (0x1ul << CLK_CLKDSTS_HXTFIF_Pos)                 /*!< CLK_T::CLKDSTS: HXTFIF Mask            */

#define CLK_CLKDSTS_LXTFIF_Pos           (1)                                               /*!< CLK_T::CLKDSTS: LXTFIF Position        */
#define CLK_CLKDSTS_LXTFIF_Msk           (0x1ul << CLK_CLKDSTS_LXTFIF_Pos)                 /*!< CLK_T::CLKDSTS: LXTFIF Mask            */

#define CLK_CLKDSTS_HXTFQIF_Pos          (8)                                               /*!< CLK_T::CLKDSTS: HXTFQIF Position       */
#define CLK_CLKDSTS_HXTFQIF_Msk          (0x1ul << CLK_CLKDSTS_HXTFQIF_Pos)                /*!< CLK_T::CLKDSTS: HXTFQIF Mask           */

#define CLK_CDUPB_UPERBD_Pos             (0)                                               /*!< CLK_T::CDUPB: UPERBD Position          */
#define CLK_CDUPB_UPERBD_Msk             (0x3fful << CLK_CDUPB_UPERBD_Pos)                 /*!< CLK_T::CDUPB: UPERBD Mask              */

#define CLK_CDLOWB_LOWERBD_Pos           (0)                                               /*!< CLK_T::CDLOWB: LOWERBD Position        */
#define CLK_CDLOWB_LOWERBD_Msk           (0x3fful << CLK_CDLOWB_LOWERBD_Pos)               /*!< CLK_T::CDLOWB: LOWERBD Mask            */

#define CLK_STOPREQ_CANFD0STR_Pos        (0)                                               /*!< CLK_T::STOPREQ: CANFD0STR Position     */
#define CLK_STOPREQ_CANFD0STR_Msk        (0x1ul << CLK_STOPREQ_CANFD0STR_Pos)              /*!< CLK_T::STOPREQ: CANFD0STR Mask         */

#define CLK_STOPREQ_CANFD1STR_Pos        (1)                                               /*!< CLK_T::STOPREQ: CANFD1STR Position     */
#define CLK_STOPREQ_CANFD1STR_Msk        (0x1ul << CLK_STOPREQ_CANFD1STR_Pos)              /*!< CLK_T::STOPREQ: CANFD1STR Mask         */

#define CLK_STOPREQ_CANFD2STR_Pos        (2)                                               /*!< CLK_T::STOPREQ: CANFD2STR Position     */
#define CLK_STOPREQ_CANFD2STR_Msk        (0x1ul << CLK_STOPREQ_CANFD2STR_Pos)              /*!< CLK_T::STOPREQ: CANFD2STR Mask         */

#define CLK_STOPREQ_CANFD3STR_Pos        (3)                                               /*!< CLK_T::STOPREQ: CANFD3STR Position     */
#define CLK_STOPREQ_CANFD3STR_Msk        (0x1ul << CLK_STOPREQ_CANFD3STR_Pos)              /*!< CLK_T::STOPREQ: CANFD3STR Mask         */

#define CLK_STOPACK_CANFD0STA_Pos        (0)                                               /*!< CLK_T::STOPACK: CANFD0STA Position     */
#define CLK_STOPACK_CANFD0STA_Msk        (0x1ul << CLK_STOPACK_CANFD0STA_Pos)              /*!< CLK_T::STOPACK: CANFD0STA Mask         */

#define CLK_STOPACK_CANFD1STA_Pos        (1)                                               /*!< CLK_T::STOPACK: CANFD1STA Position     */
#define CLK_STOPACK_CANFD1STA_Msk        (0x1ul << CLK_STOPACK_CANFD1STA_Pos)              /*!< CLK_T::STOPACK: CANFD1STA Mask         */

#define CLK_STOPACK_CANFD2STA_Pos        (2)                                               /*!< CLK_T::STOPACK: CANFD2STA Position     */
#define CLK_STOPACK_CANFD2STA_Msk        (0x1ul << CLK_STOPACK_CANFD2STA_Pos)              /*!< CLK_T::STOPACK: CANFD2STA Mask         */

#define CLK_STOPACK_CANFD3STA_Pos        (3)                                               /*!< CLK_T::STOPACK: CANFD3STA Position     */
#define CLK_STOPACK_CANFD3STA_Msk        (0x1ul << CLK_STOPACK_CANFD3STA_Pos)              /*!< CLK_T::STOPACK: CANFD3STA Mask         */

#define CLK_PMUCTL_PDMSEL_Pos            (0)                                               /*!< CLK_T::PMUCTL: PDMSEL Position         */
#define CLK_PMUCTL_PDMSEL_Msk            (0x7ul << CLK_PMUCTL_PDMSEL_Pos)                  /*!< CLK_T::PMUCTL: PDMSEL Mask             */

#define CLK_PMUCTL_DPDHOLDEN_Pos         (3)                                               /*!< CLK_T::PMUCTL: DPDHOLDEN Position      */
#define CLK_PMUCTL_DPDHOLDEN_Msk         (0x1ul << CLK_PMUCTL_DPDHOLDEN_Pos)               /*!< CLK_T::PMUCTL: DPDHOLDEN Mask          */

#define CLK_PMUCTL_SRETSEL_Pos           (4)                                               /*!< CLK_T::PMUCTL: SRETSEL Position        */
#define CLK_PMUCTL_SRETSEL_Msk           (0x7ul << CLK_PMUCTL_SRETSEL_Pos)                 /*!< CLK_T::PMUCTL: SRETSEL Mask            */

#define CLK_PMUCTL_WKTMREN_Pos           (8)                                               /*!< CLK_T::PMUCTL: WKTMREN Position        */
#define CLK_PMUCTL_WKTMREN_Msk           (0x1ul << CLK_PMUCTL_WKTMREN_Pos)                 /*!< CLK_T::PMUCTL: WKTMREN Mask            */

#define CLK_PMUCTL_WKTMRIS_Pos           (9)                                               /*!< CLK_T::PMUCTL: WKTMRIS Position        */
#define CLK_PMUCTL_WKTMRIS_Msk           (0xful << CLK_PMUCTL_WKTMRIS_Pos)                 /*!< CLK_T::PMUCTL: WKTMRIS Mask            */

#define CLK_PMUCTL_WKPINEN0_Pos          (16)                                              /*!< CLK_T::PMUCTL: WKPINEN0 Position       */
#define CLK_PMUCTL_WKPINEN0_Msk          (0x3ul << CLK_PMUCTL_WKPINEN0_Pos)                /*!< CLK_T::PMUCTL: WKPINEN0 Mask           */

#define CLK_PMUCTL_ACMPSPWK_Pos          (18)                                              /*!< CLK_T::PMUCTL: ACMPSPWK Position       */
#define CLK_PMUCTL_ACMPSPWK_Msk          (0x1ul << CLK_PMUCTL_ACMPSPWK_Pos)                /*!< CLK_T::PMUCTL: ACMPSPWK Mask           */

#define CLK_PMUCTL_VBUSWKEN_Pos          (22)                                              /*!< CLK_T::PMUCTL: VBUSWKEN Position       */
#define CLK_PMUCTL_VBUSWKEN_Msk          (0x1ul << CLK_PMUCTL_VBUSWKEN_Pos)                /*!< CLK_T::PMUCTL: VBUSWKEN Mask           */

#define CLK_PMUCTL_RTCWKEN_Pos           (23)                                              /*!< CLK_T::PMUCTL: RTCWKEN Position        */
#define CLK_PMUCTL_RTCWKEN_Msk           (0x1ul << CLK_PMUCTL_RTCWKEN_Pos)                 /*!< CLK_T::PMUCTL: RTCWKEN Mask            */

#define CLK_PMUCTL_WKPINEN1_Pos          (24)                                              /*!< CLK_T::PMUCTL: WKPINEN1 Position       */
#define CLK_PMUCTL_WKPINEN1_Msk          (0x3ul << CLK_PMUCTL_WKPINEN1_Pos)                /*!< CLK_T::PMUCTL: WKPINEN1 Mask           */

#define CLK_PMUCTL_WKPINEN2_Pos          (26)                                              /*!< CLK_T::PMUCTL: WKPINEN2 Position       */
#define CLK_PMUCTL_WKPINEN2_Msk          (0x3ul << CLK_PMUCTL_WKPINEN2_Pos)                /*!< CLK_T::PMUCTL: WKPINEN2 Mask           */

#define CLK_PMUCTL_WKPINEN3_Pos          (28)                                              /*!< CLK_T::PMUCTL: WKPINEN3 Position       */
#define CLK_PMUCTL_WKPINEN3_Msk          (0x3ul << CLK_PMUCTL_WKPINEN3_Pos)                /*!< CLK_T::PMUCTL: WKPINEN3 Mask           */

#define CLK_PMUCTL_WKPINEN4_Pos          (30)                                              /*!< CLK_T::PMUCTL: WKPINEN4 Position       */
#define CLK_PMUCTL_WKPINEN4_Msk          (0x3ul << CLK_PMUCTL_WKPINEN4_Pos)                /*!< CLK_T::PMUCTL: WKPINEN4 Mask           */

#define CLK_PMUSTS_PINWK0_Pos            (0)                                               /*!< CLK_T::PMUSTS: PINWK0 Position         */
#define CLK_PMUSTS_PINWK0_Msk            (0x1ul << CLK_PMUSTS_PINWK0_Pos)                  /*!< CLK_T::PMUSTS: PINWK0 Mask             */

#define CLK_PMUSTS_TMRWK_Pos             (1)                                               /*!< CLK_T::PMUSTS: TMRWK Position          */
#define CLK_PMUSTS_TMRWK_Msk             (0x1ul << CLK_PMUSTS_TMRWK_Pos)                   /*!< CLK_T::PMUSTS: TMRWK Mask              */

#define CLK_PMUSTS_RTCWK_Pos             (2)                                               /*!< CLK_T::PMUSTS: RTCWK Position          */
#define CLK_PMUSTS_RTCWK_Msk             (0x1ul << CLK_PMUSTS_RTCWK_Pos)                   /*!< CLK_T::PMUSTS: RTCWK Mask              */

#define CLK_PMUSTS_PINWK1_Pos            (3)                                               /*!< CLK_T::PMUSTS: PINWK1 Position         */
#define CLK_PMUSTS_PINWK1_Msk            (0x1ul << CLK_PMUSTS_PINWK1_Pos)                  /*!< CLK_T::PMUSTS: PINWK1 Mask             */

#define CLK_PMUSTS_PINWK2_Pos            (4)                                               /*!< CLK_T::PMUSTS: PINWK2 Position         */
#define CLK_PMUSTS_PINWK2_Msk            (0x1ul << CLK_PMUSTS_PINWK2_Pos)                  /*!< CLK_T::PMUSTS: PINWK2 Mask             */

#define CLK_PMUSTS_PINWK3_Pos            (5)                                               /*!< CLK_T::PMUSTS: PINWK3 Position         */
#define CLK_PMUSTS_PINWK3_Msk            (0x1ul << CLK_PMUSTS_PINWK3_Pos)                  /*!< CLK_T::PMUSTS: PINWK3 Mask             */

#define CLK_PMUSTS_PINWK4_Pos            (6)                                               /*!< CLK_T::PMUSTS: PINWK4 Position         */
#define CLK_PMUSTS_PINWK4_Msk            (0x1ul << CLK_PMUSTS_PINWK4_Pos)                  /*!< CLK_T::PMUSTS: PINWK4 Mask             */

#define CLK_PMUSTS_VBUSWK_Pos            (7)                                               /*!< CLK_T::PMUSTS: VBUSWK Position         */
#define CLK_PMUSTS_VBUSWK_Msk            (0x1ul << CLK_PMUSTS_VBUSWK_Pos)                  /*!< CLK_T::PMUSTS: VBUSWK Mask             */

#define CLK_PMUSTS_GPAWK_Pos             (8)                                               /*!< CLK_T::PMUSTS: GPAWK Position          */
#define CLK_PMUSTS_GPAWK_Msk             (0x1ul << CLK_PMUSTS_GPAWK_Pos)                   /*!< CLK_T::PMUSTS: GPAWK Mask              */

#define CLK_PMUSTS_GPBWK_Pos             (9)                                               /*!< CLK_T::PMUSTS: GPBWK Position          */
#define CLK_PMUSTS_GPBWK_Msk             (0x1ul << CLK_PMUSTS_GPBWK_Pos)                   /*!< CLK_T::PMUSTS: GPBWK Mask              */

#define CLK_PMUSTS_GPCWK_Pos             (10)                                              /*!< CLK_T::PMUSTS: GPCWK Position          */
#define CLK_PMUSTS_GPCWK_Msk             (0x1ul << CLK_PMUSTS_GPCWK_Pos)                   /*!< CLK_T::PMUSTS: GPCWK Mask              */

#define CLK_PMUSTS_GPDWK_Pos             (11)                                              /*!< CLK_T::PMUSTS: GPDWK Position          */
#define CLK_PMUSTS_GPDWK_Msk             (0x1ul << CLK_PMUSTS_GPDWK_Pos)                   /*!< CLK_T::PMUSTS: GPDWK Mask              */

#define CLK_PMUSTS_LVRWK_Pos             (12)                                              /*!< CLK_T::PMUSTS: LVRWK Position          */
#define CLK_PMUSTS_LVRWK_Msk             (0x1ul << CLK_PMUSTS_LVRWK_Pos)                   /*!< CLK_T::PMUSTS: LVRWK Mask              */

#define CLK_PMUSTS_BODWK_Pos             (13)                                              /*!< CLK_T::PMUSTS: BODWK Position          */
#define CLK_PMUSTS_BODWK_Msk             (0x1ul << CLK_PMUSTS_BODWK_Pos)                   /*!< CLK_T::PMUSTS: BODWK Mask              */

#define CLK_PMUSTS_RSTWK_Pos             (15)                                              /*!< CLK_T::PMUSTS: RSTWK Position          */
#define CLK_PMUSTS_RSTWK_Msk             (0x1ul << CLK_PMUSTS_RSTWK_Pos)                   /*!< CLK_T::PMUSTS: RSTWK Mask              */

#define CLK_PMUSTS_ACMPWK0_Pos           (16)                                              /*!< CLK_T::PMUSTS: ACMPWK0 Position        */
#define CLK_PMUSTS_ACMPWK0_Msk           (0x1ul << CLK_PMUSTS_ACMPWK0_Pos)                 /*!< CLK_T::PMUSTS: ACMPWK0 Mask            */

#define CLK_PMUSTS_ACMPWK1_Pos           (17)                                              /*!< CLK_T::PMUSTS: ACMPWK1 Position        */
#define CLK_PMUSTS_ACMPWK1_Msk           (0x1ul << CLK_PMUSTS_ACMPWK1_Pos)                 /*!< CLK_T::PMUSTS: ACMPWK1 Mask            */

#define CLK_PMUSTS_ACMPWK2_Pos           (18)                                              /*!< CLK_T::PMUSTS: ACMPWK2 Position        */
#define CLK_PMUSTS_ACMPWK2_Msk           (0x1ul << CLK_PMUSTS_ACMPWK2_Pos)                 /*!< CLK_T::PMUSTS: ACMPWK2 Mask            */

#define CLK_PMUSTS_ACMPWK3_Pos           (19)                                              /*!< CLK_T::PMUSTS: ACMPWK3 Position        */
#define CLK_PMUSTS_ACMPWK3_Msk           (0x1ul << CLK_PMUSTS_ACMPWK3_Pos)                 /*!< CLK_T::PMUSTS: ACMPWK3 Mask            */

#define CLK_PMUSTS_CLRWK_Pos             (31)                                              /*!< CLK_T::PMUSTS: CLRWK Position          */
#define CLK_PMUSTS_CLRWK_Msk             (0x1ul << CLK_PMUSTS_CLRWK_Pos)                   /*!< CLK_T::PMUSTS: CLRWK Mask              */

#define CLK_SWKDBCTL_SWKDBCLKSEL_Pos     (0)                                               /*!< CLK_T::SWKDBCTL: SWKDBCLKSEL Position  */
#define CLK_SWKDBCTL_SWKDBCLKSEL_Msk     (0xful << CLK_SWKDBCTL_SWKDBCLKSEL_Pos)           /*!< CLK_T::SWKDBCTL: SWKDBCLKSEL Mask      */

#define CLK_PASWKCTL_WKEN_Pos            (0)                                               /*!< CLK_T::PASWKCTL: WKEN Position         */
#define CLK_PASWKCTL_WKEN_Msk            (0x1ul << CLK_PASWKCTL_WKEN_Pos)                  /*!< CLK_T::PASWKCTL: WKEN Mask             */

#define CLK_PASWKCTL_PRWKEN_Pos          (1)                                               /*!< CLK_T::PASWKCTL: PRWKEN Position       */
#define CLK_PASWKCTL_PRWKEN_Msk          (0x1ul << CLK_PASWKCTL_PRWKEN_Pos)                /*!< CLK_T::PASWKCTL: PRWKEN Mask           */

#define CLK_PASWKCTL_PFWKEN_Pos          (2)                                               /*!< CLK_T::PASWKCTL: PFWKEN Position       */
#define CLK_PASWKCTL_PFWKEN_Msk          (0x1ul << CLK_PASWKCTL_PFWKEN_Pos)                /*!< CLK_T::PASWKCTL: PFWKEN Mask           */

#define CLK_PASWKCTL_WKPSEL_Pos          (4)                                               /*!< CLK_T::PASWKCTL: WKPSEL Position       */
#define CLK_PASWKCTL_WKPSEL_Msk          (0xful << CLK_PASWKCTL_WKPSEL_Pos)                /*!< CLK_T::PASWKCTL: WKPSEL Mask           */

#define CLK_PASWKCTL_DBEN_Pos            (8)                                               /*!< CLK_T::PASWKCTL: DBEN Position         */
#define CLK_PASWKCTL_DBEN_Msk            (0x1ul << CLK_PASWKCTL_DBEN_Pos)                  /*!< CLK_T::PASWKCTL: DBEN Mask             */

#define CLK_PBSWKCTL_WKEN_Pos            (0)                                               /*!< CLK_T::PBSWKCTL: WKEN Position         */
#define CLK_PBSWKCTL_WKEN_Msk            (0x1ul << CLK_PBSWKCTL_WKEN_Pos)                  /*!< CLK_T::PBSWKCTL: WKEN Mask             */

#define CLK_PBSWKCTL_PRWKEN_Pos          (1)                                               /*!< CLK_T::PBSWKCTL: PRWKEN Position       */
#define CLK_PBSWKCTL_PRWKEN_Msk          (0x1ul << CLK_PBSWKCTL_PRWKEN_Pos)                /*!< CLK_T::PBSWKCTL: PRWKEN Mask           */

#define CLK_PBSWKCTL_PFWKEN_Pos          (2)                                               /*!< CLK_T::PBSWKCTL: PFWKEN Position       */
#define CLK_PBSWKCTL_PFWKEN_Msk          (0x1ul << CLK_PBSWKCTL_PFWKEN_Pos)                /*!< CLK_T::PBSWKCTL: PFWKEN Mask           */

#define CLK_PBSWKCTL_WKPSEL_Pos          (4)                                               /*!< CLK_T::PBSWKCTL: WKPSEL Position       */
#define CLK_PBSWKCTL_WKPSEL_Msk          (0xful << CLK_PBSWKCTL_WKPSEL_Pos)                /*!< CLK_T::PBSWKCTL: WKPSEL Mask           */

#define CLK_PBSWKCTL_DBEN_Pos            (8)                                               /*!< CLK_T::PBSWKCTL: DBEN Position         */
#define CLK_PBSWKCTL_DBEN_Msk            (0x1ul << CLK_PBSWKCTL_DBEN_Pos)                  /*!< CLK_T::PBSWKCTL: DBEN Mask             */

#define CLK_PCSWKCTL_WKEN_Pos            (0)                                               /*!< CLK_T::PCSWKCTL: WKEN Position         */
#define CLK_PCSWKCTL_WKEN_Msk            (0x1ul << CLK_PCSWKCTL_WKEN_Pos)                  /*!< CLK_T::PCSWKCTL: WKEN Mask             */

#define CLK_PCSWKCTL_PRWKEN_Pos          (1)                                               /*!< CLK_T::PCSWKCTL: PRWKEN Position       */
#define CLK_PCSWKCTL_PRWKEN_Msk          (0x1ul << CLK_PCSWKCTL_PRWKEN_Pos)                /*!< CLK_T::PCSWKCTL: PRWKEN Mask           */

#define CLK_PCSWKCTL_PFWKEN_Pos          (2)                                               /*!< CLK_T::PCSWKCTL: PFWKEN Position       */
#define CLK_PCSWKCTL_PFWKEN_Msk          (0x1ul << CLK_PCSWKCTL_PFWKEN_Pos)                /*!< CLK_T::PCSWKCTL: PFWKEN Mask           */

#define CLK_PCSWKCTL_WKPSEL_Pos          (4)                                               /*!< CLK_T::PCSWKCTL: WKPSEL Position       */
#define CLK_PCSWKCTL_WKPSEL_Msk          (0xful << CLK_PCSWKCTL_WKPSEL_Pos)                /*!< CLK_T::PCSWKCTL: WKPSEL Mask           */

#define CLK_PCSWKCTL_DBEN_Pos            (8)                                               /*!< CLK_T::PCSWKCTL: DBEN Position         */
#define CLK_PCSWKCTL_DBEN_Msk            (0x1ul << CLK_PCSWKCTL_DBEN_Pos)                  /*!< CLK_T::PCSWKCTL: DBEN Mask             */

#define CLK_PDSWKCTL_WKEN_Pos            (0)                                               /*!< CLK_T::PDSWKCTL: WKEN Position         */
#define CLK_PDSWKCTL_WKEN_Msk            (0x1ul << CLK_PDSWKCTL_WKEN_Pos)                  /*!< CLK_T::PDSWKCTL: WKEN Mask             */

#define CLK_PDSWKCTL_PRWKEN_Pos          (1)                                               /*!< CLK_T::PDSWKCTL: PRWKEN Position       */
#define CLK_PDSWKCTL_PRWKEN_Msk          (0x1ul << CLK_PDSWKCTL_PRWKEN_Pos)                /*!< CLK_T::PDSWKCTL: PRWKEN Mask           */

#define CLK_PDSWKCTL_PFWKEN_Pos          (2)                                               /*!< CLK_T::PDSWKCTL: PFWKEN Position       */
#define CLK_PDSWKCTL_PFWKEN_Msk          (0x1ul << CLK_PDSWKCTL_PFWKEN_Pos)                /*!< CLK_T::PDSWKCTL: PFWKEN Mask           */

#define CLK_PDSWKCTL_WKPSEL_Pos          (4)                                               /*!< CLK_T::PDSWKCTL: WKPSEL Position       */
#define CLK_PDSWKCTL_WKPSEL_Msk          (0xful << CLK_PDSWKCTL_WKPSEL_Pos)                /*!< CLK_T::PDSWKCTL: WKPSEL Mask           */

#define CLK_PDSWKCTL_DBEN_Pos            (8)                                               /*!< CLK_T::PDSWKCTL: DBEN Position         */
#define CLK_PDSWKCTL_DBEN_Msk            (0x1ul << CLK_PDSWKCTL_DBEN_Pos)                  /*!< CLK_T::PDSWKCTL: DBEN Mask             */

#define CLK_IOPDCTL_IOHR_Pos             (0)                                               /*!< CLK_T::IOPDCTL: IOHR Position          */
#define CLK_IOPDCTL_IOHR_Msk             (0x1ul << CLK_IOPDCTL_IOHR_Pos)                   /*!< CLK_T::IOPDCTL: IOHR Mask              */


/**@}*/ /* CLK_CONST */
/**@}*/ /* end of CLK register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __CLK_REG_H__ */
