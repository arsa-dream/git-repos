/*
 * FTMn_Core.h
 *
 *  Created on: 16-Nov-2020
 *      Author: HP
 */

#ifndef MCAL_FTMN_CORE_H_
#define MCAL_FTMN_CORE_H_

#include "Headers.h"


//Core

#define		FTMn_MODE(FTMNumber,			\
						FaultIE,			\
						FaultMode,			\
						CapTest,			\
						PWMSync,			\
						WriteProtection,	\
						InitOutput,			\
						FTMEn				)					    		(FTMNumber -> MODE = 	(FTM_MODE_FTMEN(FaultIE)				|\
																									 FTM_MODE_INIT(InitOutput)				|\
																									 FTM_MODE_WPDIS(WriteProtection)		|\
																									 FTM_MODE_PWMSYNC(PWMSync)				|\
																									 FTM_MODE_CAPTEST(CapTest)				|\
																									 FTM_MODE_FAULTM(FaultMode)				|\
																									 FTM_MODE_FAULTIE(FaultIE)	)	)

#define 	FTMn_SC_CTRL(FTMNumber,			\
							 FilterClkPS,		\
							 PWMCh0,			\
							 PWMCh1,			\
							 PWMCh2,			\
							 PWMCh3,			\
							 PWMCh4,			\
							 PWMCh5,			\
							 PWMCh6,			\
							 PWMCh7,			\
							 TimerOvFlwIntrp,	\
							 ReloadFlg,			\
							 ReloadIntrp,		\
							 CenterAlignPWM,	\
							 ClkSrcSel,			\
							 PSFactor			)				     		(FTMNumber -> SC = 	(	FTM_SC_FLTPS(FilterClkPS)			|\
																									FTM_SC_PWMEN0(PWMCh0)				|\
																									FTM_SC_PWMEN1(PWMCh1)				|\
																									FTM_SC_PWMEN2(PWMCh2)				|\
																									FTM_SC_PWMEN3(PWMCh3)				|\
																									FTM_SC_PWMEN4(PWMCh4)				|\
																									FTM_SC_PWMEN5(PWMCh5)				|\
																									FTM_SC_PWMEN6(PWMCh6)				|\
																									FTM_SC_PWMEN7(PWMCh7)				|\
																									FTM_SC_TOIE(TimerOvFlwIntrp)		|\
																									FTM_SC_RF(ReloadFlg)				|\
																									FTM_SC_RIE(ReloadIntrp)				|\
																									FTM_SC_CPWMS(CenterAlignPWM)		|\
																									FTM_SC_CLKS(ClkSrcSel)				|\
																									FTM_SC_PS(PSFactor)	)	)


#define 	FTMn_COMBINE_CTRL(FTMNumber,		\
							 ModCombine3,		\
							 FaultEn3,			\
							 SyncEn3,			\
							 DeadTimeEn3,		\
							 DualCapture3,		\
							 DualCapChlMde3,	\
							 CompChl3,			\
							 Combine3,			\
							 ModCombine2,		\
							 FaultEn2,			\
							 SyncEn2,			\
							 DeadTimeEn2,		\
							 DualCapture2,		\
							 DualCapChlMde2,	\
							 CompChl2,			\
							 Combine2,			\
							 ModCombine1,		\
							 FaultEn1,			\
							 SyncEn1,			\
							 DeadTimeEn1,		\
							 DualCapture1,		\
							 DualCapChlMde1,	\
							 CompChl1,			\
							 Combine1,			\
							 ModCombine0,		\
							 FaultEn0,			\
							 SyncEn0,			\
							 DeadTimeEn0,		\
							 DualCapture0,		\
							 DualCapChlMde0,	\
							 CompChl0,			\
							 Combine0)										(FTMNumber -> COMBINE = 	(	     FTM_COMBINE_MCOMBINE3(ModCombine3)		|\
																												 FTM_COMBINE_FAULTEN3(FaultEn3)			|\
																												 FTM_COMBINE_SYNCEN3(SyncEn3)			|\
																												 FTM_COMBINE_DTEN3(DeadTimeEn3)			|\
																												 FTM_COMBINE_DECAP3(DualCapture3)		|\
																												 FTM_COMBINE_DECAPEN3(DualCapChlMde3)	|\
																												 FTM_COMBINE_COMP3(CompChl3)			|\
																												 FTM_COMBINE_COMBINE3(Combine3)			|\
																												 FTM_COMBINE_MCOMBINE2(ModCombine2)		|\
																												 FTM_COMBINE_FAULTEN2(FaultEn2)			|\
																												 FTM_COMBINE_SYNCEN2(SyncEn2)			|\
																												 FTM_COMBINE_DTEN2(DeadTimeEn2)			|\
																												 FTM_COMBINE_DECAP2(DualCapture2)		|\
																												 FTM_COMBINE_DECAPEN2(DualCapChlMde2)	|\
																												 FTM_COMBINE_COMP2(CompChl2)			|\
																												 FTM_COMBINE_COMBINE2(Combine2)			|\
																												 FTM_COMBINE_MCOMBINE1(ModCombine1)		|\
																												 FTM_COMBINE_FAULTEN1(FaultEn1)			|\
																												 FTM_COMBINE_SYNCEN1(SyncEn1)			|\
																												 FTM_COMBINE_DTEN1(DeadTimeEn1)			|\
																												 FTM_COMBINE_DECAP1(DualCapture1)		|\
																												 FTM_COMBINE_DECAPEN1(DualCapChlMde1)	|\
																												 FTM_COMBINE_COMP1(CompChl1)			|\
																												 FTM_COMBINE_COMBINE1(Combine1)			|\
																												 FTM_COMBINE_MCOMBINE1(ModCombine0)		|\
																												 FTM_COMBINE_FAULTEN0(FaultEn0)			|\
																												 FTM_COMBINE_SYNCEN0(SyncEn0)			|\
																												 FTM_COMBINE_DTEN0(DeadTimeEn0)			|\
																												 FTM_COMBINE_DECAP0(DualCapture0)		|\
																												 FTM_COMBINE_DECAPEN0(DualCapChlMde0)	|\
																												 FTM_COMBINE_COMP0(CompChl0)			|\
																												 FTM_COMBINE_COMBINE0(Combine0)			 ))


#define		FTMn_POL_CTRL(FTMNumber,		\
							 Ch0Polarity,	\
							 Ch1Polarity,	\
							 Ch2Polarity,	\
							 Ch3Polarity,	\
							 Ch4Polarity,	\
							 Ch5Polarity,	\
							 Ch6Polarity,	\
							 Ch7Polarity)									(FTMNumber -> POL =  FTM_POL_POL0(Ch0Polarity)|	\
																								 FTM_POL_POL1(Ch1Polarity)|	\
																								 FTM_POL_POL2(Ch2Polarity)|	\
																								 FTM_POL_POL3(Ch3Polarity)|	\
																								 FTM_POL_POL4(Ch4Polarity)|	\
																								 FTM_POL_POL5(Ch5Polarity)|	\
																								 FTM_POL_POL6(Ch6Polarity)|	\
																								 FTM_POL_POL7(Ch7Polarity)	)

#define		FTMn_MOD_CTRL(	FTMNumber,		\
							ModuloValue	)									(FTMNumber -> MOD =  PDB_MOD_MOD(ModuloValue)	)


#define		FTMn_CnSC(	FTMNumber,			\
						  ChannelNo,		\
						  TriggerMode,		\
						  ChlInterpEn,		\
						  MSB,				\
						  MSA,				\
						  ELSB,				\
						  ELSA,				\
						  ICCntReset,		\
						  DMA)											 	(FTMNumber -> CONTROLS [ChannelNo].CnSC = 	(FTM_CnSC_TRIGMODE(TriggerMode)	|		\
																														FTM_CnSC_CHIE(ChlInterpEn)		|		\
																														FTM_CnSC_MSB(MSB)				|		\
																														FTM_CnSC_MSA(MSA)				|		\
																														FTM_CnSC_ELSB(ELSB)				|		\
																														FTM_CnSC_ELSA(ELSA)				|		\
																														FTM_CnSC_ICRST(ICCntReset)		|		\
																														FTM_CnSC_DMA(DMA)				)	)

#define 	FTMn_OUTINT(FTMNumber,	\
						Ch0InitVal,	\
						Ch1InitVal,	\
						Ch2InitVal,	\
						Ch3InitVal,	\
						Ch4InitVal,	\
						Ch5InitVal,	\
						Ch6InitVal,	\
						Ch7InitVal	)										(FTMNumber	->	OUTINIT =	(	FTM_OUTINIT_CH0OI(Ch0InitVal)	|\
																											FTM_OUTINIT_CH1OI(Ch1InitVal)	|\
																											FTM_OUTINIT_CH2OI(Ch2InitVal)	|\
																											FTM_OUTINIT_CH3OI(Ch3InitVal)	|\
																											FTM_OUTINIT_CH4OI(Ch4InitVal)	|\
																											FTM_OUTINIT_CH5OI(Ch5InitVal)	|\
																											FTM_OUTINIT_CH6OI(Ch6InitVal)	|\
																											FTM_OUTINIT_CH7OI(Ch7InitVal)	)	)


#define		FTMn_SYNCCONF(FTMNumber,	\
						  HwSoc,		\
						  HwInvc,		\
						  Hwom,			\
						  HwwrBuf,		\
						  HwrstCnt,		\
						  SwSoc,		\
						  SwInvc,		\
						  Swom,			\
						  SwwrBuf,		\
						  SwrstCnt,		\
						  SyncMode,		\
						  Swoc,			\
						  Invc,			\
						  CntInc,		\
						  HwTrigMode	)									(FTMNumber	-> SYNCONF	=	(	FTM_SYNCONF_HWTRIGMODE(HwTrigMode)		|\
								  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	 FTM_SYNCONF_CNTINC(CntInc)				|\
																											 FTM_SYNCONF_INVC(Invc) 				|\
																											 FTM_SYNCONF_SWOC(Swoc)					|\
																											 FTM_SYNCONF_SYNCMODE(SyncMode) 		|\
																											 FTM_SYNCONF_SWRSTCNT(SwrstCnt)			|\
																											 FTM_SYNCONF_SWWRBUF(SwwrBuf)			|\
																											 FTM_SYNCONF_SWOM(Swom)					|\
																											 FTM_SYNCONF_SWINVC(SwInvc)				|\
																											 FTM_SYNCONF_SWSOC(SwSoc) 				|\
																											 FTM_SYNCONF_HWRSTCNT(HwrstCnt)			|\
																											 FTM_SYNCONF_HWWRBUF(HwwrBuf)			|\
																											 FTM_SYNCONF_HWOM(Hwom)					|\
																											 FTM_SYNCONF_HWINVC(HwInvc)				|\
																											 FTM_SYNCONF_HWSOC(HwSoc)	)	)

#define		FTMn_CNTINT(	FTMNumber,	\
							InitialCnt	)									(FTMNumber	->	CNTIN	=	InitialCnt)

#define 	FTMn_CHn_SET_COMPARE_COUNT(FTMNumber,\
										ChannelNo,\
										Count	)							(FTMNumber -> CONTROLS[ChannelNo].CnV = Count)

#define 	FTMn_CHn_SET_CHANNEL_DUTY(FTMNumber,	\
										ChannelNo,	\
										Duty	)							(FTMNumber -> CONTROLS[ChannelNo].CnV = Duty *	(FTM0_CHx_MODULO_VAL/100u)	)

#define 	FTMn_CHn_SET_CHANNEL_DUTYCNT(FTMNumber,	\
										ChannelNo,	\
										DutyCnt	)							(FTMNumber -> CONTROLS[ChannelNo].CnV = 	DutyCnt	)

#define 	FTMn_SYNC_CNVCNT(FTMNumber)										(FTMNumber -> SYNC	|=	FTM_SYNC_SWSYNC_MASK)

#define		FTMn_CHn_FETCH_CHF_FLG(FTMNumber,	\
									ChannelNo)								((FTMNumber ->	CONTROLS[ChannelNo].CnSC & FTM_CnSC_CHF_MASK) >> FTM_CnSC_CHF_SHIFT )

#define		FTMn_CHn_CLEAR_CHF_FLG(FTMNumber,	\
									ChannelNo)								(FTMNumber ->	CONTROLS[ChannelNo].CnSC &= ~FTM_CnSC_CHF_MASK)

#define		FTMn_FETCH_TIMEROVFLG(FTMNumber)								(	(	(FTMNumber -> SC)	&	(	FTM_SC_TOF(1u)	)	)	>>	FTM_SC_TOF_SHIFT		)
#define		FTMn_CLEAR_TIMEROVFLG(FTMNumber)								(		(FTMNumber -> SC)   &=	0xFFFFFDFFu	)

#define		FTMn_FETCH_MODVAL(FTMNumber)									(	FTMNumber	-> MOD	)

#define		FTMn_DISABLE_CHx(FTMNumber,	\
						 	 ChannelNo	)									(	FTMNumber	-> SC &= ~(	STRD_FIXED_LEFTOFFSET(1u, 15u)	<<	ChannelNo)	)


#define		FTMn_DISABLE_CH0(FTMNumber)										(	FTMNumber	-> SC &= 	~FTM_SC_PWMEN0_MASK	)
#define		FTMn_DISABLE_CH1(FTMNumber)										(	FTMNumber	-> SC &= 	~FTM_SC_PWMEN1_MASK	)
#define		FTMn_DISABLE_CH2(FTMNumber)										(	FTMNumber	-> SC &= 	~FTM_SC_PWMEN2_MASK	)

#define		FTMn_ENABLE_CH0(FTMNumber)										(	FTMNumber	-> SC |=	FTM_SC_PWMEN0_MASK	)
#define		FTMn_ENABLE_CH1(FTMNumber)										(	FTMNumber	-> SC |=	FTM_SC_PWMEN1_MASK	)
#define		FTMn_ENABLE_CH2(FTMNumber)										(	FTMNumber	-> SC |=	FTM_SC_PWMEN2_MASK	)

#define		FTMn_ENABLE_CHx(FTMNumber,	\
							 ChannelNo	)									(	FTMNumber	-> SC |= (	STRD_FIXED_LEFTOFFSET(1u, 15u)	<<	ChannelNo)	)




/* Dev Note 10 Ref. Manual 1375*/
#define 	FTMn_FAULTMODE_DISABLED											0b00
#define		FTMn_FAULTMODE_EVENCHLS											0b01
#define		FTMn_FAULTMODE_ALLMANUAL										0b10
#define		FTMn_FAULTMODE_ALLAUTO											0b11

/* Dev Note 11 RM Page 1366*/
#define		FTMn_SC_NO_CLK_SRC												0b00
#define		FTMn_SC_FTM_CLK_INPUT											0b01
#define		FTMn_SC_FIXED_CLK_FREQ											0b10
#define		FTMn_SC_EXT_CLK													0b11

#define		FTMn_SC_PRESCALE_BY_1											0b000
#define		FTMn_SC_PRESCALE_BY_2											0b001
#define		FTMn_SC_PRESCALE_BY_4											0b010
#define		FTMn_SC_PRESCALE_BY_8											0b011
#define		FTMn_SC_PRESCALE_BY_16											0b100
#define		FTMn_SC_PRESCALE_BY_32											0b101
#define		FTMn_SC_PRESCALE_BY_64											0b110
#define		FTMn_SC_PRESCALE_BY_128											0b111

#define 	FTMn_SC_FILTER_PS_DIV_BY_1										0b0000
#define 	FTMn_SC_FILTER_PS_DIV_BY_2										0b0001
#define 	FTMn_SC_FILTER_PS_DIV_BY_3										0b0010
#define 	FTMn_SC_FILTER_PS_DIV_BY_4										0b0011
#define 	FTMn_SC_FILTER_PS_DIV_BY_5										0b0100
#define 	FTMn_SC_FILTER_PS_DIV_BY_6										0b0101
#define 	FTMn_SC_FILTER_PS_DIV_BY_7										0b0110
#define 	FTMn_SC_FILTER_PS_DIV_BY_8										0b0111
#define 	FTMn_SC_FILTER_PS_DIV_BY_9										0b1000
#define 	FTMn_SC_FILTER_PS_DIV_BY_10										0b1001
#define 	FTMn_SC_FILTER_PS_DIV_BY_11										0b1010
#define 	FTMn_SC_FILTER_PS_DIV_BY_12										0b1011
#define 	FTMn_SC_FILTER_PS_DIV_BY_13										0b1100
#define 	FTMn_SC_FILTER_PS_DIV_BY_14										0b1101
#define 	FTMn_SC_FILTER_PS_DIV_BY_15										0b1110
#define 	FTMn_SC_FILTER_PS_DIV_BY_16										0b1111

/*Note 12: Ref Manual <1388>, FTM CHn Polarity*/
#define 	ACTIVE_HI														0u
#define		ACTIVE_LOW														1u


extern 			void FTMn_Init(void);
extern inline	void FTM0_Init(void);
extern inline	void FTM1_Init(void);
extern inline	void FTM2_Init(void);
extern inline	void FTM3_Init(void);
extern inline	void FTM4_Init(void);
extern inline	void FTM5_Init(void);
extern inline	void FTM6_Init(void);
extern inline	void FTM7_Init(void);


extern	uint32	TIMER_SetDelay(uint32	u32Input);
extern	uint8	TIMER_IsDelayExpired(uint32	u32Output);
extern	uint8 	FTMn_CHn_SetDuty(FTM_Type		*LstTimerNumber,	uint8 u8Duty,	uint8	u8ChlNo);



#endif /* MCAL_FTMN_CORE_H_ */
