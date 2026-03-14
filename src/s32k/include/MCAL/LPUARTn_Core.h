/*
 * LPUARTn_Core.h
 *
 *  Created on: 21-Nov-2020
 *      Author: HP
 */

#ifndef MCAL_LPUARTN_CORE_H_
#define MCAL_LPUARTN_CORE_H_

#include	"Headers.h"


#define		LPUARTn_MAXRXBUFSIZE										30u


typedef	struct{
	uint8 	u8IndexPos;
	sint8	s8Buffer[LPUARTn_MAXRXBUFSIZE];
}stLPUARTRxBuf;

typedef		enum{
	eLPUART_0 = 0u,
	eLPUART_1,
	eLPUART_2,
	eLPUART_x_Limit
}eLPUART_x_Table;




#define  	LPUART_n_SET_BAUD_RATE(	UartAddr,			\
									MatchModeAddr_1,	\
									MatchModeAddr_2,	\
									TenBitMode,			\
									OverSamplingRatio,	\
									TxDMACond,			\
									RxDMACond,			\
									RxIdleDMACond,		\
									MatchConfig,		\
									BothEdgeSample,		\
									ResyncCond,			\
									LinBrkInprtCond,	\
									RxIpActiveEdge,		\
									StopBitNoSel,		\
								   	BaudRateMod)						  (UartAddr -> BAUD = 	  (LPUART_BAUD_MAEN1(MatchModeAddr_1)|	\
																								   LPUART_BAUD_MAEN2(MatchModeAddr_2)|		\
																								   LPUART_BAUD_M10(TenBitMode)|				\
																								   LPUART_BAUD_OSR(OverSamplingRatio)|		\
																								   LPUART_BAUD_TDMAE(TxDMACond)|			\
																								   LPUART_BAUD_RDMAE(RxDMACond)|			\
																								   LPUART_BAUD_RIDMAE(RxIdleDMACond)|		\
																								   LPUART_BAUD_MATCFG(MatchConfig)|			\
																								   LPUART_BAUD_BOTHEDGE(BothEdgeSample)|	\
																								   LPUART_BAUD_RESYNCDIS(ResyncCond)|		\
																								   LPUART_BAUD_LBKDIE(LinBrkInprtCond)|		\
																								   LPUART_BAUD_RXEDGIE(RxIpActiveEdge)|		\
																								   LPUART_BAUD_SBNS(StopBitNoSel)|			\
																								   LPUART_BAUD_SBR(BaudRateMod) )	)
																								  /* Ref. Manual: 1703*/


#define  	LPUART_n_SET_REG_STAT( UartAddr,		\
								   MsbFirst,		\
								   RxDataInvert,	\
								   RxWakeIdleDetect,\
								   BrkCharGenLen,	\
								   LinBrkDetect)						   (UartAddr -> STAT =  (LPUART_STAT_MSBF(MsbFirst)|			\
																								   LPUART_STAT_RXINV(RxDataInvert)|		\
																								   LPUART_STAT_RWUID(RxWakeIdleDetect)|	\
																								   LPUART_STAT_BRK13(BrkCharGenLen)|	\
																								   LPUART_STAT_LBKDE(LinBrkDetect)	)
																								  /* Ref. Manual: 1705*/


#define  	LPUART_n_SET_CTRL_REG( UartAddr,			\
								   RxBit8TxBit9,		\
								   RxBit9TxBit8,		\
								   TxDirSingleWire,		\
								   TxDataInvert,		\
								   OvrRunIntrp,			\
								   NoiseErrIntrp,		\
								   FrmeErIntrp,			\
								   ParityErIntrp,		\
								   TxIntrp,				\
								   TxCompleteIntrp,		\
								   RxIntrp,				\
								   IdleLineIntrp,		\
								   TxEnable,			\
								   RxEnable,			\
								   RxWakeUpCtrl,		\
								   SendBrk,				\
								   Match1Intrpt,		\
								   Match2Intrpt,		\
								   SevenBitMode,		\
								   IdleCfg,				\
								   Loops,				\
								   Doze,				\
								   RxSrcSel,			\
								   Bit9Bit8MdeSel,		\
								   RxWakeMethSel,		\
								   IdleLineSel,			\
								   ParityEn,			\
								   ParitySel)							 (UartAddr -> CTRL = 	  (LPUART_CTRL_R8T9(RxBit8TxBit9)|		\
																							   LPUART_CTRL_R9T8(RxBit9TxBit8)|								\
																							   LPUART_CTRL_TXDIR(TxDirSingleWire)|							\
																							   LPUART_CTRL_TXINV(TxDataInvert)|								\
																							   LPUART_CTRL_ORIE(OvrRunIntrp)|								\
																							   LPUART_CTRL_NEIE(NoiseErrIntrp)|								\
																							   LPUART_CTRL_FEIE(FrmeErIntrp)|								\
																							   LPUART_CTRL_PEIE(ParityErIntrp)|								\
																							   LPUART_CTRL_TIE(TxIntrp)|									\
																							   LPUART_CTRL_TCIE(TxCompleteIntrp)|							\
																							   LPUART_CTRL_RIE(RxIntrp)|									\
																							   LPUART_CTRL_ILIE(IdleLineIntrp)|								\
																							   LPUART_CTRL_TE(TxEnable)|									\
																							   LPUART_CTRL_RE(RxEnable) |									\
																							   LPUART_CTRL_RWU(RxWakeUpCtrl) |								\
																							   LPUART_CTRL_SBK(SendBrk) |									\
																							   LPUART_CTRL_MA1IE(Match1Intrpt) |							\
																							   LPUART_CTRL_MA2IE(Match2Intrpt) |							\
																							   LPUART_CTRL_M7(SevenBitMode) |								\
																							   LPUART_CTRL_IDLECFG(IdleCfg) |								\
																							   LPUART_CTRL_LOOPS(Loops) |									\
																							   LPUART_CTRL_DOZEEN(Doze) |									\
																							   LPUART_CTRL_RSRC(RxSrcSel) |									\
																							   LPUART_CTRL_M(Bit9Bit8MdeSel) |								\
																							   LPUART_CTRL_WAKE(RxWakeMethSel) |							\
																							   LPUART_CTRL_ILT(IdleLineSel) |								\
																							   LPUART_CTRL_PE(ParityEn) |									\
																							   LPUART_CTRL_PT(ParitySel) )	)
																							  /* Ref. Manual: 1709*/




#define  	LPUART_n_SET_WATER_REG( UartAddr,	\
								   TxWater,		\
								   RxWater )							(UartAddr -> WATER = 	(	LPUART_WATER_TXWATER(TxWater)|		\
										   	   	   	   	   	   	   	   	   	   	   	   				LPUART_WATER_RXWATER(RxWater)	)		)






#define		LPUARTn_OVERSAMPLERATIO_DEFAULT									0b00000
#define		LPUARTn_OVERSAMPLERATIO_4_BOTHEDGE								0b00011
#define		LPUARTn_OVERSAMPLERATIO_5_BOTHEDGE								0b00100
#define		LPUARTn_OVERSAMPLERATIO_6_BOTHEDGE								0b00101
#define		LPUARTn_OVERSAMPLERATIO_7_BOTHEDGE								0b00110
#define		LPUARTn_OVERSAMPLERATIO_8										0b00111
#define		LPUARTn_OVERSAMPLERATIO_9										0b01000
#define		LPUARTn_OVERSAMPLERATIO_10										0b01001
#define		LPUARTn_OVERSAMPLERATIO_11										0b01010
#define		LPUARTn_OVERSAMPLERATIO_12										0b01011
#define		LPUARTn_OVERSAMPLERATIO_13										0b01100
#define		LPUARTn_OVERSAMPLERATIO_14										0b01101
#define		LPUARTn_OVERSAMPLERATIO_15										0b01110
#define		LPUARTn_OVERSAMPLERATIO_16										0b01111
#define		LPUARTn_OVERSAMPLERATIO_17										0b10000
#define		LPUARTn_OVERSAMPLERATIO_18										0b10001
#define		LPUARTn_OVERSAMPLERATIO_19										0b10010
#define		LPUARTn_OVERSAMPLERATIO_20										0b10011
#define		LPUARTn_OVERSAMPLERATIO_21										0b10100
#define		LPUARTn_OVERSAMPLERATIO_22										0b10101
#define		LPUARTn_OVERSAMPLERATIO_23										0b10110
#define		LPUARTn_OVERSAMPLERATIO_24										0b10111
#define		LPUARTn_OVERSAMPLERATIO_25										0b11000
#define		LPUARTn_OVERSAMPLERATIO_26										0b11001
#define		LPUARTn_OVERSAMPLERATIO_27										0b11010
#define		LPUARTn_OVERSAMPLERATIO_28										0b11011
#define		LPUARTn_OVERSAMPLERATIO_29										0b11100
#define		LPUARTn_OVERSAMPLERATIO_30										0b11101
#define		LPUARTn_OVERSAMPLERATIO_31										0b11110
#define		LPUARTn_OVERSAMPLERATIO_32										0b11111


#define		LPUARTn_READ_RXINRTFLG(UartNumber)								(	(	(UartNumber	->	STAT)	&	LPUART_STAT_RXEDGIF_MASK	) >> LPUART_STAT_RXEDGIF_SHIFT	)
#define		LPUARTn_READ_RXDATAREGFULL(UartNumber)							(	(	(UartNumber	->	STAT)	&	LPUART_STAT_RDRF_MASK	) >> LPUART_STAT_RDRF_SHIFT	)
#define		LPUARTn_READ_STATTDRE(UartNumber)								(	(	(UartNumber	->	STAT)	&	LPUART_STAT_TDRE_MASK	) >> LPUART_STAT_TDRE_SHIFT	)


#define		LPUARTn_COPY_RX_WORD(UartNumber,	OutputBuf)					(OutputBuf = (UartNumber	->	DATA))
#define		LPUARTn_COPY_TX_WORD(UartNumber,	OutputBuf)					((UartNumber	->	DATA) = OutputBuf)
#define		LPUART_x_READTDREFLAG(UartNumber)								(	(	(UartNumber	->	STAT) & LPUART_STAT_TDRE_MASK)	>>	LPUART_STAT_TDRE_SHIFT	)
#define		LPUART_x_SENDWORD(UartNumber,	Word)							(	UartNumber	->	DATA	=	Word	)
#define		LPUART_x_STAT_RECIVE_ACTIVE(UartNumber)							(	(	(UartNumber	->	STAT) &	LPUART_STAT_RAF_MASK )	>>	LPUART_STAT_RAF_SHIFT)


#define 	LPUART_n_ENABLE_CTRL_TXINTRP(UartAddr)							(UartAddr -> CTRL |= LPUART_CTRL_TIE(1u) )
#define 	LPUART_n_DISABLE_CTRL_TXINTRP(UartAddr)							(UartAddr -> CTRL &= ~LPUART_CTRL_TIE_MASK )
#define 	LPUART_n_ENABLE_CTRL_TXCOMPLETEINTP(UartAddr)					(UartAddr -> CTRL |= LPUART_CTRL_TCIE(1u) )
#define 	LPUART_n_DISABLE_CTRL_TXCOMPLETEINTP(UartAddr)					(UartAddr -> CTRL &= ~LPUART_CTRL_TCIE_MASK )
#define 	LPUART_n_CLEAR_STAT_RXEDGEINTRPFLG(UartAddr)					(UartAddr -> CTRL |= LPUART_STAT_RXEDGIF_MASK)


#define 	LPUART_n_DISABLE_BAUD_RXEDGEINTRP(UartAddr)						(UartAddr -> BAUD &= ~LPUART_BAUD_RXEDGIE_MASK )
#define		LPUART_n_FETCH_TxCOMPLETE(UartAddr)								(	(	(UartAddr -> STAT) & LPUART_STAT_TC_MASK	) >> LPUART_STAT_TC_SHIFT	)

#define     LPUART_n_DISABLE_CTRL_RXINTP(UartAddr)							(UartAddr -> CTRL |= LPUART_CTRL_RIE(1u) )
#define     LPUART_n_ENABLE_CTRL_RXINTP(UartAddr)							(UartAddr -> CTRL &= ~LPUART_CTRL_RIE_MASK )

/* Dev Note 9 : Configures the input trigger usage. This field should only be changed when the transmitter and receiver
are both disabled.*/
#define		LPUART_x_TRGSEL_CFGPIN_TRIG_DISABLE								 0b00/*Ref manual Page: 1702*/
#define		LPUART_x_TRGSEL_CFGPIN_TRIG_EN_INSTEAD_RXD						 0b01/*Ref manual Page: 1702*/
#define		LPUART_x_TRGSEL_CFGPIN_TRIG_EN_INSTEAD_CTSB						 0b10/*Ref manual Page: 1702*/
#define		LPUART_x_TRGSEL_CFGPIN_TRIG_MODULATE_TXD						 0b11/*Ref manual Page: 1702*/


#define 	LPUART_x_STAT_IDLECHAR_1										0b000/*Ref manual Page: 1712*/
#define 	LPUART_x_STAT_IDLECHAR_2										0b001/*Ref manual Page: 1712*/
#define 	LPUART_x_STAT_IDLECHAR_4										0b010/*Ref manual Page: 1712*/
#define 	LPUART_x_STAT_IDLECHAR_8										0b011/*Ref manual Page: 1712*/
#define 	LPUART_x_STAT_IDLECHAR_16										0b100/*Ref manual Page: 1712*/
#define 	LPUART_x_STAT_IDLECHAR_32										0b101/*Ref manual Page: 1712*/
#define 	LPUART_x_STAT_IDLECHAR_64										0b110/*Ref manual Page: 1712*/
#define 	LPUART_x_STAT_IDLECHAR_128										0b111/*Ref manual Page: 1712*/

#define 	LPUART_x_BAUD_ORR_DEFAULT										0b00000 /*ORR 16*/
#define 	LPUART_x_BAUD_ORR_4												0b00011 /*ORR 4*/
#define 	LPUART_x_BAUD_ORR_5												0b00100 /*ORR 5*/
#define 	LPUART_x_BAUD_ORR_6												0b00101 /*ORR 6*/
#define 	LPUART_x_BAUD_ORR_7												0b00110 /*ORR 7*/
#define 	LPUART_x_BAUD_ORR_8												0b00111 /*ORR 8*/
#define 	LPUART_x_BAUD_ORR_9												0b01000 /*ORR 9*/
#define 	LPUART_x_BAUD_ORR_10											0b01001 /*ORR 10*/
#define 	LPUART_x_BAUD_ORR_11											0b01010 /*ORR 11*/
#define 	LPUART_x_BAUD_ORR_12											0b01011 /*ORR 12*/
#define 	LPUART_x_BAUD_ORR_13											0b01110 /*ORR 13*/
#define 	LPUART_x_BAUD_ORR_14											0b01101 /*ORR 14*/
#define 	LPUART_x_BAUD_ORR_15											0b01110 /*ORR 15*/
#define 	LPUART_x_BAUD_ORR_16											0b01111 /*ORR 16*/
#define 	LPUART_x_BAUD_ORR_17											0b10000 /*ORR 17*/
#define 	LPUART_x_BAUD_ORR_18											0b10001 /*ORR 18*/
#define 	LPUART_x_BAUD_ORR_19											0b10010 /*ORR 19*/
#define 	LPUART_x_BAUD_ORR_20											0b10011 /*ORR 20*/
#define 	LPUART_x_BAUD_ORR_21											0b10100 /*ORR 21*/
#define 	LPUART_x_BAUD_ORR_22											0b10101 /*ORR 22*/
#define 	LPUART_x_BAUD_ORR_23											0b10110 /*ORR 23*/
#define 	LPUART_x_BAUD_ORR_24											0b10111 /*ORR 24*/
#define 	LPUART_x_BAUD_ORR_25											0b11000 /*ORR 25*/
#define 	LPUART_x_BAUD_ORR_26											0b11001 /*ORR 26*/
#define 	LPUART_x_BAUD_ORR_27											0b11010 /*ORR 27*/
#define 	LPUART_x_BAUD_ORR_28											0b11011 /*ORR 28*/
#define 	LPUART_x_BAUD_ORR_29											0b11100 /*ORR 29*/
#define 	LPUART_x_BAUD_ORR_30											0b11101 /*ORR 30*/
#define 	LPUART_x_BAUD_ORR_31											0b11110 /*ORR 31*/
#define 	LPUART_x_BAUD_ORR_32											0b11111 /*ORR 32*/
																			/* All other values are Reserved, Refer Manual page: 1704*/
#define		LPUART_x_MATCH_CFG_ADDR_WAKE_UP									0b00
#define		LPUART_x_MATCH_CFG_IDLE_WAKE_UP									0b01
#define		LPUART_x_MATCH_CFG_MTCH_ON_OFF									0b10
#define		LPUART_x_MATCH_CFG_RWS_CTS_MATCH								0b11

#define		LPUART_x_BAUD_ONESTOPBIT										0u
#define		LPUART_x_BAUD_TWOSTOPBIT										1u



#define		LPUART_x_BAUD_SBR									   			2u/* Formula: SBR = (SrcClk/ ( (OSR+1)*Baud rate) )For SBR = ~2u (1.778)Baud rate 144000, SrcClk 128kHz, OSR = 4
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 The Baud rate, OSR(4) were chosen at minimal error of -0.222 at the given clock source
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 NOTE: OSR shall be 4u if SBR to be configured to 2u for 144000 Baud rate : DevHelp: KeyWord: CLK_CRITICAL*/






void LPUART_Init(void);
void LPUart0_Init(void);
void LPUart1_Init(void);
void LPUart2_Init(void);


extern	STD_FsmStates 	LPUart0_TransmitString(sint8	*s8Word,	uint8 u8Size);
extern	STD_FsmStates 	LPUart1_TransmitString(sint8	*s8Word,	uint8 u8Size);
extern	STD_FsmStates 	LPUart2_TransmitString(sint8	*s8Word,	uint8 u8Size);

extern	void 			LPUart0_Recieve(void);
extern	void 			LPUart1_Recieve(void);
extern	void 			LPUart2_Recieve(void);


#endif /* MCAL_LPUARTN_CORE_H_ */
