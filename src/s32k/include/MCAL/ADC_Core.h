/*
 * ADC_Core.h
 *
 * Target:   NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   ADC MCAL driver interface.
 *   Supports ADC0 and ADC1 modules, up to 16 channels each.
 *   Configuration parameters (enabled channels, resolution, clock)
 *   are in ADC_Cfg.h.
 *
 * Clock source:
 *   SOSCDIV2 (8 MHz) selected via PCC_PCCn_PCS(1).
 *   ADC input clock = 8 MHz / ADIV divider (configured per module in Cfg).
 *
 * Conversion modes:
 *   Software trigger (ADTRG=0) -- conversion starts on ADCH write
 *   Hardware trigger (ADTRG=1) -- conversion triggered by PDB/TRGMUX
 *   Continuous conversion (ADCO=1) -- restarts automatically after each
 *
 * Ref: S32K144 Reference Manual, Chapter 40 (ADC), pages 1215-1265.
 */

#ifndef MCAL_ADC_CORE_H_
#define MCAL_ADC_CORE_H_

#include "Headers.h"

/*===========================================================================
 * CFG1 REGISTER CONSTANTS
 * Ref. Manual page 1227 -- ADC_CFG1 register
 *=========================================================================*/

/* ADIV -- ADC clock divider (CFG1[ADIV])                                  */
#define ADCn_CFG1_ADIV_DIV1     0b00    /* Input clock / 1                 */
#define ADCn_CFG1_ADIV_DIV2     0b01    /* Input clock / 2                 */
#define ADCn_CFG1_ADIV_DIV4     0b10    /* Input clock / 4                 */
#define ADCn_CFG1_ADIV_DIV8     0b11    /* Input clock / 8                 */

/* MODE -- ADC resolution (CFG1[MODE])                                     */
#define ADCn_CFG1_MODE_8BIT     0b00    /* 8-bit conversion                */
#define ADCn_CFG1_MODE_12BIT    0b01    /* 12-bit conversion               */
#define ADCn_CFG1_MODE_10BIT    0b10    /* 10-bit conversion               */

/* ADICLK -- ADC input clock source (CFG1[ADICLK])                         */
#define ADCn_CFG1_ADICLK_1      0b00    /* Bus clock                       */
#define ADCn_CFG1_ADICLK_2      0b01    /* Bus clock / 2                   */
#define ADCn_CFG1_ADICLK_3      0b10    /* Alternate clock 1 (SOSCDIV2)    */
#define ADCn_CFG1_ADICLK_4      0b11    /* Asynchronous ADC clock (ADACK)  */

/*===========================================================================
 * SC1 REGISTER CONSTANTS -- Channel selection (SC1[ADCH])
 * Ref. Manual page 1225 -- ADC_SC1 register
 *=========================================================================*/
#define ADCn_SC1_ADCH_EXTCH0ASINPUT     0b000000    /* External channel 0  */
#define ADCn_SC1_ADCH_EXTCH1ASINPUT     0b000001    /* External channel 1  */
#define ADCn_SC1_ADCH_EXTCH2ASINPUT     0b000010    /* External channel 2  */
#define ADCn_SC1_ADCH_EXTCH3ASINPUT     0b000011    /* External channel 3  */
#define ADCn_SC1_ADCH_EXTCH4ASINPUT     0b000100    /* External channel 4  */
#define ADCn_SC1_ADCH_EXTCH5ASINPUT     0b000101    /* External channel 5  */
#define ADCn_SC1_ADCH_EXTCH6ASINPUT     0b000110    /* External channel 6  */
#define ADCn_SC1_ADCH_EXTCH7ASINPUT     0b000111    /* External channel 7  */
#define ADCn_SC1_ADCH_EXTCH8ASINPUT     0b001000    /* External channel 8  */
#define ADCn_SC1_ADCH_EXTCH9ASINPUT     0b001001    /* External channel 9  */
#define ADCn_SC1_ADCH_EXTCH10ASINPUT    0b001010    /* External channel 10 */
#define ADCn_SC1_ADCH_EXTCH11ASINPUT    0b001011    /* External channel 11 */
#define ADCn_SC1_ADCH_EXTCH12ASINPUT    0b001100    /* External channel 12 */
#define ADCn_SC1_ADCH_EXTCH13ASINPUT    0b001101    /* External channel 13 */
#define ADCn_SC1_ADCH_EXTCH14ASINPUT    0b001110    /* External channel 14 */
#define ADCn_SC1_ADCH_EXTCH15ASINPUT    0b001111    /* External channel 15 */
#define ADCn_SC1_ADCH_INTCH0ASINPUT     0b010101    /* Internal channel 0  */
#define ADCn_SC1_ADCH_INTCH1ASINPUT     0b010110    /* Internal channel 1  */
#define ADCn_SC1_ADCH_INTCH2ASINPUT     0b010111    /* Internal channel 2  */
#define ADCn_SC1_ADCH_BANDGAP           0b011011    /* Bandgap voltage      */
#define ADCn_SC1_ADCH_INTCH3ASINPUT     0b011100    /* Internal channel 3  */
#define ADCn_SC1_ADCH_VREFSHASINPUT     0b011101    /* High reference (VREFH) -- see SC2[REFSEL] */
#define ADCn_SC1_ADCH_VREFSLASINPUT     0b011110    /* Low reference (VREFL)  */
#define ADCn_SC1_ADCH_EXTCH16ASINPUT    0b100000    /* External channel 16 */
#define ADCn_SC1_ADCH_EXTCH17ASINPUT    0b100001    /* External channel 17 */
#define ADCn_SC1_ADCH_EXTCH18ASINPUT    0b100010    /* External channel 18 */
#define ADCn_SC1_ADCH_EXTCH19ASINPUT    0b100011    /* External channel 19 */
#define ADCn_SC1_ADCH_EXTCH20ASINPUT    0b100100    /* External channel 20 */
#define ADCn_SC1_ADCH_EXTCH21ASINPUT    0b100101    /* External channel 21 */
#define ADCn_SC1_ADCH_EXTCH22ASINPUT    0b100110    /* External channel 22 */
#define ADCn_SC1_ADCH_EXTCH23ASINPUT    0b100111    /* External channel 23 */
#define ADCn_SC1_ADCH_EXTCH24ASINPUT    0b101000    /* External channel 24 */
#define ADCn_SC1_ADCH_EXTCH25ASINPUT    0b101001    /* External channel 25 */
#define ADCn_SC1_ADCH_EXTCH26ASINPUT    0b101010    /* External channel 26 */
#define ADCn_SC1_ADCH_EXTCH27ASINPUT    0b101011    /* External channel 27 */
#define ADCn_SC1_ADCH_EXTCH28ASINPUT    0b101100    /* External channel 28 */
#define ADCn_SC1_ADCH_EXTCH29ASINPUT    0b101101    /* External channel 29 */
#define ADCn_SC1_ADCH_EXTCH30ASINPUT    0b101110    /* External channel 30 */
#define ADCn_SC1_ADCH_EXTCH31ASINPUT    0b101111    /* External channel 31 */

/*===========================================================================
 * SC2 REGISTER CONSTANTS
 * Ref. Manual page 1234 -- ADC_SC2 register
 *=========================================================================*/
#define ADCn_SC2_CONVTRIGSW     0b0     /* Software trigger                */
#define ADCn_SC2_CONVTRIGHW     0b1     /* Hardware trigger (PDB/TRGMUX)   */

#define ADCn_SC2_REF_SELDEFAULT 0b00    /* Default reference (VREFH/VREFL) */
#define ADCn_SC2_REF_SELALTREFVTG 0b01  /* Alternate reference voltage     */

/*===========================================================================
 * SC3 REGISTER CONSTANTS -- Hardware averaging
 * Ref. Manual page 1237 -- ADC_SC3 register
 *=========================================================================*/
#define ADCn_SC3_HWAVGBY4SAMPLES    0b00    /* Average 4 samples           */
#define ADCn_SC3_HWAVGBY8SAMPLES    0b01    /* Average 8 samples           */
#define ADCn_SC3_HWAVGBY16SAMPLES   0b10    /* Average 16 samples          */
#define ADCn_SC3_HWAVGBY32SAMPLES   0b11    /* Average 32 samples          */

/*===========================================================================
 * REGISTER OPERATION MACROS
 *=========================================================================*/

/* Configure CFG1: clock divider, resolution, input clock source
 * Ref. Manual page 1227                                                    */
#define ADCn_CFG1(AdcModNo, Adiv, Mode, AdiClk)    \
    ((AdcModNo)->CFG1 |= (ADC_CFG1_ADICLK(AdiClk)  |   \
                          ADC_CFG1_MODE(Mode)        |   \
                          ADC_CFG1_ADIV(Adiv)))

/* Configure CFG2: sample time
 * Ref. Manual page 1228                                                    */
#define ADCn_CFG2(AdcModNo, SampleRate) \
    ((AdcModNo)->CFG2 |= ADC_CFG2_SMPLTS(SampleRate))

/* Configure SC1 for a channel: interrupt enable and channel select
 * Ref. Manual page 1225                                                    */
#define ADCn_SC1_CHx(AdcModNo, ChnlNo, Aien, Adch) \
    ((AdcModNo)->SC1[(ChnlNo)] |= (ADC_SC1_AIEN(Aien) | ADC_SC1_ADCH(Adch)))

/* Configure SC2: trigger, compare, DMA, reference voltage
 * Ref. Manual page 1234                                                    */
#define ADCn_SC2_CHx(AdcModNo, TrigSel, Comp, CompGrt, CompRng, DmaEn, VtgRefSel) \
    ((AdcModNo)->SC2 |= (ADC_SC2_REFSEL(VtgRefSel)  |   \
                         ADC_SC2_DMAEN(DmaEn)        |   \
                         ADC_SC2_ACREN(CompRng)       |   \
                         ADC_SC2_ACFGT(CompGrt)       |   \
                         ADC_SC2_ACFE(Comp)           |   \
                         ADC_SC2_ADTRG(TrigSel)))

/* Configure SC3: continuous conversion, hardware averaging
 * Ref. Manual page 1237                                                    */
#define ADCn_SC3_CHx(AdcModNo, ContiConv, HwAvg, HwAvgSel) \
    ((AdcModNo)->SC3 |= (ADC_SC3_AVGS(HwAvgSel)     |   \
                         ADC_SC3_AVGE(HwAvg)         |   \
                         ADC_SC3_ADCO(ContiConv)))

/* Set clear-on-read trigger in CFG1 (CLRLTRG bit)                         */
#define ADCn_CFG1_SETCLRTRIG(AdcModNo) \
    ((AdcModNo)->CFG1 |= ADC_CFG1_CLRLTRG_MASK)

/* Start calibration -- write CAL bit in SC3
 * Ref. Manual page 1237                                                    */
#define ADCn_SC3_CALIB_SET(AdcModNo) \
    ((AdcModNo)->SC3 |= ADC_SC3_CAL_MASK)

/*===========================================================================
 * PUBLIC FUNCTION DECLARATIONS
 *=========================================================================*/
extern void ADC_Init(void);
extern void ADC0_Init(void);
extern void ADC1_Init(void);

#endif /* MCAL_ADC_CORE_H_ */
