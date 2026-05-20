/*
 * ADC_Core.c
 *
 * Target:   NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   ADC MCAL driver implementation.
 *   Initializes ADC0 and ADC1 modules based on configuration in ADC_Cfg.h.
 *   Each module is gated by ENABLE/DISABLE compile-time flags.
 *
 * Clock:
 *   PCC_PCCn_PCS(1) selects SOSCDIV2 (8 MHz) as ADC clock source.
 *   ADC clock = 8 MHz / ADIV divider (configured in ADC_Cfg.h per module).
 *   Clock must be disabled before changing PCS, then re-enabled.
 *   Ref. Manual page 958 -- PCC_ADC0/1 registers.
 *
 * Ref: S32K144 Reference Manual, Chapter 40 (ADC), pages 1215-1265.
 */

#include "Headers.h"

/*===========================================================================
 * PUBLIC FUNCTIONS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * ADC_Init
 *
 * Top-level ADC initialization. Calls ADC0_Init and/or ADC1_Init
 * based on compile-time module enable flags in ADC_Cfg.h.
 * Called from main.c during MCAL initialization sequence.
 *--------------------------------------------------------------------------*/
void ADC_Init(void)
{
#if(ADC0_MODULE == ENABLE)
    ADC0_Init();
#endif

#if(ADC1_MODULE == ENABLE)
    ADC1_Init();
#endif
}

/*---------------------------------------------------------------------------
 * ADC0_Init
 *
 * Initializes ADC0 module with parameters from ADC_Cfg.h.
 *
 * Sequence:
 *   1. Enable PCC clock with SOSCDIV2 source
 *   2. Disable module (write ADCH=0x1F to SC1[0])
 *   3. Configure CFG1 (clock divider, resolution, input clock)
 *   4. Configure CFG2 (sample time)
 *   5. Configure enabled SC1 channels (channel select, interrupt enable)
 *   6. Configure SC2 (trigger, compare, DMA, reference)
 *   7. Configure SC3 (continuous conversion, hardware averaging)
 *--------------------------------------------------------------------------*/
#if(ADC0_MODULE == ENABLE)

void ADC0_Init(void)
{
    /* Step 1 -- Enable PCC clock with SOSCDIV2 as source                  */
    PCC->PCCn[PCC_ADC0_INDEX] &= ~PCC_PCCn_CGC_MASK;   /* Disable clock to change PCS     */
    PCC->PCCn[PCC_ADC0_INDEX] |=  PCC_PCCn_PCS(1u);    /* PCS=1: Select SOSCDIV2 (8 MHz)  */
    PCC->PCCn[PCC_ADC0_INDEX] |=  PCC_PCCn_CGC_MASK;   /* Re-enable clock to ADC0         */

    /* Step 2 -- Disable module before configuration
     * ADCH=0x1F disables conversions, AIEN=0 disables interrupts
     * Ref. Manual page 1225                                                */
    ADC0->SC1[0] |= ADC_SC1_ADCH_MASK;

    /* Step 3 -- Configure CFG1: clock divider, resolution, input clock    */
    ADCn_CFG1(ADC0,
              ADC0_CFG1_ADIV_DIV,
              ADC0_CFG1_MODE_DIV,
              ADC0_CFG1_ADICLK);

    /* Step 4 -- Configure CFG2: sample time                               */
    ADCn_CFG2(ADC0, ADC0_CFG2_SAMPLERATE);

    /* Step 5 -- Configure enabled SC1 channels                            */
#if(ADC0_CHANNEL_0 == ENABLE)
    ADCn_SC1_CHx(ADC0, 0u,  ADC0_CHANNEL_0_INTRPT,  ADC0_CHANNEL_0_ADCH);
#endif
#if(ADC0_CHANNEL_1 == ENABLE)
    ADCn_SC1_CHx(ADC0, 1u,  ADC0_CHANNEL_1_INTRPT,  ADC0_CHANNEL_1_ADCH);
#endif
#if(ADC0_CHANNEL_2 == ENABLE)
    ADCn_SC1_CHx(ADC0, 2u,  ADC0_CHANNEL_2_INTRPT,  ADC0_CHANNEL_2_ADCH);
#endif
#if(ADC0_CHANNEL_3 == ENABLE)
    ADCn_SC1_CHx(ADC0, 3u,  ADC0_CHANNEL_3_INTRPT,  ADC0_CHANNEL_3_ADCH);
#endif
#if(ADC0_CHANNEL_4 == ENABLE)
    ADCn_SC1_CHx(ADC0, 4u,  ADC0_CHANNEL_4_INTRPT,  ADC0_CHANNEL_4_ADCH);
#endif
#if(ADC0_CHANNEL_5 == ENABLE)
    ADCn_SC1_CHx(ADC0, 5u,  ADC0_CHANNEL_5_INTRPT,  ADC0_CHANNEL_5_ADCH);
#endif
#if(ADC0_CHANNEL_6 == ENABLE)
    ADCn_SC1_CHx(ADC0, 6u,  ADC0_CHANNEL_6_INTRPT,  ADC0_CHANNEL_6_ADCH);
#endif
#if(ADC0_CHANNEL_7 == ENABLE)
    ADCn_SC1_CHx(ADC0, 7u,  ADC0_CHANNEL_7_INTRPT,  ADC0_CHANNEL_7_ADCH);
#endif
#if(ADC0_CHANNEL_8 == ENABLE)
    ADCn_SC1_CHx(ADC0, 8u,  ADC0_CHANNEL_8_INTRPT,  ADC0_CHANNEL_8_ADCH);
#endif
#if(ADC0_CHANNEL_9 == ENABLE)
    ADCn_SC1_CHx(ADC0, 9u,  ADC0_CHANNEL_9_INTRPT,  ADC0_CHANNEL_9_ADCH);
#endif
#if(ADC0_CHANNEL_10 == ENABLE)
    ADCn_SC1_CHx(ADC0, 10u, ADC0_CHANNEL_10_INTRPT, ADC0_CHANNEL_10_ADCH);
#endif
#if(ADC0_CHANNEL_11 == ENABLE)
    ADCn_SC1_CHx(ADC0, 11u, ADC0_CHANNEL_11_INTRPT, ADC0_CHANNEL_11_ADCH);
#endif
#if(ADC0_CHANNEL_12 == ENABLE)
    ADCn_SC1_CHx(ADC0, 12u, ADC0_CHANNEL_12_INTRPT, ADC0_CHANNEL_12_ADCH);
#endif
#if(ADC0_CHANNEL_13 == ENABLE)
    ADCn_SC1_CHx(ADC0, 13u, ADC0_CHANNEL_13_INTRPT, ADC0_CHANNEL_13_ADCH);
#endif
#if(ADC0_CHANNEL_14 == ENABLE)
    ADCn_SC1_CHx(ADC0, 14u, ADC0_CHANNEL_14_INTRPT, ADC0_CHANNEL_14_ADCH);
#endif
#if(ADC0_CHANNEL_15 == ENABLE)
    ADCn_SC1_CHx(ADC0, 15u, ADC0_CHANNEL_15_INTRPT, ADC0_CHANNEL_15_ADCH);
#endif

    /* Step 6 -- Configure SC2: trigger, compare, DMA, reference voltage   */
    ADCn_SC2_CHx(ADC0,
                 ADC0_CONV_TRIGSEL,
                 ADC0_COMPFUNCTION,
                 ADC0_COMP_GREATER,
                 ADC0_COMP_RANGE,
                 ADC0_DMA_ACCESS,
                 ADC0_REFVTGSELECT_CFG);

    /* Step 7 -- Configure SC3: continuous conversion, hardware averaging   */
    ADCn_SC3_CHx(ADC0,
                 ADC0_CONTI_CONV,
                 ADC0_HW_AVG_CFG,
                 ADC0_HW_AVG_SEL);
}

/*---------------------------------------------------------------------------
 * ADC0_IRQHandler
 *
 * ADC0 conversion complete interrupt handler.
 * ISF cleared automatically on SC1 read followed by Rn read.
 * TODO: Read result register and store in application buffer.
 * Dev Note: Function name from IV table -- startup_S32K144.S
 *--------------------------------------------------------------------------*/
void INTERRUPT_ ADC0_IRQHandler(void)
{
    /* TODO: Read ADC0->R[0] and store result                               */
}

#endif /* ADC0_MODULE */

/*---------------------------------------------------------------------------
 * ADC1_Init
 *
 * Initializes ADC1 module -- identical structure to ADC0_Init.
 * See ADC0_Init comments for sequence rationale.
 *--------------------------------------------------------------------------*/
#if(ADC1_MODULE == ENABLE)

void ADC1_Init(void)
{
    /* Enable PCC clock with SOSCDIV2 as source                             */
    PCC->PCCn[PCC_ADC1_INDEX] &= ~PCC_PCCn_CGC_MASK;   /* Disable clock to change PCS     */
    PCC->PCCn[PCC_ADC1_INDEX] |=  PCC_PCCn_PCS(1u);    /* PCS=1: Select SOSCDIV2 (8 MHz)  */
    PCC->PCCn[PCC_ADC1_INDEX] |=  PCC_PCCn_CGC_MASK;   /* Re-enable clock to ADC1         */

    /* Disable module before configuration                                  */
    ADC1->SC1[0] |= ADC_SC1_ADCH_MASK;

    /* Configure CFG1: clock divider, resolution, input clock               */
    ADCn_CFG1(ADC1,
              ADC1_CFG1_ADIV_DIV,
              ADC1_CFG1_MODE_DIV,
              ADC1_CFG1_ADICLK);

    /* Configure CFG2: sample time                                          */
    ADCn_CFG2(ADC1, ADC1_CFG2_SAMPLERATE);

    /* Configure enabled SC1 channels                                       */
#if(ADC1_CHANNEL_0 == ENABLE)
    ADCn_SC1_CHx(ADC1, 0u,  ADC1_CHANNEL_0_INTRPT,  ADC1_CHANNEL_0_ADCH);
#endif
#if(ADC1_CHANNEL_1 == ENABLE)
    ADCn_SC1_CHx(ADC1, 1u,  ADC1_CHANNEL_1_INTRPT,  ADC1_CHANNEL_1_ADCH);
#endif
#if(ADC1_CHANNEL_2 == ENABLE)
    ADCn_SC1_CHx(ADC1, 2u,  ADC1_CHANNEL_2_INTRPT,  ADC1_CHANNEL_2_ADCH);
#endif
#if(ADC1_CHANNEL_3 == ENABLE)
    ADCn_SC1_CHx(ADC1, 3u,  ADC1_CHANNEL_3_INTRPT,  ADC1_CHANNEL_3_ADCH);
#endif
#if(ADC1_CHANNEL_4 == ENABLE)
    ADCn_SC1_CHx(ADC1, 4u,  ADC1_CHANNEL_4_INTRPT,  ADC1_CHANNEL_4_ADCH);
#endif
#if(ADC1_CHANNEL_5 == ENABLE)
    ADCn_SC1_CHx(ADC1, 5u,  ADC1_CHANNEL_5_INTRPT,  ADC1_CHANNEL_5_ADCH);
#endif
#if(ADC1_CHANNEL_6 == ENABLE)
    ADCn_SC1_CHx(ADC1, 6u,  ADC1_CHANNEL_6_INTRPT,  ADC1_CHANNEL_6_ADCH);
#endif
#if(ADC1_CHANNEL_7 == ENABLE)
    ADCn_SC1_CHx(ADC1, 7u,  ADC1_CHANNEL_7_INTRPT,  ADC1_CHANNEL_7_ADCH);
#endif
#if(ADC1_CHANNEL_8 == ENABLE)
    ADCn_SC1_CHx(ADC1, 8u,  ADC1_CHANNEL_8_INTRPT,  ADC1_CHANNEL_8_ADCH);
#endif
#if(ADC1_CHANNEL_9 == ENABLE)
    ADCn_SC1_CHx(ADC1, 9u,  ADC1_CHANNEL_9_INTRPT,  ADC1_CHANNEL_9_ADCH);
#endif
#if(ADC1_CHANNEL_10 == ENABLE)
    ADCn_SC1_CHx(ADC1, 10u, ADC1_CHANNEL_10_INTRPT, ADC1_CHANNEL_10_ADCH);
#endif
#if(ADC1_CHANNEL_11 == ENABLE)
    ADCn_SC1_CHx(ADC1, 11u, ADC1_CHANNEL_11_INTRPT, ADC1_CHANNEL_11_ADCH);
#endif
#if(ADC1_CHANNEL_12 == ENABLE)
    ADCn_SC1_CHx(ADC1, 12u, ADC1_CHANNEL_12_INTRPT, ADC1_CHANNEL_12_ADCH);
#endif
#if(ADC1_CHANNEL_13 == ENABLE)
    ADCn_SC1_CHx(ADC1, 13u, ADC1_CHANNEL_13_INTRPT, ADC1_CHANNEL_13_ADCH);
#endif
#if(ADC1_CHANNEL_14 == ENABLE)
    ADCn_SC1_CHx(ADC1, 14u, ADC1_CHANNEL_14_INTRPT, ADC1_CHANNEL_14_ADCH);
#endif
#if(ADC1_CHANNEL_15 == ENABLE)
    ADCn_SC1_CHx(ADC1, 15u, ADC1_CHANNEL_15_INTRPT, ADC1_CHANNEL_15_ADCH);
#endif

    /* Configure SC2: trigger, compare, DMA, reference voltage              */
    ADCn_SC2_CHx(ADC1,
                 ADC1_CONV_TRIGSEL,
                 ADC1_COMPFUNCTION,
                 ADC1_COMP_GREATER,
                 ADC1_COMP_RANGE,
                 ADC1_DMA_ACCESS,
                 ADC1_REFVTGSELECT_CFG);

    /* Configure SC3: continuous conversion, hardware averaging             */
    ADCn_SC3_CHx(ADC1,
                 ADC1_CONTI_CONV,
                 ADC1_HW_AVG_CFG,
                 ADC1_HW_AVG_SEL);
}

/*---------------------------------------------------------------------------
 * ADC1_IRQHandler
 *
 * ADC1 conversion complete interrupt handler.
 * TODO: Read result register and store in application buffer.
 * Dev Note: Function name from IV table -- startup_S32K144.S
 *--------------------------------------------------------------------------*/
void INTERRUPT_ ADC1_IRQHandler(void)
{
    /* TODO: Read ADC1->R[0] and store result                               */
}

#endif /* ADC1_MODULE */
