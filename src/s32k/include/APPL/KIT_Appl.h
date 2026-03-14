/*
 * Appl.h
 *
 *  Created on: 03-Nov-2020
 *      Author: HP
 */

#ifndef APPL_H_
#define APPL_H_


#include 	"Headers.h"

#define		APPL_SET_GREEN_LED()											GPIO_CLR_OUTPUT(PTD, 16u)		/* Active Low pin*/
#define		APPL_SET_RED_LED()											GPIO_CLR_OUTPUT(PTD, 15u)		/* Active Low pin*/
#define		APPL_SET_BLUE_LED()											GPIO_CLR_OUTPUT(PTD, 0u)		/* Active Low pin*/

#define		APPL_CLR_GREEN_LED()											GPIO_SET_OUTPUT(PTD, 16u)		/* Active Low pin*/
#define		APPL_CLR_RED_LED()											GPIO_SET_OUTPUT(PTD, 15u)		/* Active Low pin*/
#define		APPL_CLR_BLUE_LED()											GPIO_SET_OUTPUT(PTD, 0u)		/* Active Low pin*/

#define		APPL_TOG_GREEN_LED()											GPIO_TOGGLE(PTD, 16u)			/* Active Low pin*/
#define		APPL_TOG_RED_LED()											GPIO_TOGGLE(PTD, 15u)			/* Active Low pin*/
#define		APPL_TOG_BLUE_LED()											GPIO_TOGGLE(PTD, 0u)			/* Active Low pin*/

#define 	APPL_SWITCH_2_STATUS()										GPIO_READ_INPUT(PTC, 12u)

#define		APPL_DISABLE_PWM_RED()										FTMn_DISABLE_CH0(FTM0)
#define		APPL_DISABLE_PWM_GREEN()										FTMn_DISABLE_CH1(FTM0)
#define		APPL_DISABLE_PWM_BLUE()										FTMn_DISABLE_CH2(FTM0)

#define		APPL_ENABLE_PWM_RED()										FTMn_ENABLE_CH0(FTM0)
#define		APPL_ENABLE_PWM_GREEN()										FTMn_ENABLE_CH1(FTM0)
#define		APPL_ENABLE_PWM_BLUE()										FTMn_ENABLE_CH2(FTM0)

#define		APPL_SetRedDuty(duty)										FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, 0u, ((duty * 0xFFFFu)/10u)	) /* in accurate API, re check */
#define		APPL_SetGreenDuty(duty)										FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, 1u, ((duty * 0xFFFFu)/10u)	) /* in accurate API, re check */
#define		APPL_SetBlueDuty(duty)										FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, 2u, ((duty * 0xFFFFu)/10u)	) /* in accurate API, re check */

#define	    APPL_UartOut(str, len)										LPUart1_TransmitString(str, len)


extern void 	APPL_main(void);

#endif /* APPL_H_ */
