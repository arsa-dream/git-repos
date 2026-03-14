/*
 * WDOG_Cfg.h
 *
 *  Created on: 07-Nov-2020
 *      Author: HP
 */

#ifndef MCAL_WDOG_CFG_H_
#define MCAL_WDOG_CFG_H_

#include "Headers.h"


/* Enable/ Disable Condition*/
#define    	WDOG_STATUS_CFG													    ENABLE				/* Config values allowed ENABLE/DISABLE*/
/* Config parameters */
#define		WDOG_WIN_MODE														DISABLE				/* Config values allowed ENABLE/DISABLE*/
	#if(WDOG_WIN_MODE == ENABLE)

		#define		WDOG_WIN_VAL												0x0000FFFF			/* TBD: conversion from real time values to counter value*/

	#endif
#define		WDOG_CMD32EN														ENABLE				/* Config values allowed ENABLE/DISABLE*/
#define		WDOG_PRESCALR														ENABLE				/* Config values allowed ENABLE/DISABLE*/
#define		WDOG_CLK_SRC														WDOG_INTRLPO_CLK	/* Config values allowed WDOG_BUS_CLK/WDOG_INTRLPO_CLK/WDOG_INTRL_CLK/WDOG_EXT_CLK*/
#define		WDOG_RECONFIG														DISABLE				/* Config values allowed ENABLE/DISABLE*/
#define		WDOG_TEST_MODE														WDOG_TEST_DISABLE	/* Config values allowed WDOG_TEST_DISABLE/WDOG_TEST_ENABLE/WDOG_TEST_LOWBYTE/WDOG_TEST_HIGHBYTE*/
#define		WDOG_DEBUG_MODE														DISABLE				/* Config values allowed ENABLE/DISABLE*/
#define		WDOG_WAIT_MODE														DISABLE				/* Config values allowed ENABLE/DISABLE*/
#define		WDOG_STOP_MODE														DISABLE				/* Config values allowed ENABLE/DISABLE*/
#define 	WDOG_PRESCALE														ENABLE				/* Config values allowed ENABLE/DISABLE*/
#define		WDOG_INRPT_CFG														DISABLE				/* Config values allowed ENABLE/DISABLE*/

/* Time out Cfgs*/

#define		WDOG_TIMEOUT_VAL													4u					/* Units: Seconds*/
#define		WDOG_WINDOW_VAL														0x0000FFFE			/* TBD: conversion from real time values to counter value
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 Note 8. Should be less than WDOG_TIMEOUT_VAL, Ref. Manual page 510*/




#endif /* MCAL_WDOG_CFG_H_ */
