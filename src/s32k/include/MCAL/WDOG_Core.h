
/*
 * WDOG_Core.h
 *
 *  Created on: 07-Nov-2020
 *      Author: HP
 */



#ifndef WDOG_CORE_H_
#define WDOG_CORE_H_


#include	"Headers.h"



#define		WDOG_CS_REG(WinMode, Cmd32en, ClkSrc, ReConfig, IntrptCfg,	TestMode, DebugMode, WaitMode, StopMode, Enable, PreScale)					(WDOG->CS = (WDOG_CS_WIN(WinMode)|		\
																																								WDOG_CS_CMD32EN(Cmd32en)|	\
																																								WDOG_CS_CLK(ClkSrc)|		\
																																								WDOG_CS_UPDATE(ReConfig)|	\
																																								WDOG_CS_INT(IntrptCfg)|		\
																																								WDOG_CS_TST(TestMode)|		\
																																								WDOG_CS_DBG(DebugMode)|		\
																																								WDOG_CS_WAIT(WaitMode)|		\
																																								WDOG_CS_STOP(StopMode)|		\
																																								WDOG_CS_EN(Enable)) |		\
																																								WDOG_CS_PRES(PreScale))

#define	 	WDOG_UNLOCK_REGS()							(WDOG->CNT = 0xD928C520)
#define	 	WDOG_REFRESH_SET()							(WDOG->CNT = 0xB480A602)
#define	 	WDOG_READ_ULK_STAT()						(WDOG->CS & 0x0800)
#define	 	WDOG_READ_RCS_STAT()						(WDOG->CS & 0x0400)
#define		WDOG_CAL_TIMEOUT_VAL(TimePeriod)			(TimePeriod*500u);			/* Formula =  WDOG_Cnt = (Source clk)/((Prescaler) * Time period) in milli seconds
																					   <500 Constant for 128khz Clk, 256 Prescale>: : DevHelp: KeyWord: CLK_CRITICAL */



#define		WDOG_WRITE_TOTAL_VAL(TotalVal)				(WDOG->TOVAL =	TotalVal)
#define		WDOG_WRITE_WINDOW_VAL(WindowVal)			(WDOG->WIN =	WindowVal)

#define 	WDOG_BUS_CLK								0b00 /* 	Note 5. Page 573 , Ref. Manual */
#define		WDOG_INTRLPO_CLK							0b01
#define		WDOG_INTRL_CLK								0b10
#define		WDOG_EXT_CLK								0b11

#define		WDOG_CLR_INRTP								0b1	 /* 	Note 6. Page 506 , Ref. Manual */

#define		WDOG_TEST_DISABLE							0b00 /* 	Note 7. Page 507, Ref. Manual */
#define		WDOG_TEST_ENABLE							0b01
#define		WDOG_TEST_LOWBYTE							0b10
#define		WDOG_TEST_HIGHBYTE							0b11


#if(WDOG_WINDOW_VAL	<	WDOG_TIMEOUT_VAL)																		/* TBD: To be solved > to >=*/

#error 		"Developer help: Watch dog Window value shall be less than Time out value Refer Note 8."

#endif

#if(WDOG_TIMEOUT_VAL >=  131000u)

#error 		"Developer help: Watch dog Delay shall be less than 131 seconds(Max Delay)"


#endif



extern 		void inline WDOG_Init(void);
extern		void inline WDOG_Refresh(void);


#endif  /* WDOG_CORE_H_ */

