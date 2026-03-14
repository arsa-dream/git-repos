/*
 * ADC_Core.c
 *
 *  Created on: 06-Dec-2020
 *      Author: HP
 */


#include	"Headers.h"


/*********************************Function definitions start here************************/
void	ADC_Init(void)
{

#if(ENABLE	==	ADC0_MODULE)

	ADC0_Init();

#endif

#if(ENABLE	==	ADC1_MODULE)

	ADC1_Init();

#endif

}


#if(ENABLE	==	ADC0_MODULE)

void	ADC0_Init(void)
{

	PCC->PCCn[PCC_ADC0_INDEX] &=~ PCC_PCCn_CGC_MASK;  /* Disable clock to change PCS */
	PCC->PCCn[PCC_ADC0_INDEX] |= PCC_PCCn_PCS(1);     /* PCS=1: Select SOSCDIV2 		*/
	PCC->PCCn[PCC_ADC0_INDEX] |= PCC_PCCn_CGC_MASK;   /* Enable bus clock in ADC 	*/

	/*!
	 * ADC0 Initialization:
	 * ===================================================
	 */
	ADC0->SC1[0] |= ADC_SC1_ADCH_MASK;	/* ADCH=1F: Module is disabled for conversions	*/
										/* AIEN=0: Interrupts are disabled 			*/


	ADCn_CFG1(	ADC0,					\
				ADC0_CFG1_ADIV_DIV,		\
				ADC0_CFG1_MODE_DIV,		\
				ADC0_CFG1_ADICLK);	// Check Clk 1 meaning

	ADCn_CFG2(	ADC0,					\
				ADC1_CFG2_SAMPLERATE	);


#if(ENABLE	==	ADC0_CHANNEL_0)

	ADCn_SC1_CHx(	ADC0,					\
					0u,						\
					ADC0_CHANNEL_0_INTRPT,	\
					ADC0_CHANNEL_0_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_1)

	ADCn_SC1_CHx(	ADC0,					\
					1u,						\
					ADC0_CHANNEL_1_INTRPT,	\
					ADC0_CHANNEL_1_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_2)

	ADCn_SC1_CHx(	ADC0,					\
					2u,						\
					ADC0_CHANNEL_2_INTRPT,	\
					ADC0_CHANNEL_2_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_3)

	ADCn_SC1_CHx(	ADC0,					\
					3u,						\
					ADC0_CHANNEL_3_INTRPT,	\
					ADC0_CHANNEL_3_ADCH);
#endif

#if(ENABLE	==	ADC0_CHANNEL_4)

	ADCn_SC1_CHx(	ADC0,					\
					4u,						\
					ADC0_CHANNEL_4_INTRPT,	\
					ADC0_CHANNEL_4_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_5)

	ADCn_SC1_CHx(	ADC0,					\
					5u,						\
					ADC0_CHANNEL_5_INTRPT,	\
					ADC0_CHANNEL_5_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_6)

	ADCn_SC1_CHx(	ADC0,					\
					6u,						\
					ADC0_CHANNEL_6_INTRPT,	\
					ADC0_CHANNEL_6_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_7)

	ADCn_SC1_CHx(	ADC0,					\
					7u,						\
					ADC0_CHANNEL_7_INTRPT,	\
					ADC0_CHANNEL_7_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_8)

	ADCn_SC1_CHx(	ADC0,					\
					8u,						\
					ADC0_CHANNEL_8_INTRPT,	\
					ADC0_CHANNEL_8_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_9)

	ADCn_SC1_CHx(	ADC0,					\
					9u,						\
					ADC0_CHANNEL_9_INTRPT,	\
					ADC0_CHANNEL_9_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_10)

	ADCn_SC1_CHx(	ADC0,					\
					10u,					\
					ADC0_CHANNEL_10_INTRPT,	\
					ADC0_CHANNEL_10_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_11)

	ADCn_SC1_CHx(	ADC0,					\
					11u,					\
					ADC0_CHANNEL_11_INTRPT,	\
					ADC0_CHANNEL_11_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_12)

	ADCn_SC1_CHx(	ADC0,					\
					12u,					\
					ADC0_CHANNEL_12_INTRPT,	\
					ADC0_CHANNEL_12_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_13)

	ADCn_SC1_CHx(	ADC0,					\
					13u,					\
					ADC0_CHANNEL_13_INTRPT,	\
					ADC0_CHANNEL_13_ADCH);

#endif

#if(ENABLE	==	ADC0_CHANNEL_14)

	ADCn_SC1_CHx(	ADC0,					\
					14u,					\
					ADC0_CHANNEL_14_INTRPT,	\
					ADC0_CHANNEL_14_ADCH);
#endif

#if(ENABLE	==	ADC0_CHANNEL_15)

	ADCn_SC1_CHx(	ADC0,					\
					15u,					\
					ADC0_CHANNEL_15_INTRPT,	\
					ADC0_CHANNEL_15_ADCH);

#endif


	ADCn_SC2_CHx(	ADC0,					\
					ADC0_CONV_TRIGSEL,		\
					ADC0_COMPFUNCTION,		\
					ADC0_COMP_GREATER,		\
					ADC0_COMP_RANGE,		\
					ADC0_DMA_ACCESS,		\
					ADC0_REFVTGSELECT_CFG);

	ADCn_SC3_CHx(	ADC0,	\
					ADC0_CONTI_CONV,	\
					ADC0_HW_AVG_CFG,	\
					ADC0_HW_AVG_SEL	);

}


void	INTERRUPT_	ADC0_IRQHandler(void)
{

}

#endif

#if(ENABLE	==	ADC1_MODULE)

void	ADC1_Init(void)
{
	PCC->PCCn[PCC_ADC1_INDEX] &=~ PCC_PCCn_CGC_MASK;  /* Disable clock to change PCS */
	PCC->PCCn[PCC_ADC1_INDEX] |= PCC_PCCn_PCS(1);     /* PCS=1: Select SOSCDIV2 		*/
	PCC->PCCn[PCC_ADC1_INDEX] |= PCC_PCCn_CGC_MASK;   /* Enable bus clock in ADC 	*/

	/*!
	 * ADC0 Initialization:
	 * ===================================================
	 */
	ADC1->SC1[0] |= ADC_SC1_ADCH_MASK;	/* ADCH=1F: Module is disabled for conversions	*/
										/* AIEN=0: Interrupts are disabled 			*/


	ADCn_CFG1(	ADC1,					\
				ADC1_CFG1_ADIV_DIV,		\
				ADC1_CFG1_MODE_DIV,		\
				ADC1_CFG1_ADICLK);	// Check Clk 1 meaning

	ADCn_CFG2(	ADC1,					\
				ADC1_CFG2_SAMPLERATE	);


#if(ENABLE	==	ADC1_CHANNEL_0)

	ADCn_SC1_CHx(	ADC1,					\
					0u,						\
					ADC1_CHANNEL_0_INTRPT,	\
					ADC1_CHANNEL_0_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_1)

	ADCn_SC1_CHx(	ADC1,					\
					1u,						\
					ADC1_CHANNEL_1_INTRPT,	\
					ADC1_CHANNEL_1_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_2)

	ADCn_SC1_CHx(	ADC1,					\
					2u,						\
					ADC1_CHANNEL_2_INTRPT,	\
					ADC1_CHANNEL_2_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_3)

	ADCn_SC1_CHx(	ADC1,					\
					3u,						\
					ADC1_CHANNEL_3_INTRPT,	\
					ADC1_CHANNEL_3_ADCH);
#endif

#if(ENABLE	==	ADC1_CHANNEL_4)

	ADCn_SC1_CHx(	ADC1,					\
					4u,						\
					ADC1_CHANNEL_4_INTRPT,	\
					ADC1_CHANNEL_4_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_5)

	ADCn_SC1_CHx(	ADC1,					\
					5u,						\
					ADC1_CHANNEL_5_INTRPT,	\
					ADC1_CHANNEL_5_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_6)

	ADCn_SC1_CHx(	ADC1,					\
					6u,						\
					ADC1_CHANNEL_6_INTRPT,	\
					ADC1_CHANNEL_6_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_7)

	ADCn_SC1_CHx(	ADC1,					\
					7u,						\
					ADC1_CHANNEL_7_INTRPT,	\
					ADC1_CHANNEL_7_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_8)

	ADCn_SC1_CHx(	ADC1,					\
					8u,						\
					ADC1_CHANNEL_8_INTRPT,	\
					ADC1_CHANNEL_8_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_9)

	ADCn_SC1_CHx(	ADC1,					\
					9u,						\
					ADC1_CHANNEL_9_INTRPT,	\
					ADC1_CHANNEL_9_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_10)

	ADCn_SC1_CHx(	ADC1,					\
					10u,					\
					ADC1_CHANNEL_10_INTRPT,	\
					ADC1_CHANNEL_10_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_11)

	ADCn_SC1_CHx(	ADC1,					\
					11u,					\
					ADC1_CHANNEL_11_INTRPT,	\
					ADC1_CHANNEL_11_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_12)

	ADCn_SC1_CHx(	ADC1,					\
					12u,					\
					ADC1_CHANNEL_12_INTRPT,	\
					ADC1_CHANNEL_12_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_13)

	ADCn_SC1_CHx(	ADC1,					\
					13u,					\
					ADC1_CHANNEL_13_INTRPT,	\
					ADC1_CHANNEL_13_ADCH);

#endif

#if(ENABLE	==	ADC1_CHANNEL_14)

	ADCn_SC1_CHx(	ADC1,					\
					14u,					\
					ADC1_CHANNEL_14_INTRPT,	\
					ADC1_CHANNEL_14_ADCH);
#endif

#if(ENABLE	==	ADC1_CHANNEL_15)

	ADCn_SC1_CHx(	ADC1,					\
					15u,					\
					ADC1_CHANNEL_15_INTRPT,	\
					ADC1_CHANNEL_15_ADCH);

#endif


	ADCn_SC2_CHx(	ADC1,					\
					ADC1_CONV_TRIGSEL,		\
					ADC1_COMPFUNCTION,		\
					ADC1_COMP_GREATER,		\
					ADC1_COMP_RANGE,		\
					ADC1_DMA_ACCESS,		\
					ADC1_REFVTGSELECT_CFG);

	ADCn_SC3_CHx(	ADC1,	\
					ADC1_CONTI_CONV,	\
					ADC1_HW_AVG_CFG,	\
					ADC1_HW_AVG_SEL	);

}


void	INTERRUPT_	ADC1_IRQHandler(void)
{

}

#endif
