/*
 * WDOG_Core.c
 *
 *  Created on: 06-Nov-2020
 *      Author: HP
 */



#include "Headers.h"


void inline WDOG_Init(void)
{

	volatile uint32 u32TotalValue = 0;

	u32TotalValue = WDOG_CAL_TIMEOUT_VAL(WDOG_TIMEOUT_VAL);

	WDOG_UNLOCK_REGS();

	while(WDOG_READ_ULK_STAT() == 0u);
	/* Wait until the WDOG registers are unlocked*/

	WDOG_WRITE_TOTAL_VAL(u32TotalValue);
	/* Configure time out value */

#if(WDOG_WIN_MODE == ENABLE)
	WDOG_WRITE_WINDOW_VAL(WDOG_WIN_VAL);
#endif

	WDOG_CS_REG(WDOG_WIN_MODE,		\
				WDOG_CMD32EN,		\
				WDOG_CLK_SRC,		\
				WDOG_RECONFIG,		\
				WDOG_INRPT_CFG,		\
				WDOG_TEST_MODE,		\
				WDOG_DEBUG_MODE,	\
				WDOG_WAIT_MODE,		\
				WDOG_STOP_MODE,		\
				WDOG_STATUS_CFG,	\
				WDOG_PRESCALE);


	while(WDOG_READ_RCS_STAT() == 0u); /*wait until new configuration takes effect*/

}


void inline WDOG_Refresh(void)
{
	DISABLE_INTERRUPTS();

	WDOG_REFRESH_SET();

	ENABLE_INTERRUPTS();
}
