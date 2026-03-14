///*
// * LPTMR_Core.c
// *
// *  Created on: 21-Nov-2020
// *      Author: HP
// */
//
//
//
//#include "Headers.h"
//
////Core
//

/*#define		LPTMR_CSR(DMAReq,			\
						IntrpEn,		\
						InputSel,		\
						PinPol,			\
						FreeRunCnt,		\
						Mode,			\
						Enable			)											(LPTMR0	->	CSR	=	LPTMR_CSR_TEN(Enable)		|			\
																										LPTMR_CSR_TMS(Mode)			|			\
																										LPTMR_CSR_TFC(FreeRunCnt)	|			\
																										LPTMR_CSR_TPP(PinPol)		|			\
																										LPTMR_CSR_TPS(InputSel)		|			\
																										LPTMR_CSR_TIE(IntrpEn)		|			\
																										LPTMR_CSR_TDRE(DMAReq)		)*/
//
//

/*#define 	LPTMR_PSR(PreScaler,	\
						PreSclrBypass,	\)*/

//
///* Dev Note 15. Ref Manual: 1569*/
//#define		LPTMR_PULSE_CNT0														0b00
//#define		LPTMR_PULSE_CNT1														0b01
//#define		LPTMR_PULSE_CNT2														0b10
//#define		LPTMR_PULSE_CNT3														0b11
//
//
//#define		LPTMR_PINPO_ACTHI														FALSE	/* Rising Edge : For Input Source*/
//#define		LPTMR_PINPO_ACTLO														TRUE	/* Falling Edge: For Input Source*/
//
//#define		LPTMR_RST_UPON_TCF														FALSE
//#define		LPTMR_RST_UPON_OVFL														TRUE
//
//#define		LPTMR_MODE_TIMECNT														FALSE
//#define		LPTMR_MODE_PULSECNT														TRUE
//
//
////Cfg
//
///* Control status register	*/
//
//#define		LPTMR_TMR_CFG															ENABLE
//#define		LPTMR_DMA_REQ_EN														DISABLE
//#define		LPTMR_TMR_PINSEL														LPTMR_PULSE_CNT0
//#define		LPTMR_TMR_PINPOL														LPTMR_PINPO_ACTHI
//#define		LPTMR_TMR_FRECNT														LPTMR_RST_UPON_TCF
//#define		LPTMR_TMR_MODE															LPTMR_MODE_TIMECNT
//#define		LPTMR_TMR_INTR															ENABLE
//
//
//
//
//
//#define		LPTMR_TMR_CMP_FLG
//
//void	LPTMR_Core(void)
//{

/*LPTMR_CSR(	LPTMR_DMA_REQ_EN,			\
				LPTMR_TMR_INTR,				\
				LPTMR_TMR_PINSEL,			\
				LPTMR_TMR_PINPOL,			\
				LPTMR_TMR_FRECNT,			\
				LPTMR_TMR_MODE,				\
				LPTMR_TMR_CFG				);*/
//}
