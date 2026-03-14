/*
 * FTMn_Cfg.h
 *
 *  Created on: 18-Nov-2020
 *      Author: HP
 */

#ifndef MCAL_FTMN_CFG_H_
#define MCAL_FTMN_CFG_H_


#define 	FTM0_TIMER_CFG													ENABLE
#define 	FTM1_TIMER_CFG													ENABLE
#define 	FTM2_TIMER_CFG													DISABLE
#define 	FTM3_TIMER_CFG													DISABLE
#define 	FTM4_TIMER_CFG													DISABLE
#define 	FTM5_TIMER_CFG													DISABLE
#define 	FTM6_TIMER_CFG													DISABLE
#define 	FTM7_TIMER_CFG													DISABLE

#if(ENABLE == FTM0_TIMER_CFG)

#define		FTM0_COMBINE_MCOMBINE3											DISABLE
#define		FTM0_COMBINE_FAULTEN3											DISABLE
#define		FTM0_COMBINE_SYNCEN3											DISABLE
#define		FTM0_COMBINE_DTEN3												DISABLE
#define		FTM0_COMBINE_DECAP3												DISABLE
#define		FTM0_COMBINE_DECAPEN3											DISABLE
#define		FTM0_COMBINE_COMP3												DISABLE
#define		FTM0_COMBINE_COMBINE3											DISABLE
#define		FTM0_COMBINE_MCOMBINE2											DISABLE
#define		FTM0_COMBINE_FAULTEN2											DISABLE
#define		FTM0_COMBINE_SYNCEN2											DISABLE
#define		FTM0_COMBINE_DTEN2												DISABLE
#define		FTM0_COMBINE_DECAP2												DISABLE
#define		FTM0_COMBINE_DECAPEN2											DISABLE
#define		FTM0_COMBINE_COMP2												DISABLE
#define		FTM0_COMBINE_COMBINE2											DISABLE
#define		FTM0_COMBINE_MCOMBINE1											DISABLE
#define		FTM0_COMBINE_FAULTEN1											DISABLE
#define		FTM0_COMBINE_SYNCEN1											DISABLE
#define		FTM0_COMBINE_DTEN1												DISABLE
#define		FTM0_COMBINE_DECAP1												DISABLE
#define		FTM0_COMBINE_DECAPEN1											DISABLE
#define		FTM0_COMBINE_COMP1												DISABLE
#define		FTM0_COMBINE_COMBINE1											DISABLE
#define		FTM0_COMBINE_MCOMBINE0											DISABLE
#define		FTM0_COMBINE_FAULTEN0											DISABLE
#define		FTM0_COMBINE_SYNCEN0											DISABLE
#define		FTM0_COMBINE_DTEN0												DISABLE
#define		FTM0_COMBINE_DECAP0												DISABLE
#define		FTM0_COMBINE_DECAPEN0											DISABLE
#define		FTM0_COMBINE_COMP0												DISABLE
#define		FTM0_COMBINE_COMBINE0											DISABLE


#define		FTM0_SYNCCONF_HWTRIGMODE										DISABLE
#define		FTM0_SYNCCONF_CNTINC											DISABLE
#define		FTM0_SYNCCONF_INVC												DISABLE
#define		FTM0_SYNCCONF_SWOC												DISABLE
#define		FTM0_SYNCCONF_SYNCMODE											DISABLE
#define		FTM0_SYNCCONF_SWRSTCNT											DISABLE
#define		FTM0_SYNCCONF_SWWRBUF											DISABLE
#define		FTM0_SYNCCONF_SWOM												DISABLE
#define		FTM0_SYNCCONF_SWINVC											DISABLE
#define		FTM0_SYNCCONF_SWSOC												DISABLE
#define		FTM0_SYNCCONF_HWRSCNT											DISABLE
#define		FTM0_SYNCCONF_HWWRBUF											DISABLE
#define		FTM0_SYNCCONF_HWOM												DISABLE
#define		FTM0_SYNCCONF_HWINVC											DISABLE
#define		FTM0_SYNCCONF_HWSOC												DISABLE

#define		FTM0_CH0_POLARITY												ACTIVE_LOW
#define		FTM0_CH1_POLARITY												ACTIVE_LOW
#define		FTM0_CH2_POLARITY												ACTIVE_LOW
#define		FTM0_CH3_POLARITY												ACTIVE_HI
#define		FTM0_CH4_POLARITY												ACTIVE_HI
#define		FTM0_CH5_POLARITY												ACTIVE_HI
#define		FTM0_CH6_POLARITY												ACTIVE_HI
#define		FTM0_CH7_POLARITY												ACTIVE_HI


/* Mode register values*/
#define 	FTM0_MODE_FAULT_INTRP_EN										DISABLE
#define		FTM0_MODE_FAULT_MODE											FTMn_FAULTMODE_DISABLED
#define		FTM0_MODE_CAPTURE_TEST											DISABLE
#define 	FTM0_MODE_PWMSYNC												DISABLE
#define 	FTM0_MODE_WRITE_PROTECT											DISABLE
#define		FTM0_MODE_INIT_OUTINTREG										ENABLE
#define		FTM0_MODE_TPM_COMPACT_EN										DISABLE

/* Status and control  register values*/
#define 	FTM0_SC_FILTER_PS												FTMn_SC_FILTER_PS_DIV_BY_1
#define 	FTM0_SC_PWMCH0													ENABLE
#define 	FTM0_SC_PWMCH1													ENABLE
#define 	FTM0_SC_PWMCH2													ENABLE
#define 	FTM0_SC_PWMCH3													DISABLE
#define 	FTM0_SC_PWMCH4													DISABLE
#define 	FTM0_SC_PWMCH5													DISABLE
#define 	FTM0_SC_PWMCH6													DISABLE
#define 	FTM0_SC_PWMCH7													DISABLE
#define 	FTM0_SC_TIMER_FLW_INTR											DISABLE
#define 	FTM0_SC_RELOAD_FLG												DISABLE
#define 	FTM0_SC_RELOAD_INTRPT											DISABLE
#define 	FTM0_SC_CENTER_ALIGN_PWM										DISABLE
#define 	FTM0_SC_CLK_SRC_SEL												FTMn_SC_EXT_CLK
#define 	FTM0_SC_PRESCALE_FACTOR											FTMn_SC_PRESCALE_BY_128		/*Allowed values Dev Note 11*/  /*SRCCLK = 8Mhz, Prescaled = 1Mhz, 1 tick 30ms */

#define		FTM0_CH0_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM0_CH1_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM0_CH2_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM0_CH3_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM0_CH4_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM0_CH5_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM0_CH6_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM0_CH7_INITVAL												1u	/* Allowed values 0, 1*/

/* Modulo register value*/
#define		FTM0_CHx_MODULO_VAL												8000u   	/* 1tick 125 ns  ->  8000u * 125ns -> 1ms*/
																						/* Example table */
																						/* 8000u -> 1ms  */
#define		FTM0_INIT_CNT													0x0000u		/*Range 0x0000 - 0xFFFF*/


#if(ENABLE	==	FTM0_SC_PWMCH0)

/* Dev Note 13. Ref manual 1427, For MSA, B and ESLA, B for selection of channel modes */

#define		FTM0_C0SC_TRIG_MODE												DISABLE
#define		FTM0_C0SC_CHL_INTRT												ENABLE
#define		FTM0_C0SC_MSB													ENABLE
#define		FTM0_C0SC_MSA													DISABLE
#define		FTM0_C0SC_ELSB													ENABLE
#define		FTM0_C0SC_ELSA													DISABLE /* Currently its PWM -E Mode*/
#define		FTM0_C0SC_COUNT_RST_IC											DISABLE
#define		FTM0_C0SC_DMA													DISABLE

#endif

#if(ENABLE	==	FTM0_SC_PWMCH1)

#define		FTM0_C1SC_TRIG_MODE												DISABLE
#define		FTM0_C1SC_CHL_INTRT												ENABLE
#define		FTM0_C1SC_MSB													ENABLE
#define		FTM0_C1SC_MSA													DISABLE /* Currently its PWM -E Mode*/
#define		FTM0_C1SC_ELSB													ENABLE
#define		FTM0_C1SC_ELSA													DISABLE
#define		FTM0_C1SC_COUNT_RST_IC											DISABLE
#define		FTM0_C1SC_DMA													DISABLE

#endif

#if(ENABLE	==	FTM0_SC_PWMCH2)

#define		FTM0_C2SC_TRIG_MODE												DISABLE
#define		FTM0_C2SC_CHL_INTRT												ENABLE
#define		FTM0_C2SC_MSB													ENABLE
#define		FTM0_C2SC_MSA													DISABLE /* Currently its PWM -E Mode*/
#define		FTM0_C2SC_ELSB													ENABLE
#define		FTM0_C2SC_ELSA													DISABLE
#define		FTM0_C2SC_COUNT_RST_IC											DISABLE
#define		FTM0_C2SC_DMA													DISABLE

#endif

#if(ENABLE	==	FTM0_SC_PWMCH3)

#define		FTM0_C2SC_TRIG_MODE												DISABLE
#define		FTM0_C2SC_CHL_INTRT												ENABLE
#define		FTM0_C2SC_MSB													ENABLE
#define		FTM0_C2SC_MSA													DISABLE /* Currently its PWM -E Mode*/
#define		FTM0_C2SC_ELSB													ENABLE
#define		FTM0_C2SC_ELSA													DISABLE
#define		FTM0_C2SC_COUNT_RST_IC											DISABLE
#define		FTM0_C2SC_DMA													DISABLE

#endif

#if(ENABLE	==	FTM0_SC_PWMCH4)

#define		FTM0_C3SC_TRIG_MODE												DISABLE
#define		FTM0_C3SC_CHL_INTRT												ENABLE
#define		FTM0_C3SC_MSB													ENABLE
#define		FTM0_C3SC_MSA													DISABLE /* Currently its PWM -E Mode*/
#define		FTM0_C3SC_ELSB													ENABLE
#define		FTM0_C3SC_ELSA													DISABLE
#define		FTM0_C3SC_COUNT_RST_IC											DISABLE
#define		FTM0_C3SC_DMA													DISABLE

#endif

#if(ENABLE	==	FTM0_SC_PWMCH5)

#define		FTM0_C4SC_TRIG_MODE												DISABLE
#define		FTM0_C4SC_CHL_INTRT												ENABLE
#define		FTM0_C4SC_MSB													ENABLE
#define		FTM0_C4SC_MSA													DISABLE /* Currently its PWM -E Mode*/
#define		FTM0_C4SC_ELSB													ENABLE
#define		FTM0_C4SC_ELSA													DISABLE
#define		FTM0_C4SC_COUNT_RST_IC											DISABLE
#define		FTM0_C4SC_DMA													DISABLE

#endif

#if(ENABLE	==	FTM0_SC_PWMCH6)

#define		FTM0_C5SC_TRIG_MODE												DISABLE
#define		FTM0_C5SC_CHL_INTRT												ENABLE
#define		FTM0_C5SC_MSB													ENABLE
#define		FTM0_C5SC_MSA													DISABLE /* Currently its PWM -E Mode*/
#define		FTM0_C5SC_ELSB													ENABLE
#define		FTM0_C5SC_ELSA													DISABLE
#define		FTM0_C5SC_COUNT_RST_IC											DISABLE
#define		FTM0_C5SC_DMA													DISABLE

#endif

#if(ENABLE	==	FTM0_SC_PWMCH7)

#define		FTM0_C6SC_TRIG_MODE												DISABLE
#define		FTM0_C6SC_CHL_INTRT												ENABLE
#define		FTM0_C6SC_MSB													ENABLE
#define		FTM0_C6SC_MSA													DISABLE /* Currently its PWM -E Mode*/
#define		FTM0_C6SC_ELSB													ENABLE
#define		FTM0_C6SC_ELSA													DISABLE
#define		FTM0_C6SC_COUNT_RST_IC											DISABLE
#define		FTM0_C6SC_DMA													DISABLE

#endif

#if(ENABLE	==	FTM0_SC_PWMCH8)

#define		FTM0_C7SC_TRIG_MODE												DISABLE
#define		FTM0_C7SC_CHL_INTRT												ENABLE
#define		FTM0_C7SC_MSB													ENABLE
#define		FTM0_C7SC_MSA													DISABLE /* Currently its PWM -E Mode*/
#define		FTM0_C7SC_ELSB													ENABLE
#define		FTM0_C7SC_ELSA													DISABLE
#define		FTM0_C7SC_COUNT_RST_IC											DISABLE
#define		FTM0_C7SC_DMA													DISABLE

#endif


#endif
/***********************************************************FTM1 Configuration**********************************************************************/

#if(ENABLE == FTM1_TIMER_CFG)

#define		FTM1_COMBINE_MCOMBINE3											DISABLE
#define		FTM1_COMBINE_FAULTEN3											DISABLE
#define		FTM1_COMBINE_SYNCEN3											DISABLE
#define		FTM1_COMBINE_DTEN3												DISABLE
#define		FTM1_COMBINE_DECAP3												DISABLE
#define		FTM1_COMBINE_DECAPEN3											DISABLE
#define		FTM1_COMBINE_COMP3												DISABLE
#define		FTM1_COMBINE_COMBINE3											DISABLE
#define		FTM1_COMBINE_MCOMBINE2											DISABLE
#define		FTM1_COMBINE_FAULTEN2											DISABLE
#define		FTM1_COMBINE_SYNCEN2											DISABLE
#define		FTM1_COMBINE_DTEN2												DISABLE
#define		FTM1_COMBINE_DECAP2												DISABLE
#define		FTM1_COMBINE_DECAPEN2											DISABLE
#define		FTM1_COMBINE_COMP2												DISABLE
#define		FTM1_COMBINE_COMBINE2											DISABLE
#define		FTM1_COMBINE_MCOMBINE1											DISABLE
#define		FTM1_COMBINE_FAULTEN1											DISABLE
#define		FTM1_COMBINE_SYNCEN1											DISABLE
#define		FTM1_COMBINE_DTEN1												DISABLE
#define		FTM1_COMBINE_DECAP1												DISABLE
#define		FTM1_COMBINE_DECAPEN1											DISABLE
#define		FTM1_COMBINE_COMP1												DISABLE
#define		FTM1_COMBINE_COMBINE1											DISABLE
#define		FTM1_COMBINE_MCOMBINE0											DISABLE
#define		FTM1_COMBINE_FAULTEN0											DISABLE
#define		FTM1_COMBINE_SYNCEN0											DISABLE
#define		FTM1_COMBINE_DTEN0												DISABLE
#define		FTM1_COMBINE_DECAP0												DISABLE
#define		FTM1_COMBINE_DECAPEN0											DISABLE
#define		FTM1_COMBINE_COMP0												DISABLE
#define		FTM1_COMBINE_COMBINE0											DISABLE

#define		FTM1_CH0_POLARITY												ACTIVE_HI
#define		FTM1_CH1_POLARITY												ACTIVE_HI
#define		FTM1_CH2_POLARITY												ACTIVE_HI
#define		FTM1_CH3_POLARITY												ACTIVE_HI
#define		FTM1_CH4_POLARITY												ACTIVE_HI
#define		FTM1_CH5_POLARITY												ACTIVE_HI
#define		FTM1_CH6_POLARITY												ACTIVE_HI
#define		FTM1_CH7_POLARITY												ACTIVE_HI


/* Mode register values*/
#define 	FTM1_MODE_FAULT_INTRP_EN										DISABLE
#define		FTM1_MODE_FAULT_MODE											FTMn_FAULTMODE_DISABLED
#define		FTM1_MODE_CAPTURE_TEST											DISABLE
#define 	FTM1_MODE_PWMSYNC												DISABLE
#define 	FTM1_MODE_WRITE_PROTECT											DISABLE
#define		FTM1_MODE_INIT_OUTINTREG										ENABLE
#define		FTM1_MODE_TPM_COMPACT_EN										DISABLE

/* Status and control  register values*/
#define 	FTM1_SC_FILTER_PS												FTMn_SC_FILTER_PS_DIV_BY_1
#define 	FTM1_SC_PWMCH0													DISABLE
#define 	FTM1_SC_PWMCH1													DISABLE
#define 	FTM1_SC_PWMCH2													DISABLE
#define 	FTM1_SC_PWMCH3													DISABLE
#define 	FTM1_SC_PWMCH4													DISABLE
#define 	FTM1_SC_PWMCH5													DISABLE
#define 	FTM1_SC_PWMCH6													DISABLE
#define 	FTM1_SC_PWMCH7													DISABLE
#define 	FTM1_SC_TIMER_FLW_INTR											ENABLE
#define 	FTM1_SC_RELOAD_FLG												DISABLE
#define 	FTM1_SC_RELOAD_INTRPT											DISABLE
#define 	FTM1_SC_CENTER_ALIGN_PWM										DISABLE
#define 	FTM1_SC_CLK_SRC_SEL												FTMn_SC_EXT_CLK
#define 	FTM1_SC_PRESCALE_FACTOR											FTMn_SC_PRESCALE_BY_2/*Allowed values Dev Note 11*/

#define		FTM1_CH0_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM1_CH1_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM1_CH2_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM1_CH3_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM1_CH4_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM1_CH5_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM1_CH6_INITVAL												1u	/* Allowed values 0, 1*/
#define		FTM1_CH7_INITVAL												1u	/* Allowed values 0, 1*/

/* Modulo register value*/
#define		FTM1_CH0_MODULO_VAL												4000u /* TOF hits after MOD value 125u -> 1ms for FTM input (8/64) Mhz */
#define		FTM1_INIT_CNT													0x0000u	/*Range 0x0000 - 0xFFFF*/

#define		FTM1_SYNCCONF_HWTRIGMODE										DISABLE
#define		FTM1_SYNCCONF_CNTINC											DISABLE
#define		FTM1_SYNCCONF_INVC												DISABLE
#define		FTM1_SYNCCONF_SWOC												DISABLE
#define		FTM1_SYNCCONF_SYNCMODE											DISABLE
#define		FTM1_SYNCCONF_SWRSTCNT											DISABLE
#define		FTM1_SYNCCONF_SWWRBUF											DISABLE
#define		FTM1_SYNCCONF_SWOM												DISABLE
#define		FTM1_SYNCCONF_SWINVC											DISABLE
#define		FTM1_SYNCCONF_SWSOC												DISABLE
#define		FTM1_SYNCCONF_HWRSCNT											DISABLE
#define		FTM1_SYNCCONF_HWWRBUF											DISABLE
#define		FTM1_SYNCCONF_HWOM												DISABLE
#define		FTM1_SYNCCONF_HWINVC											DISABLE
#define		FTM1_SYNCCONF_HWSOC												DISABLE


#if(ENABLE	==	FTM1_SC_PWMCH0|	\
				FTM1_SC_PWMCH1|	\
				FTM1_SC_PWMCH2|	\
				FTM1_SC_PWMCH3|	\
				FTM1_SC_PWMCH4|	\
				FTM1_SC_PWMCH5|	\
				FTM1_SC_PWMCH6|	\
				FTM1_SC_PWMCH7)

/* Dev Note 13. Ref manual 1427, For MSA, B and ESLA, B for selection of channel modes */

#define		FTM1_C0SC_TRIG_MODE												DISABLE
#define		FTM1_C0SC_CHL_INTRT												ENABLE
#define		FTM1_C0SC_MSB													DISABLE
#define		FTM1_C0SC_MSA													ENABLE
#define		FTM1_C0SC_ELSB													DISABLE
#define		FTM1_C0SC_ELSA													ENABLE /* Currently its OC -Toggle Mode*/
#define		FTM1_C0SC_COUNT_RST_IC											DISABLE
#define		FTM1_C0SC_DMA													DISABLE

#define		FTM1_C1SC_TRIG_MODE												DISABLE
#define		FTM1_C1SC_CHL_INTRT												ENABLE
#define		FTM1_C1SC_MSB													ENABLE
#define		FTM1_C1SC_MSA													DISABLE /* Currently its OC -Toggle Mode*/
#define		FTM1_C1SC_ELSB													ENABLE
#define		FTM1_C1SC_ELSA													DISABLE
#define		FTM1_C1SC_COUNT_RST_IC											DISABLE
#define		FTM1_C1SC_DMA													DISABLE


#endif

#endif




#endif /* MCAL_FTMN_CFG_H_ */
