/*
 * FTMn_Core.c
 *
 *  Created on: 16-Nov-2020
 *      Author: HP
 */


#include "Headers.h"

/* Global variables*/

static	uint32	u32FTM1Counter_1ms 	=	0;




/* Function body from here*/

void	FTMn_Init(void)
{


#if(ENABLE == FTM0_TIMER_CFG)

	FTM0_Init();

#endif

#if(ENABLE == FTM1_TIMER_CFG)

	FTM1_Init();

#endif

#if(ENABLE == FTM2_TIMER_CFG)

	FTM2_Init();

#endif

#if(ENABLE == FTM3_TIMER_CFG)

	FTM3_Init();

#endif

#if(ENABLE == FTM4_TIMER_CFG)

	FTM4_Init();

#endif

#if(ENABLE == FTM5_TIMER_CFG)

	FTM5_Init();

#endif

#if(ENABLE == FTM6_TIMER_CFG)

	FTM6_Init();

#endif

#if(ENABLE == FTM7_TIMER_CFG)

	FTM7_Init();

#endif

}






#if(ENABLE == FTM0_TIMER_CFG)

void	FTM0_Init(void)
{

	/* Clock initialization : TBD*/
	PCC->PCCn[PCC_FTM0_INDEX] &= ~PCC_PCCn_CGC_MASK; 	/* Ensure clk disabled for config 	*/

	PCC->PCCn[PCC_FTM0_INDEX] |= (PCC_PCCn_PCS(0b010)|  PCC_PCCn_CGC_MASK);/* Clock Src=1, 8 MHz SIRCDIV1_CLK */



	/* FTM0 Initialization*/
	FTMn_CNTINT(	FTM0,							\
					FTM0_INIT_CNT	);



	FTMn_MODE(	FTM0,								\
				FTM0_MODE_FAULT_INTRP_EN,			\
				FTM0_MODE_FAULT_MODE,				\
				FTM0_MODE_CAPTURE_TEST,				\
				FTM0_MODE_PWMSYNC,					\
				FTM0_MODE_WRITE_PROTECT,			\
				FTM0_MODE_INIT_OUTINTREG,			\
				FTM0_MODE_TPM_COMPACT_EN				);


	FTMn_COMBINE_CTRL(	FTM0,						\
						FTM0_COMBINE_MCOMBINE3,		\
						FTM0_COMBINE_FAULTEN3,		\
						FTM0_COMBINE_SYNCEN3,		\
						FTM0_COMBINE_DTEN3,			\
						FTM0_COMBINE_DECAP3	,		\
						FTM0_COMBINE_DECAPEN3,		\
						FTM0_COMBINE_COMP3,			\
						FTM0_COMBINE_COMBINE3,		\
						FTM0_COMBINE_MCOMBINE2,		\
						FTM0_COMBINE_FAULTEN2,		\
						FTM0_COMBINE_SYNCEN2,		\
						FTM0_COMBINE_DTEN2,			\
						FTM0_COMBINE_DECAP2,		\
						FTM0_COMBINE_DECAPEN2,		\
						FTM0_COMBINE_COMP2,			\
						FTM0_COMBINE_COMBINE2,		\
						FTM0_COMBINE_MCOMBINE1,		\
						FTM0_COMBINE_FAULTEN1,		\
						FTM0_COMBINE_SYNCEN1,		\
						FTM0_COMBINE_DTEN1,			\
						FTM0_COMBINE_DECAP1,		\
						FTM0_COMBINE_DECAPEN1,		\
						FTM0_COMBINE_COMP1,			\
						FTM0_COMBINE_COMBINE1,		\
						FTM0_COMBINE_MCOMBINE0,		\
						FTM0_COMBINE_FAULTEN0,		\
						FTM0_COMBINE_SYNCEN0,		\
						FTM0_COMBINE_DTEN0,			\
						FTM0_COMBINE_DECAP0,		\
						FTM0_COMBINE_DECAPEN0,		\
						FTM0_COMBINE_COMP0,			\
						FTM0_COMBINE_COMBINE0	);


	FTMn_POL_CTRL(	FTM0,							\
					FTM0_CH0_POLARITY,				\
					FTM0_CH1_POLARITY,				\
					FTM0_CH2_POLARITY,				\
					FTM0_CH3_POLARITY,				\
					FTM0_CH4_POLARITY,				\
					FTM0_CH5_POLARITY,				\
					FTM0_CH6_POLARITY,				\
					FTM0_CH7_POLARITY	);

	FTMn_MOD_CTRL(	FTM0,							\
					FTM0_CHx_MODULO_VAL	);


	FTMn_OUTINT(	FTM0,				\
					FTM0_CH0_INITVAL,	\
					FTM0_CH1_INITVAL,	\
					FTM0_CH2_INITVAL,	\
					FTM0_CH3_INITVAL,	\
					FTM0_CH4_INITVAL,	\
					FTM0_CH5_INITVAL,	\
					FTM0_CH6_INITVAL,	\
					FTM0_CH7_INITVAL	);


	FTMn_SYNCCONF(	FTM0,						\
					FTM0_SYNCCONF_HWTRIGMODE,	\
					FTM0_SYNCCONF_CNTINC,		\
					FTM0_SYNCCONF_INVC,			\
					FTM0_SYNCCONF_SWOC,			\
					FTM0_SYNCCONF_SYNCMODE,		\
					FTM0_SYNCCONF_SWRSTCNT,		\
					FTM0_SYNCCONF_SWWRBUF,		\
					FTM0_SYNCCONF_SWOM,			\
					FTM0_SYNCCONF_SWINVC,		\
					FTM0_SYNCCONF_SWSOC,		\
					FTM0_SYNCCONF_HWRSCNT,		\
					FTM0_SYNCCONF_HWWRBUF,		\
					FTM0_SYNCCONF_HWOM,			\
					FTM0_SYNCCONF_HWINVC,		\
					FTM0_SYNCCONF_HWSOC		);


#if(ENABLE	==	FTM0_SC_PWMCH0)

	FTMn_CnSC(	  FTM0,						\
				  0u,						\
				  FTM0_C0SC_TRIG_MODE,		\
				  FTM0_C0SC_CHL_INTRT,		\
				  FTM0_C0SC_MSB,			\
				  FTM0_C0SC_MSA,			\
				  FTM0_C0SC_ELSB,			\
				  FTM0_C0SC_ELSA,			\
				  FTM0_C0SC_COUNT_RST_IC,	\
				  FTM0_C0SC_DMA);
#endif

#if(ENABLE	==	FTM0_SC_PWMCH1)

	FTMn_CnSC(	  FTM0,						\
				  1u,						\
				  FTM0_C1SC_TRIG_MODE,		\
				  FTM0_C1SC_CHL_INTRT,		\
				  FTM0_C1SC_MSB,			\
				  FTM0_C1SC_MSA,			\
				  FTM0_C1SC_ELSB,			\
				  FTM0_C1SC_ELSA,			\
				  FTM0_C1SC_COUNT_RST_IC,	\
				  FTM0_C1SC_DMA);
#endif


#if(ENABLE	==	FTM0_SC_PWMCH2)

	FTMn_CnSC(	  FTM0,						\
				  2u,						\
				  FTM0_C2SC_TRIG_MODE,		\
				  FTM0_C2SC_CHL_INTRT,		\
				  FTM0_C2SC_MSB,			\
				  FTM0_C2SC_MSA,			\
				  FTM0_C2SC_ELSB,			\
				  FTM0_C2SC_ELSA,			\
				  FTM0_C2SC_COUNT_RST_IC,	\
				  FTM0_C2SC_DMA);

#endif

#if(ENABLE	==	FTM0_SC_PWMCH3)

	FTMn_CnSC(	  FTM0,						\
				  3u,						\
				  FTM0_C3SC_TRIG_MODE,		\
				  FTM0_C3SC_CHL_INTRT,		\
				  FTM0_C3SC_MSB,			\
				  FTM0_C3SC_MSA,			\
				  FTM0_C3SC_ELSB,			\
				  FTM0_C3SC_ELSA,			\
				  FTM0_C3SC_COUNT_RST_IC,	\
				  FTM0_C3SC_DMA);

#endif

#if(ENABLE	==	FTM0_SC_PWMCH4)

	FTMn_CnSC(	  FTM0,						\
				  4u,						\
				  FTM0_C4SC_TRIG_MODE,		\
				  FTM0_C4SC_CHL_INTRT,		\
				  FTM0_C4SC_MSB,			\
				  FTM0_C4SC_MSA,			\
				  FTM0_C4SC_ELSB,			\
				  FTM0_C4SC_ELSA,			\
				  FTM0_C4SC_COUNT_RST_IC,	\
				  FTM0_C4SC_DMA);

#endif

#if(ENABLE	==	FTM0_SC_PWMCH5)

	FTMn_CnSC(	  FTM0,						\
				  5u,						\
				  FTM0_C5SC_TRIG_MODE,		\
				  FTM0_C5SC_CHL_INTRT,		\
				  FTM0_C5SC_MSB,			\
				  FTM0_C5SC_MSA,			\
				  FTM0_C5SC_ELSB,			\
				  FTM0_C5SC_ELSA,			\
				  FTM0_C5SC_COUNT_RST_IC,	\
				  FTM0_C5SC_DMA);

#endif

#if(ENABLE	==	FTM0_SC_PWMCH6)

	FTMn_CnSC(	  FTM0,						\
				  6u,						\
				  FTM0_C6SC_TRIG_MODE,		\
				  FTM0_C6SC_CHL_INTRT,		\
				  FTM0_C6SC_MSB,			\
				  FTM0_C6SC_MSA,			\
				  FTM0_C6SC_ELSB,			\
				  FTM0_C6SC_ELSA,			\
				  FTM0_C6SC_COUNT_RST_IC,	\
				  FTM0_C6SC_DMA);
#endif

#if(ENABLE	==	FTM0_SC_PWMCH7)

	FTMn_CnSC(	  FTM0,						\
				  7u,						\
				  FTM0_C7SC_TRIG_MODE,		\
				  FTM0_C7SC_CHL_INTRT,		\
				  FTM0_C7SC_MSB,			\
				  FTM0_C7SC_MSA,			\
				  FTM0_C7SC_ELSB,			\
				  FTM0_C7SC_ELSA,			\
				  FTM0_C7SC_COUNT_RST_IC,	\
				  FTM0_C7SC_DMA);
#endif

FTMn_SC_CTRL(	FTM0,							\
					FTM0_SC_FILTER_PS,				\
					FTM0_SC_PWMCH0,					\
					FTM0_SC_PWMCH1,					\
					FTM0_SC_PWMCH2,					\
					FTM0_SC_PWMCH3,					\
					FTM0_SC_PWMCH4,					\
					FTM0_SC_PWMCH5,					\
					FTM0_SC_PWMCH6,					\
					FTM0_SC_PWMCH7,					\
					FTM0_SC_TIMER_FLW_INTR,			\
					FTM0_SC_RELOAD_FLG,				\
					FTM0_SC_RELOAD_INTRPT,			\
					FTM0_SC_CENTER_ALIGN_PWM,		\
					FTM0_SC_CLK_SRC_SEL,			\
					FTM0_SC_PRESCALE_FACTOR);





}

#endif

#if(ENABLE == FTM1_TIMER_CFG)

void	FTM1_Init(void)
{

	/* Clock initialization : TBD*/
	PCC->PCCn[PCC_FTM1_INDEX] &= ~PCC_PCCn_CGC_MASK; 	/* Ensure clk disabled for config 	*/

	PCC->PCCn[PCC_FTM1_INDEX] |= PCC_PCCn_PCS(0b010)	/* Clock Src=1, 8 MHz SIRCDIV1_CLK */
                              |  PCC_PCCn_CGC_MASK;


	/* FTM1 Initialization*/
	FTMn_CNTINT(	FTM1,							\
					FTM1_INIT_CNT	);



	FTMn_MODE(	FTM1,								\
				FTM1_MODE_FAULT_INTRP_EN,			\
				FTM1_MODE_FAULT_MODE,				\
				FTM1_MODE_CAPTURE_TEST,				\
				FTM1_MODE_PWMSYNC,					\
				FTM1_MODE_WRITE_PROTECT,			\
				FTM1_MODE_INIT_OUTINTREG,			\
				FTM1_MODE_TPM_COMPACT_EN				);


	FTMn_COMBINE_CTRL(	FTM1,						\
						FTM1_COMBINE_MCOMBINE3,		\
						FTM1_COMBINE_FAULTEN3,		\
						FTM1_COMBINE_SYNCEN3,		\
						FTM1_COMBINE_DTEN3,			\
						FTM1_COMBINE_DECAP3	,		\
						FTM1_COMBINE_DECAPEN3,		\
						FTM1_COMBINE_COMP3,			\
						FTM1_COMBINE_COMBINE3,		\
						FTM1_COMBINE_MCOMBINE2,		\
						FTM1_COMBINE_FAULTEN2,		\
						FTM1_COMBINE_SYNCEN2,		\
						FTM1_COMBINE_DTEN2,			\
						FTM1_COMBINE_DECAP2,		\
						FTM1_COMBINE_DECAPEN2,		\
						FTM1_COMBINE_COMP2,			\
						FTM1_COMBINE_COMBINE2,		\
						FTM1_COMBINE_MCOMBINE1,		\
						FTM1_COMBINE_FAULTEN1,		\
						FTM1_COMBINE_SYNCEN1,		\
						FTM1_COMBINE_DTEN1,			\
						FTM1_COMBINE_DECAP1,		\
						FTM1_COMBINE_DECAPEN1,		\
						FTM1_COMBINE_COMP1,			\
						FTM1_COMBINE_COMBINE1,		\
						FTM1_COMBINE_MCOMBINE0,		\
						FTM1_COMBINE_FAULTEN0,		\
						FTM1_COMBINE_SYNCEN0,		\
						FTM1_COMBINE_DTEN0,			\
						FTM1_COMBINE_DECAP0,		\
						FTM1_COMBINE_DECAPEN0,		\
						FTM1_COMBINE_COMP0,			\
						FTM1_COMBINE_COMBINE0	);


	FTMn_POL_CTRL(	FTM1,							\
					FTM1_CH0_POLARITY,				\
					FTM1_CH1_POLARITY,				\
					FTM1_CH2_POLARITY,				\
					FTM1_CH3_POLARITY,				\
					FTM1_CH4_POLARITY,				\
					FTM1_CH5_POLARITY,				\
					FTM1_CH6_POLARITY,				\
					FTM1_CH7_POLARITY	);

	FTMn_MOD_CTRL(	FTM1,							\
					FTM1_CH0_MODULO_VAL	);


	FTMn_OUTINT(	FTM1,				\
					FTM1_CH0_INITVAL,	\
					FTM1_CH1_INITVAL,	\
					FTM1_CH2_INITVAL,	\
					FTM1_CH3_INITVAL,	\
					FTM1_CH4_INITVAL,	\
					FTM1_CH5_INITVAL,	\
					FTM1_CH6_INITVAL,	\
					FTM1_CH7_INITVAL	);

	FTMn_SYNCCONF(	FTM1,						\
						FTM1_SYNCCONF_HWTRIGMODE,	\
						FTM1_SYNCCONF_CNTINC,		\
						FTM1_SYNCCONF_INVC,			\
						FTM1_SYNCCONF_SWOC,			\
						FTM1_SYNCCONF_SYNCMODE,		\
						FTM1_SYNCCONF_SWRSTCNT,		\
						FTM1_SYNCCONF_SWWRBUF,		\
						FTM1_SYNCCONF_SWOM,			\
						FTM1_SYNCCONF_SWINVC,		\
						FTM1_SYNCCONF_SWSOC,		\
						FTM1_SYNCCONF_HWRSCNT,		\
						FTM1_SYNCCONF_HWWRBUF,		\
						FTM1_SYNCCONF_HWOM,			\
						FTM1_SYNCCONF_HWINVC,		\
						FTM1_SYNCCONF_HWSOC		);


#if(ENABLE	==	FTM1_SC_PWMCH0|	\
				FTM1_SC_PWMCH1|	\
				FTM1_SC_PWMCH2|	\
				FTM1_SC_PWMCH3|	\
				FTM1_SC_PWMCH4|	\
				FTM1_SC_PWMCH5|	\
				FTM1_SC_PWMCH6|	\
				FTM1_SC_PWMCH7)

	FTMn_CnSC(	  FTM1,						\
				  0u,						\
				  FTM1_C0SC_TRIG_MODE,		\
				  FTM1_C0SC_CHL_INTRT,		\
				  FTM1_C0SC_MSB,			\
				  FTM1_C0SC_MSA,			\
				  FTM1_C0SC_ELSB,			\
				  FTM1_C0SC_ELSA,			\
				  FTM1_C0SC_COUNT_RST_IC,	\
				  FTM1_C0SC_DMA);



	FTMn_CnSC(	  FTM1,						\
				  1u,						\
				  FTM1_C1SC_TRIG_MODE,		\
				  FTM1_C1SC_CHL_INTRT,		\
				  FTM1_C1SC_MSB,			\
				  FTM1_C1SC_MSA,			\
				  FTM1_C1SC_ELSB,			\
				  FTM1_C1SC_ELSA,			\
				  FTM1_C1SC_COUNT_RST_IC,	\
				  FTM1_C1SC_DMA);



#endif


	FTMn_SC_CTRL(	FTM1,							\
						FTM1_SC_FILTER_PS,				\
						FTM1_SC_PWMCH0,					\
						FTM1_SC_PWMCH1,					\
						FTM1_SC_PWMCH2,					\
						FTM1_SC_PWMCH3,					\
						FTM1_SC_PWMCH4,					\
						FTM1_SC_PWMCH5,					\
						FTM1_SC_PWMCH6,					\
						FTM1_SC_PWMCH7,					\
						FTM1_SC_TIMER_FLW_INTR,			\
						FTM1_SC_RELOAD_FLG,				\
						FTM1_SC_RELOAD_INTRPT,			\
						FTM1_SC_CENTER_ALIGN_PWM,		\
						FTM1_SC_CLK_SRC_SEL,			\
						FTM1_SC_PRESCALE_FACTOR);



}

#endif

#if(ENABLE == FTM2_TIMER_CFG)

void	FTM2_Init(void)
{

}

#endif

#if(ENABLE == FTM3_TIMER_CFG)

void	FTM3_Init(void)
{

}

#endif

#if(ENABLE == FTM4_TIMER_CFG)

void	FTM4_Init(void)
{

}

#endif

#if(ENABLE == FTM5_TIMER_CFG)

void	FTM5_Init(void)
{

}

#endif

#if(ENABLE == FTM6_TIMER_CFG)

void	FTM6_Init(void)
{

}

#endif

#if(ENABLE == FTM7_TIMER_CFG)

void	FTM7_Init(void)
{

}

#endif



uint8 FTMn_CHn_SetDuty(FTM_Type		*LstTimerNumber,	uint8 u8Duty,	uint8	u8ChlNo)
{
	uint8 	u8RetVal 		= NOK;
	uint16 	u16CompareCnt 	= 0u;

	if(u8Duty 	<= 	100		&&	\
	  (u8ChlNo	<	8	)	)
	{
		u16CompareCnt = (FTM0_CHx_MODULO_VAL/100) * u8Duty;
		/* Formula: Compare count = (	1% of Final count * Duty Requested )	*/

		FTMn_CHn_SET_COMPARE_COUNT(LstTimerNumber,	u8ChlNo,	u16CompareCnt);

		u8RetVal = OK;

	}
	else
	{
		u8RetVal = NOK;
	}

	return u8RetVal;
}

/* FTM0 Channel 0 -1 Compare match interrupt*/

void 	INTERRUPT_	FTM0_Ch0_Ch1_IRQHandler(void)/* Dev Note 15. Function name: 	From IV - Table Library -> Startup_S32K144.S	*/
{

	uint8 u8Status = 0;

	//uint16	u16

	u8Status = FTMn_CHn_FETCH_CHF_FLG(FTM0,	0u); 	/* Ch0*/

	switch(u8Status)
	{

		case TRUE:
		FTMn_CHn_CLEAR_CHF_FLG(FTM0,	0u);
		break;

		case FALSE:
		default:
		break;
	}

	u8Status = FTMn_CHn_FETCH_CHF_FLG(FTM0,	1u);	/* Ch1*/

	switch(u8Status)
	{

		case TRUE:
		FTMn_CHn_CLEAR_CHF_FLG(FTM0,	1u);
		break;

		case FALSE:
		default:
		break;
	}


}

void 	INTERRUPT_	FTM0_Ch2_Ch3_IRQHandler(void)/* Dev Note 15. Function name: 	From IV - Table Library -> Startup_S32K144.S	*/
{

	uint8 u8Status = 0;

	u8Status = FTMn_CHn_FETCH_CHF_FLG(FTM0,	2u); 	/* Ch0*/

	switch(u8Status)
	{

		case TRUE:
		FTMn_CHn_CLEAR_CHF_FLG(FTM0,	2u);
		break;

		case FALSE:
		default:
		break;
	}

	u8Status = FTMn_CHn_FETCH_CHF_FLG(FTM0,	3u);	/* Ch1*/

	switch(u8Status)
	{

		case TRUE:
		FTMn_CHn_CLEAR_CHF_FLG(FTM0,	3u);
		break;

		case FALSE:
		default:
		break;
	}


}

void	INTERRUPT_	FTM0_Ovf_Reload_IRQHandler(void)
{

	if(TRUE	==	FTMn_FETCH_TIMEROVFLG(FTM0)	)
	{
//		FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, geLedSel, u16Duty); //Temp Debug code
		FTMn_CLEAR_TIMEROVFLG(FTM0);
	}
	else
	{

	}

	if(	FTM0_INIT_CNT == FTMn_FETCH_MODVAL(FTM0)	)
	{
//		FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, geLedSel, u16Duty);//Temp Debug code
	}
}

void INTERRUPT_ FTM1_Ovf_Reload_IRQHandler(void)
{

	if(TRUE	==	FTMn_FETCH_TIMEROVFLG(FTM1)	)
	{
		FTMn_CLEAR_TIMEROVFLG(FTM1);
	}
	else
	{

	}

	u32FTM1Counter_1ms++;

}



uint32	TIMER_SetDelay(uint32	u32Input)
{

	uint32 u32Retval = 0;

	u32Retval = u32Input + u32FTM1Counter_1ms;

	if(u32Retval < u32Input)
	{
		u32Retval = u32Input;
	}
	else
	{

	}

	return u32Retval;
}

uint8	TIMER_IsDelayExpired(uint32	u32Output)
{
	uint8 u8Retval = 0;

	if(u32Output <= u32FTM1Counter_1ms)
	{
		u8Retval = TRUE;
	}
	else
	{
		u8Retval = FALSE;
	}

	return u8Retval;
}


