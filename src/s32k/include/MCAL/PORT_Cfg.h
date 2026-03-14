/*
 * Gpio_Cfg.h
 *
 *  Created on: 01-Nov-2020
 *      Author: HP
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

#include <STRD_Types.h>
#include "Headers.h"

#define ENABLE_PORT_A																	FALSE
#define ENABLE_PORT_B																	FALSE
#define ENABLE_PORT_C																	TRUE
#define ENABLE_PORT_D																	TRUE
#define ENABLE_PORT_E																	FALSE






#if(ENABLE_PORT_A == TRUE)



	/*PortA_0 configuration values Start*/
	#define		PIN_DIR_PORTA_0																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_0														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_0 == ENABLE)

	#define INTRP_TYPE_PORTA_0																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_0																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_0															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_0																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_0													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_0 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_0													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PortA_0 configuration values End*/

	/*PORTA_1 configuration values Start*/
	#define		PIN_DIR_PORTA_1																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_1														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_1 == ENABLE)

	#define INTRP_TYPE_PORTA_1																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_1																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_1															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_1																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_1													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_1 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_1													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_1 configuration values End*/



	/*PORTA_2 configuration values Start*/
	#define		PIN_DIR_PORTA_2																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_2														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_2 == ENABLE)

	#define INTRP_TYPE_PORTA_2																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_2																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_2															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_2																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_2													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_2 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_2													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_2 configuration values End*/




	/*PORTA_3 configuration values Start*/
	#define		PIN_DIR_PORTA_3																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_3														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_3 == ENABLE)

	#define INTRP_TYPE_PORTA_3																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_3																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_3															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_3																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_3													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_3 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_3													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_3 configuration values End*/

	/*PORTA_4 configuration values Start*/
	#define		PIN_DIR_PORTA_4																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_4														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_4 == ENABLE)

	#define INTRP_TYPE_PORTA_4																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_4																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_4															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_4																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_4													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_4 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_4													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_4 configuration values End*/



	/*PORTA_5 configuration values Start*/
	#define		PIN_DIR_PORTA_5																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_5														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_5 == ENABLE)

	#define INTRP_TYPE_PORTA_5																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_5																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_5															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_5																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_5													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_5 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_5													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_5 configuration values End*/



	/*PORTA_6 configuration values Start*/
	#define		PIN_DIR_PORTA_6																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_6														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_6 == ENABLE)

	#define INTRP_TYPE_PORTA_6																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_6																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_6															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_6																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_6													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_6 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_6													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_6 configuration values End*/




	/*PORTA_7 configuration values Start*/
	#define		PIN_DIR_PORTA_7																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_7														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_7 == ENABLE)

	#define INTRP_TYPE_PORTA_7																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_7																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_7															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_7																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_7													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_7 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_7													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_7 configuration values End*/



	/*PORTA_8 configuration values Start*/
	#define		PIN_DIR_PORTA_8																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_8														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_8 == ENABLE)

	#define INTRP_TYPE_PORTA_8																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_8																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_8															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_8																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_8													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_8 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_8													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_8 configuration values End*/




	/*PORTA_9 configuration values Start*/
	#define		PIN_DIR_PORTA_9																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_9														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_9 == ENABLE)

	#define INTRP_TYPE_PORTA_9																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_9																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_9															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_9																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_9													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_9 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_9													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_9 configuration values End*/



	/*PORTA_10 configuration values Start*/
	#define		PIN_DIR_PORTA_10																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_10														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_10 == ENABLE)

	#define INTRP_TYPE_PORTA_10																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_10																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_10															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_10																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_10														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_10														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_10													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_10 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_10													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_10 configuration values End*/



	/*PORTA_11 configuration values Start*/
	#define		PIN_DIR_PORTA_11																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_11														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_11 == ENABLE)

	#define INTRP_TYPE_PORTA_11																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_11																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_11															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_11																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_11														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_11														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_11													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_11 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_11													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_11 configuration values End*/



	/*PORTA_12 configuration values Start*/
	#define		PIN_DIR_PORTA_12																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_12														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_12 == ENABLE)

	#define INTRP_TYPE_PORTA_12																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_12																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_12															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_12																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_12														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_12														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_12													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_12 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_12													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_12 configuration values End*/



	/*PORTA_13 configuration values Start*/
	#define		PIN_DIR_PORTA_13																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_13														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_13 == ENABLE)

	#define INTRP_TYPE_PORTA_13																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_13																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_13															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_13																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_13														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_13														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_13													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_13 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_13													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_13 configuration values End*/



	/*PORTA_14 configuration values Start*/
	#define		PIN_DIR_PORTA_14																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_14														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_14 == ENABLE)

	#define INTRP_TYPE_PORTA_14																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_14																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_14															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_14																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_14														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_14														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_14													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_14 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_14													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_14 configuration values End*/



	/*PORTA_15 configuration values Start*/
	#define		PIN_DIR_PORTA_15																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_15														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_15 == ENABLE)

	#define INTRP_TYPE_PORTA_15																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_15																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_15															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_15																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_15														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_15														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_15													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_15 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_15													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_15 configuration values End*/



	/*PORTA_16 configuration values Start*/
	#define		PIN_DIR_PORTA_16																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_16														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_16 == ENABLE)

	#define INTRP_TYPE_PORTA_16																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_16																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_16															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_16																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_16														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_16														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_16													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_16 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_16													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_16 configuration values End*/



	/*PORTA_17 configuration values Start*/
	#define		PIN_DIR_PORTA_17																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_17														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_17 == ENABLE)

	#define INTRP_TYPE_PORTA_17																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_17																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_17															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_17																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_17													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_17 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_17													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_17 configuration values End*/



	#if(S32K146 | S32K148 == TRUE)


	/*PORTA_18 configuration values Start*/
	#define		PIN_DIR_PORTA_18															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_18														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_18 == ENABLE)

	#define INTRP_TYPE_PORTA_18																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_18																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_18															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_18															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_18													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_18														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_18													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_18 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_18													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_18 configuration values End*/




	/*PORTA_19 configuration values Start*/
	#define		PIN_DIR_PORTA_19															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_19														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_19 == ENABLE)

	#define INTRP_TYPE_PORTA_19																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTA_19																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTA_19															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_19															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTA_19													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_19														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_19													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_19 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_19													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_19 configuration values End*/





	/*PORTA_20 configuration values Start*/
	#define		PIN_DIR_PORTA_20															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_20														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_20 == ENABLE)

	#define INTRP_TYPE_PORTA_20																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_20																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_20															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_20															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTA_20													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_20														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_20													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_20 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_20													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_20 configuration values End*/



	/*PORTA_21 configuration values Start*/
	#define		PIN_DIR_PORTA_21															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_21														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_21 == ENABLE)

	#define INTRP_TYPE_PORTA_21																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_21																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_21															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_21															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_21													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_21														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_21													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_21 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_21													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_21 configuration values End*/



	/*PORTA_22 configuration values Start*/
	#define		PIN_DIR_PORTA_22															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_22														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_22 == ENABLE)

	#define INTRP_TYPE_PORTA_22																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_22																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_22															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_22															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_22													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_22														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_22													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_22 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_22													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_22 configuration values End*/



	/*PORTA_23 configuration values Start*/
	#define		PIN_DIR_PORTA_23															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_23														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_23 == ENABLE)

	#define INTRP_TYPE_PORTA_23																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_23																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_23															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_23															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_23													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_23														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_23													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_23 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_23													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_23 configuration values End*/



	#endif /*S32K146 | S32K148 end*/

	#if(S32K148 == TRUE)

	/*PORTA_24 configuration values Start*/
	#define		PIN_DIR_PORTA_24															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_24														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_24 == ENABLE)

	#define INTRP_TYPE_PORTA_24																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_24																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_24															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_24															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_24													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_24														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_24													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_24 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_24													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_24 configuration values End*/



	/*PORTA_25 configuration values Start*/
	#define		PIN_DIR_PORTA_25															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_25														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_25 == ENABLE)

	#define INTRP_TYPE_PORTA_25																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_25																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTA_25															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_25																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTA_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_25													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_25 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_25													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_25 configuration values End*/




	/*PORTA_26 configuration values Start*/
	#define		PIN_DIR_PORTA_26																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_26														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_26 == ENABLE)

	#define INTRP_TYPE_PORTA_26																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_26																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_26															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_26																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTA_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_26													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_26 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_26													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_26 configuration values End*/



	/*PORTA_27 configuration values Start*/
	#define		PIN_DIR_PORTA_27															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_27														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_27 == ENABLE)

	#define INTRP_TYPE_PORTA_27																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_27																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTA_27															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_27															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTA_27													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_27														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_27													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_27 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_27													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_27 configuration values End*/



	/*PORTA_28 configuration values Start*/
	#define		PIN_DIR_PORTA_28															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_28														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_28 == ENABLE)

	#define INTRP_TYPE_PORTA_28																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTA_28																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTA_28															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_28															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTA_28													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_28														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_28													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_28 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_28													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_28 configuration values End*/



	/*PORTA_29 configuration values Start*/
	#define		PIN_DIR_PORTA_29															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_29														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_29 == ENABLE)

	#define INTRP_TYPE_PORTA_29																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTA_29																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTA_29															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_29															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTA_29													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_29														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_29													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_29 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_29													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_29 configuration values End*/



	/*PORTA_30 configuration values Start*/
	#define		PIN_DIR_PORTA_30															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_30														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_30 == ENABLE)

	#define INTRP_TYPE_PORTA_30																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTA_30																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTA_30															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_30															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTA_30													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_30														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_30													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_30 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_30													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_30 configuration values End*/




	/*PORTA_31 configuration values Start*/
	#define		PIN_DIR_PORTA_31															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTA_31														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTA_31 == ENABLE)

	#define INTRP_TYPE_PORTA_31																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTA_31																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTA_31															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTA_31															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTA_31													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTA_31														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTA_31													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTA_31 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTA_31													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTA_31 configuration values End*/

	#endif/*S32K148 End*/

	#endif


/**********Port B Start**********/

#if(ENABLE_PORT_B == TRUE)

	/*PORTB_0 configuration values Start*/
	#define		PIN_DIR_PORTB_0																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_0														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_0 == ENABLE)

	#define INTRP_TYPE_PORTB_0																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_0																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_0															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_0																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_0													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_0 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_0													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_0 configuration values End*/

	/*PORTB_1 configuration values Start*/
	#define		PIN_DIR_PORTB_1																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_1														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_1 == ENABLE)

	#define INTRP_TYPE_PORTB_1																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_1																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_1															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_1																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_1													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_1 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_1													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_1 configuration values End*/



	/*PORTB_2 configuration values Start*/
	#define		PIN_DIR_PORTB_2																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_2														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_2 == ENABLE)

	#define INTRP_TYPE_PORTB_2																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_2																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_2															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_2																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_2													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_2 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_2													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_2 configuration values End*/




	/*PORTB_3 configuration values Start*/
	#define		PIN_DIR_PORTB_3																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_3														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_3 == ENABLE)

	#define INTRP_TYPE_PORTB_3																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_3																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_3															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_3																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_3													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_3 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_3													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_3 configuration values End*/




	/*PORTB_4 configuration values Start*/
	#define		PIN_DIR_PORTB_4																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_4														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_4 == ENABLE)

	#define INTRP_TYPE_PORTB_4																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_4																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_4															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_4																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_4													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_4 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_4													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_4 configuration values End*/



	/*PORTB_5 configuration values Start*/
	#define		PIN_DIR_PORTB_5																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_5														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_5 == ENABLE)

	#define INTRP_TYPE_PORTB_5																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_5																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_5															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_5																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_5													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_5 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_5													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_5 configuration values End*/



	/*PORTB_6 configuration values Start*/
	#define		PIN_DIR_PORTB_6																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_6														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_6 == ENABLE)

	#define INTRP_TYPE_PORTB_6																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_6																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_6															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_6																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_6													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_6 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_6													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_6 configuration values End*/




	/*PORTB_7 configuration values Start*/
	#define		PIN_DIR_PORTB_7																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_7														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_7 == ENABLE)

	#define INTRP_TYPE_PORTB_7																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_7																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_7															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_7																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_7													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_7 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_7													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_7 configuration values End*/



	/*PORTB_8 configuration values Start*/
	#define		PIN_DIR_PORTB_8																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_8														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_8 == ENABLE)

	#define INTRP_TYPE_PORTB_8																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_8																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_8															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_8																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_8													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_8 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_8													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_8 configuration values End*/




	/*PORTB_9 configuration values Start*/
	#define		PIN_DIR_PORTB_9																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_9														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_9 == ENABLE)

	#define INTRP_TYPE_PORTB_9																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_9																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_9															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_9																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_9													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_9 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_9													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_9 configuration values End*/



	/*PORTB_10 configuration values Start*/
	#define		PIN_DIR_PORTB_10																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_10														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_10 == ENABLE)

	#define INTRP_TYPE_PORTB_10																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_10																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_10															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_10																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_10														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_10														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_10													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_10 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_10													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_10 configuration values End*/



	/*PORTB_11 configuration values Start*/
	#define		PIN_DIR_PORTB_11															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_11														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_11 == ENABLE)

	#define INTRP_TYPE_PORTB_11																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_11																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_11															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_11																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_11														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_11														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_11													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_11 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_11													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_11 configuration values End*/



	/*PORTB_12 configuration values Start*/
	#define		PIN_DIR_PORTB_12																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_12														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_12 == ENABLE)

	#define INTRP_TYPE_PORTB_12																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_12																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_12															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_12																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_12														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_12														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_12													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_12 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_12													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_12 configuration values End*/



	/*PORTB_13 configuration values Start*/
	#define		PIN_DIR_PORTB_13																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_13														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_13 == ENABLE)

	#define INTRP_TYPE_PORTB_13																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_13																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_13															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_13																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_13														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_13														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_13													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_13 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_13													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_13 configuration values End*/



	/*PORTB_14 configuration values Start*/
	#define		PIN_DIR_PORTB_14																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_14														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_14 == ENABLE)

	#define INTRP_TYPE_PORTB_14																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_14																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_14															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_14																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_14														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_14														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_14													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_14 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_14													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_14 configuration values End*/



	/*PORTB_15 configuration values Start*/
	#define		PIN_DIR_PORTB_15																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_15														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_15 == ENABLE)

	#define INTRP_TYPE_PORTB_15																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_15																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_15															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_15																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_15														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_15														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_15													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_15 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_15													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_15 configuration values End*/



	/*PORTB_16 configuration values Start*/
	#define		PIN_DIR_PORTB_16																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_16														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_16 == ENABLE)

	#define INTRP_TYPE_PORTB_16																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_16																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_16															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_16																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_16														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_16														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_16													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_16 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_16													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_16 configuration values End*/



	/*PORTB_17 configuration values Start*/
	#define		PIN_DIR_PORTB_17																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_17														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_17 == ENABLE)

	#define INTRP_TYPE_PORTB_17																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_17																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_17															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_17																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_17													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_17 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_17													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_17 configuration values End*/



	#if(S32K146 | S32K148 == TRUE)


	/*PORTB_18 configuration values Start*/
	#define		PIN_DIR_PORTB_18															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_18														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_18 == ENABLE)

	#define INTRP_TYPE_PORTB_18																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_18																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_18															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_18															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_18													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_18														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_18													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_18 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_18													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_18 configuration values End*/




	/*PORTB_19 configuration values Start*/
	#define		PIN_DIR_PORTB_19															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_19														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_19 == ENABLE)

	#define INTRP_TYPE_PORTB_19																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTB_19																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTB_19															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_19															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTB_19													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_19														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_19													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_19 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_19													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_19 configuration values End*/





	/*PORTB_20 configuration values Start*/
	#define		PIN_DIR_PORTB_20															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_20														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_20 == ENABLE)

	#define INTRP_TYPE_PORTB_20																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_20																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_20															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_20															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTB_20													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_20														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_20													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_20 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_20													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_20 configuration values End*/



	/*PORTB_21 configuration values Start*/
	#define		PIN_DIR_PORTB_21															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_21														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_21 == ENABLE)

	#define INTRP_TYPE_PORTB_21																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_21																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_21															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_21															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_21													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_21														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_21													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_21 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_21													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_21 configuration values End*/



	/*PORTB_22 configuration values Start*/
	#define		PIN_DIR_PORTB_22															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_22														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_22 == ENABLE)

	#define INTRP_TYPE_PORTB_22																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_22																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_22															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_22															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_22													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_22														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_22													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_22 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_22													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_22 configuration values End*/



	/*PORTB_23 configuration values Start*/
	#define		PIN_DIR_PORTB_23															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_23														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_23 == ENABLE)

	#define INTRP_TYPE_PORTB_23																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_23																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_23															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_23															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_23													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_23														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_23													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_23 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_23													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_23 configuration values End*/



	#endif /*S32K146 | S32K148 end*/

	#if(S32K148 == TRUE)

	/*PORTB_24 configuration values Start*/
	#define		PIN_DIR_PORTB_24															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_24														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_24 == ENABLE)

	#define INTRP_TYPE_PORTB_24																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_24																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_24															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_24															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_24													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_24														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_24													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_24 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_24													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_24 configuration values End*/



	/*PORTB_25 configuration values Start*/
	#define		PIN_DIR_PORTB_25															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_25														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_25 == ENABLE)

	#define INTRP_TYPE_PORTB_25																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_25																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTB_25															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_25																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTB_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_25													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_25 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_25													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_25 configuration values End*/




	/*PORTB_26 configuration values Start*/
	#define		PIN_DIR_PORTB_26																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_26														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_26 == ENABLE)

	#define INTRP_TYPE_PORTB_26																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_26																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_26															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_26																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTB_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_26													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_26 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_26													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_26 configuration values End*/



	/*PORTB_27 configuration values Start*/
	#define		PIN_DIR_PORTB_27															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_27														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_27 == ENABLE)

	#define INTRP_TYPE_PORTB_27																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_27																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTB_27															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_27															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTB_27													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_27														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_27													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_27 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_27													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_27 configuration values End*/



	/*PORTB_28 configuration values Start*/
	#define		PIN_DIR_PORTB_28															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_28														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_28 == ENABLE)

	#define INTRP_TYPE_PORTB_28																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTB_28																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTB_28															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_28															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTB_28													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_28														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_28													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_28 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_28													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_28 configuration values End*/



	/*PORTB_29 configuration values Start*/
	#define		PIN_DIR_PORTB_29															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_29														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_29 == ENABLE)

	#define INTRP_TYPE_PORTB_29																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTB_29																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTB_29															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_29															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTB_29													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_29														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_29													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_29 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_29													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_29 configuration values End*/



	/*PORTB_30 configuration values Start*/
	#define		PIN_DIR_PORTB_30															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_30														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_30 == ENABLE)

	#define INTRP_TYPE_PORTB_30																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTB_30																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTB_30															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_30															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTB_30													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_30														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_30													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_30 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_30													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_30 configuration values End*/




	/*PORTB_31 configuration values Start*/
	#define		PIN_DIR_PORTB_31															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTB_31														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTB_31 == ENABLE)

	#define INTRP_TYPE_PORTB_31																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTB_31																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTB_31															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTB_31															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTB_31													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTB_31														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTB_31													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTB_31 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTB_31													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTB_31 configuration values End*/

	#endif/*S32K148 End*/






#endif /* Port B End*/

#if(ENABLE_PORT_C == TRUE)

/*PORTC_0 configuration values Start*/
	#define		PIN_DIR_PORTC_0																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_0														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_0 == ENABLE)

	#define INTRP_TYPE_PORTC_0																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_0																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_0															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_0																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_0													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_0													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTC_0 configuration values End*/

	/*PORTC_1 configuration values Start*/
	#define		PIN_DIR_PORTC_1																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_1														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_1 == ENABLE)

	#define INTRP_TYPE_PORTC_1																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_1																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_1															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_1																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_1													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_1													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_1 configuration values End*/



	/*PORTC_2 configuration values Start*/
	#define		PIN_DIR_PORTC_2																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_2														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_2 == ENABLE)

	#define INTRP_TYPE_PORTC_2																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_2																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_2															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_2																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_2													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_2													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_2 configuration values End*/




	/*PORTC_3 configuration values Start*/
	#define		PIN_DIR_PORTC_3																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_3														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_3 == ENABLE)

	#define INTRP_TYPE_PORTC_3																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_3																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_3															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_3																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_3													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_3													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_3 configuration values End*/



#if(DEBUG_MODE == FALSE)
	/*PORTC_4 configuration values Start*//* Note 3. Also used for JTAG CLK pin for Debugging*/
	#define		PIN_DIR_PORTC_4																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_4														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_4 == ENABLE)

	#define INTRP_TYPE_PORTC_4																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_4																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_4															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_4																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_4													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_4													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_4 configuration values End*/
#endif


	/*PORTC_5 configuration values Start*/
	#define		PIN_DIR_PORTC_5																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_5														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_5 == ENABLE)

	#define INTRP_TYPE_PORTC_5																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_5																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTC_5															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_5																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_5													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_5													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_5 configuration values End*/



	/*PORTC_6 configuration values Start*/
	#define		PIN_DIR_PORTC_6																INPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	INTRP_TYPE_PORTC_6															INRTP_STATUS_FLG_ISF_DISABLED
	#define 	LOCK_REG_PORTC_6															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_6																CHIPSPECIFIC_1		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_6													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_6													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_6 configuration values End*/


	/*PORTC_7 configuration values Start*/
	#define		PIN_DIR_PORTC_7																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	INTRP_TYPE_PORTC_7															INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#define 	LOCK_REG_PORTC_7															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_7																CHIPSPECIFIC_1		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_7													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_7													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_7 configuration values End*/



	/*PORTC_8 configuration values Start*/
	#define		PIN_DIR_PORTC_8																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	INTRP_TYPE_PORTC_8															INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#define 	LOCK_REG_PORTC_8															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_8																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_8													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_8													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_8 configuration values End*/




	/*PORTC_9 configuration values Start*/
	#define		PIN_DIR_PORTC_9																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_9														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_9 == ENABLE)

	#define INTRP_TYPE_PORTC_9																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_9																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_9															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_9																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_9													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_9													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_9 configuration values End*/



	/*PORTC_10 configuration values Start*/
	#define		PIN_DIR_PORTC_10															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_10														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_10 == ENABLE)

	#define INTRP_TYPE_PORTC_10																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_10																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_10															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_10															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_10													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_10														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_10													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_10													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_10 configuration values End*/



	/*PORTC_11 configuration values Start*/
	#define		PIN_DIR_PORTC_11															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_11														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_11 == ENABLE)
		#define INTRP_TYPE_PORTC_11																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/
	#else
		#define INTRP_TYPE_PORTC_11																INRTP_STATUS_FLG_ISF_DISABLED           /*Not to be Modified*/
	#endif

	#define 	LOCK_REG_PORTC_11															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_11															CHIPSPECIFIC_3		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_11													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_11														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_11													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_11													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTC_11 configuration values End*/



	/*PORTC_12 configuration values Start*/
	#define		PIN_DIR_PORTC_12															INPUT       /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_12														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTC_12 == ENABLE)
		#define INTRP_TYPE_PORTC_12																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/
	#else
		#define INTRP_TYPE_PORTC_12																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#endif

	#define 	LOCK_REG_PORTC_12															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_12															CHIPSPECIFIC_3		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_12													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_12														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_12													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_12													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_12 configuration values End*/



	/*PORTC_13 configuration values Start*/
	#define		PIN_DIR_PORTC_13															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_13														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTC_13 == ENABLE)
		#define INTRP_TYPE_PORTC_13																ISF_FLG_UPON_INTRPT_RISING_EDGE			/* Cfg values Dev. Note 2*/
	#else
		#define INTRP_TYPE_PORTC_13																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#endif
	#define 	LOCK_REG_PORTC_13															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_13															CHIPSPECIFIC_3		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_13													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_13														DISABLE      /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_13													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_13													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_13 configuration values End*/



	/*PORTC_14 configuration values Start*/
	#define		PIN_DIR_PORTC_14																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_14														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_14 == ENABLE)

	#define INTRP_TYPE_PORTC_14																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_14																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_14															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_14															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_14													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_14														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_14													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_14													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTC_14 configuration values End*/



	/*PORTC_15 configuration values Start*/
	#define		PIN_DIR_PORTC_15															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_15														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_15 == ENABLE)

	#define INTRP_TYPE_PORTC_15																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_15																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTC_15															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_15															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_15													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_15														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_15													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_15													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_15 configuration values End*/



	/*PORTC_16 configuration values Start*/
	#define		PIN_DIR_PORTC_16															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_16														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_16 == ENABLE)

	#define INTRP_TYPE_PORTC_16																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_16																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTC_16															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_16															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_16													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_16														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_16													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_16													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_16 configuration values End*/



	/*PORTC_17 configuration values Start*/
	#define		PIN_DIR_PORTC_17															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTC_17 == ENABLE)

	#define INTRP_TYPE_PORTC_17																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_17																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_17															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_17															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_17													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_17													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_17													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_17 configuration values End*/



	#if(S32K146 | S32K148 == TRUE)


	/*PORTC_18 configuration values Start*/
	#define		PIN_DIR_PORTC_18															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_18														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_18 == ENABLE)

	#define INTRP_TYPE_PORTC_18																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_18																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_18															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_18															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_18													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_18														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_18													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTC_18 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTC_18													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTC_18 configuration values End*/




	/*PORTC_19 configuration values Start*/
	#define		PIN_DIR_PORTC_19															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_19														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_19 == ENABLE)

	#define INTRP_TYPE_PORTC_19																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTC_19																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTC_19															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_19															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_19													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_19														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_19													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTC_19 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTC_19													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTC_19 configuration values End*/





	/*PORTC_20 configuration values Start*/
	#define		PIN_DIR_PORTC_20															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_20														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_20 == ENABLE)

	#define INTRP_TYPE_PORTC_20																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_20																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_20															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_20															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_20													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_20														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_20													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTC_20 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTC_20													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTC_20 configuration values End*/



	/*PORTC_21 configuration values Start*/
	#define		PIN_DIR_PORTC_21															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_21														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_21 == ENABLE)

	#define INTRP_TYPE_PORTC_21																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_21																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_21															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_21															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_21													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_21														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_21													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTC_21 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTC_21													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTC_21 configuration values End*/



	/*PORTC_22 configuration values Start*/
	#define		PIN_DIR_PORTC_22															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_22														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_22 == ENABLE)

	#define INTRP_TYPE_PORTC_22																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_22																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_22															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_22															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_22													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_22														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_22													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_22													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_22 configuration values End*/



	/*PORTC_23 configuration values Start*/
	#define		PIN_DIR_PORTC_23															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_23														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_23 == ENABLE)

	#define INTRP_TYPE_PORTC_23																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_23																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_23															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_23															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_23													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_23														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_23													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_23													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTC_23 configuration values End*/



	#endif /*S32K146 | S32K148 end*/

	#if(S32K148 == TRUE)

	/*PORTC_24 configuration values Start*/
	#define		PIN_DIR_PORTC_24															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_24														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_24 == ENABLE)

	#define INTRP_TYPE_PORTC_24																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_24																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_24															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_24															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_24													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_24														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_24													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_24													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_24 configuration values End*/



	/*PORTC_25 configuration values Start*/
	#define		PIN_DIR_PORTC_25															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_25														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_25 == ENABLE)

	#define INTRP_TYPE_PORTC_25																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_25																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTC_25															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_25																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_25													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTC_25 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTC_25													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTC_25 configuration values End*/




	/*PORTC_26 configuration values Start*/
	#define		PIN_DIR_PORTC_26																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_26														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_26 == ENABLE)

	#define INTRP_TYPE_PORTC_26																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_26																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_26															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_26																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTC_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_26													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTC_26 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTC_26													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTC_26 configuration values End*/



	/*PORTC_27 configuration values Start*/
	#define		PIN_DIR_PORTC_27															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_27														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_27 == ENABLE)

	#define INTRP_TYPE_PORTC_27																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_27																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTC_27															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_27															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_27													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_27														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_27													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTC_27 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTC_27													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTC_27 configuration values End*/



	/*PORTC_28 configuration values Start*/
	#define		PIN_DIR_PORTC_28															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_28														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_28 == ENABLE)

	#define INTRP_TYPE_PORTC_28																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTC_28																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTC_28															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_28															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_28													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_28														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_28													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_28													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_28 configuration values End*/



	/*PORTC_29 configuration values Start*/
	#define		PIN_DIR_PORTC_29															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_29														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_29 == ENABLE)

	#define INTRP_TYPE_PORTC_29																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTC_29																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTC_29															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_29															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_29													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_29														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_29													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_29													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTC_29 configuration values End*/



	/*PORTC_30 configuration values Start*/
	#define		PIN_DIR_PORTC_30															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_30														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_30 == ENABLE)

	#define INTRP_TYPE_PORTC_30																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTC_30																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTC_30															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_30															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_30													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_30														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_30													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTC_30													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTC_30 configuration values End*/




	/*PORTC_31 configuration values Start*/
	#define		PIN_DIR_PORTC_31															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTC_31														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTC_31 == ENABLE)

	#define INTRP_TYPE_PORTC_31																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTC_31																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTC_31															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTC_31															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTC_31													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTC_31														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTC_31													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTC_31 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTC_31													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTC_31 configuration values End*/

	#endif/*S32K148 End*/


#if(ENABLE_PORT_D == TRUE)

	/*PORTD_0 configuration values Start*/
	#define		PIN_DIR_PORTD_0																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	INTRP_TYPE_PORTD_0															INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#define 	LOCK_REG_PORTD_0															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_0																CHIPSPECIFIC_1		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_0														ENABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_0													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_0													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED*/
	/*PORTD_0 configuration values End*/

	/*PORTD_1 configuration values Start*/
	#define		PIN_DIR_PORTD_1																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	INTRP_TYPE_PORTD_1															INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#define 	LOCK_REG_PORTD_1															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_1																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_1													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_1													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTD_1 configuration values End*/

	/*PORTD_2 configuration values Start*/
	#define		PIN_DIR_PORTD_2																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_2														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_2 == ENABLE)

	#define INTRP_TYPE_PORTD_2																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_2																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_2															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_2																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_2													DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(PULL_RESISTOR_ON_PORTD_2 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_2													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_2 configuration values End*/

	/*PORTD_3 configuration values Start*/
	#define		PIN_DIR_PORTD_3																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTD_3 == ENABLE)

	#define INTRP_TYPE_PORTD_3																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_3																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_3															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_3																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_3													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_3													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTD_3 configuration values End*/

	/*PORTD_4 configuration values Start*/
	#define		PIN_DIR_PORTD_4																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTD_4 == ENABLE)

	#define INTRP_TYPE_PORTD_4																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_4																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif
	#define 	LOCK_REG_PORTD_4															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_4																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_4													DISABLE     /* Cfg values ENABLE, DISABLE */
    #define 	PULLUP_OR_DOWN_ON_PORTD_4													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTD_4 configuration values End*/

	/*PORTD_5 configuration values Start*/
	#define		PIN_DIR_PORTD_5																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTD_5 == ENABLE)

	#define INTRP_TYPE_PORTD_5																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_5																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
    #endif
	#define 	LOCK_REG_PORTD_5															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_5																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_5													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_5													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTD_5 configuration values End*/

	/*PORTD_6 configuration values Start*/
	#define		PIN_DIR_PORTD_6																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTD_6 == ENABLE)

	#define INTRP_TYPE_PORTD_6																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_6																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif
	#define 	LOCK_REG_PORTD_6															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_6																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_6													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_6													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_6 configuration values End*/




	/*PORTD_7 configuration values Start*/
	#define		PIN_DIR_PORTD_7																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTD_7 == ENABLE)

	#define INTRP_TYPE_PORTD_7																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_7																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif
	#define 	LOCK_REG_PORTD_7															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_7																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_7													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_7													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTD_7 configuration values End*/



	/*PORTD_8 configuration values Start*/
	#define		PIN_DIR_PORTD_8																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTD_8 == ENABLE)

	#define INTRP_TYPE_PORTD_8																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_8																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#endif
	#define 	LOCK_REG_PORTD_8															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_8																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_8													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_8													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_8 configuration values End*/




	/*PORTD_9 configuration values Start*/
	#define		PIN_DIR_PORTD_9																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTD_9 == ENABLE)

	#define INTRP_TYPE_PORTD_9																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_9																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_9															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_9																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_9													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_9													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_9 configuration values End*/



	/*PORTD_10 configuration values Start*/
	#define		PIN_DIR_PORTD_10															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_10														DISABLE     /* Cfg values ENABLE, DISABLE */
	#if(INTRP_SVC_ON_PORTD_10 == ENABLE)

	#define INTRP_TYPE_PORTD_10																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_10																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_10															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_10															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_10													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_10														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_10													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_10													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_10 configuration values End*/



	/*PORTD_11 configuration values Start*/
	#define		PIN_DIR_PORTD_11															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_11														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_11 == ENABLE)

	#define INTRP_TYPE_PORTD_11																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_11																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_11															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_11															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_11													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_11														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_11													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_11													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_11 configuration values End*/



	/*PORTD_12 configuration values Start*/
	#define		PIN_DIR_PORTD_12															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_12														ENABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_12 == ENABLE)

	#define INTRP_TYPE_PORTD_12																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_12																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_12															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_12															GPIO		/* Cfg values Dev. Note 2 */    // ---> FTM_0CH1
	#define 	DRIVE_STRNTH_ON_PORTD_12													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_12														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_12													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_12													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_12 configuration values End*/



	/*PORTD_13 configuration values Start*/
	#define		PIN_DIR_PORTD_13															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_13														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_13 == ENABLE)

	#define INTRP_TYPE_PORTD_13																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_13																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_13															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_13															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_13													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_13														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_13													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_13													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_13 configuration values End*/



	/*PORTD_14 configuration values Start*/
	#define		PIN_DIR_PORTD_14															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_14														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_14 == ENABLE)

	#define INTRP_TYPE_PORTD_14																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_14																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_14															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_14															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_14													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_14														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_14													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_14													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_14 configuration values End*/



	/*PORTD_15 configuration values Start*/
	#define		PIN_DIR_PORTD_15															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_15														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	INTRP_TYPE_PORTD_15															INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#define 	LOCK_REG_PORTD_15															FALSE      	/* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_15															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_15													ENABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_15														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_15													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_15													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_15 configuration values End*/



	/*PORTD_16 configuration values Start*/
	#define		PIN_DIR_PORTD_16															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_16														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	INTRP_TYPE_PORTD_16														    INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#define 	LOCK_REG_PORTD_16															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_16															CHIPSPECIFIC_1		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_16													ENABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_16														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_16													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_16													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */
	/*PORTD_16 configuration values End*/


	/*PORTD_17 configuration values Start*/
	#define		PIN_DIR_PORTD_17															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	INTRP_TYPE_PORTD_17															INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/
	#define 	LOCK_REG_PORTD_17															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_17															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_17													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_17													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_17													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_17 configuration values End*/



#if(S32K146 | S32K148 == TRUE)


	/*PORTD_18 configuration values Start*/
	#define		PIN_DIR_PORTD_18															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_18														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_18 == ENABLE)

	#define INTRP_TYPE_PORTD_18																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_18																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_18															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_18															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTD_18													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_18														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_18													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_18													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_18 configuration values End*/


	/*PORTD_19 configuration values Start*/
	#define		PIN_DIR_PORTD_19															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_19														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_19 == ENABLE)

	#define INTRP_TYPE_PORTD_19																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTD_19																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_19															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_19															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_19													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_19														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_19													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULLUP_OR_DOWN_ON_PORTD_19													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	/*PORTD_19 configuration values End*/





	/*PORTD_20 configuration values Start*/
	#define		PIN_DIR_PORTD_20															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_20														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_20 == ENABLE)

	#define INTRP_TYPE_PORTD_20																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_20																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_20															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_20															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_20													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_20														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_20													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_20 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_20													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_20 configuration values End*/



	/*PORTD_21 configuration values Start*/
	#define		PIN_DIR_PORTD_21															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_21														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_21 == ENABLE)

	#define INTRP_TYPE_PORTD_21																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_21																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_21															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_21															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTD_21													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_21														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_21													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_21 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_21													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_21 configuration values End*/



	/*PORTD_22 configuration values Start*/
	#define		PIN_DIR_PORTD_22															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_22														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_22 == ENABLE)

	#define INTRP_TYPE_PORTD_22																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_22																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_22															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_22															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTD_22													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_22														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_22													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_22 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_22													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_22 configuration values End*/



	/*PORTD_23 configuration values Start*/
	#define		PIN_DIR_PORTD_23															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_23														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_23 == ENABLE)

	#define INTRP_TYPE_PORTD_23																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_23																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_23															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_23															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTD_23													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_23														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_23													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_23 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_23													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_23 configuration values End*/



	#endif /*S32K146 | S32K148 end*/

	#if(S32K148 == TRUE)

	/*PORTD_24 configuration values Start*/
	#define		PIN_DIR_PORTD_24															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_24														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_24 == ENABLE)

	#define INTRP_TYPE_PORTD_24																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_24																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_24															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_24															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTD_24													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_24														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_24													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_24 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_24													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_24 configuration values End*/



	/*PORTD_25 configuration values Start*/
	#define		PIN_DIR_PORTD_25															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_25														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_25 == ENABLE)

	#define INTRP_TYPE_PORTD_25																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_25																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_25															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_25																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_25													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_25 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_25													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_25 configuration values End*/




	/*PORTD_26 configuration values Start*/
	#define		PIN_DIR_PORTD_26																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_26														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_26 == ENABLE)

	#define INTRP_TYPE_PORTD_26																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_26																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_26															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_26																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTD_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_26													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_26 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_26													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_26 configuration values End*/



	/*PORTD_27 configuration values Start*/
	#define		PIN_DIR_PORTD_27															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_27														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_27 == ENABLE)

	#define INTRP_TYPE_PORTD_27																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_27																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTD_27															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_27															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_27													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_27														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_27													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_27 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_27													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_27 configuration values End*/



	/*PORTD_28 configuration values Start*/
	#define		PIN_DIR_PORTD_28															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_28														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_28 == ENABLE)

	#define INTRP_TYPE_PORTD_28																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTD_28																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_28															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_28															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_28													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_28														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_28													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_28 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_28													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_28 configuration values End*/



	/*PORTD_29 configuration values Start*/
	#define		PIN_DIR_PORTD_29															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_29														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_29 == ENABLE)

	#define INTRP_TYPE_PORTD_29																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTD_29																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_29															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_29															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_29													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_29														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_29													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_29 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_29													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_29 configuration values End*/



	/*PORTD_30 configuration values Start*/
	#define		PIN_DIR_PORTD_30															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_30														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_30 == ENABLE)

	#define INTRP_TYPE_PORTD_30																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTD_30																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_30															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_30															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_30													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_30														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_30													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_30 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_30													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_30 configuration values End*/




	/*PORTD_31 configuration values Start*/
	#define		PIN_DIR_PORTD_31															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTD_31														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTD_31 == ENABLE)

	#define INTRP_TYPE_PORTD_31																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTD_31																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTD_31															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTD_31															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTD_31													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTD_31														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTD_31													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTD_31 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTD_31													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTD_31 configuration values End*/

	#endif/*S32K148 End*/

#endif

#if(ENABLE_PORT_E == TRUE)

	/*PORTE_0 configuration values Start*/
	#define		PIN_DIR_PORTE_0																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_0														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_0 == ENABLE)

	#define INTRP_TYPE_PORTE_0																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_0																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_0															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_0																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_0														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_0													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_0 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_0													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_0 configuration values End*/

	/*PORTE_1 configuration values Start*/
	#define		PIN_DIR_PORTE_1																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_1														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_1 == ENABLE)

	#define INTRP_TYPE_PORTE_1																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_1																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_1															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_1																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_1														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_1													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_1 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_1													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_1 configuration values End*/



	/*PORTE_2 configuration values Start*/
	#define		PIN_DIR_PORTE_2																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_2														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_2 == ENABLE)

	#define INTRP_TYPE_PORTE_2																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_2																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_2															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_2																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_2														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_2													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_2 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_2													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_2 configuration values End*/




	/*PORTE_3 configuration values Start*/
	#define		PIN_DIR_PORTE_3																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_3														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_3 == ENABLE)

	#define INTRP_TYPE_PORTE_3																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_3																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_3															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_3																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_3														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_3													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_3 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_3													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_3 configuration values End*/




	/*PORTE_4 configuration values Start*/
	#define		PIN_DIR_PORTE_4																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_4														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_4 == ENABLE)

	#define INTRP_TYPE_PORTE_4																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_4																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_4															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_4																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_4														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_4													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_4 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_4													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_4 configuration values End*/



	/*PORTE_5 configuration values Start*/
	#define		PIN_DIR_PORTE_5																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_5														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_5 == ENABLE)

	#define INTRP_TYPE_PORTE_5																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_5																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_5															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_5																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_5														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_5													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_5 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_5													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_5 configuration values End*/



	/*PORTE_6 configuration values Start*/
	#define		PIN_DIR_PORTE_6																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_6														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_6 == ENABLE)

	#define INTRP_TYPE_PORTE_6																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_6																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_6															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_6																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_6														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_6													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_6 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_6													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_6 configuration values End*/




	/*PORTE_7 configuration values Start*/
	#define		PIN_DIR_PORTE_7																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_7														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_7 == ENABLE)

	#define INTRP_TYPE_PORTE_7																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_7																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_7															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_7																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_7														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_7													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_7 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_7													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_7 configuration values End*/



	/*PORTE_8 configuration values Start*/
	#define		PIN_DIR_PORTE_8																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_8														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_8 == ENABLE)

	#define INTRP_TYPE_PORTE_8																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_8																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_8															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_8																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_8														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_8													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_8 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_8													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_8 configuration values End*/




	/*PORTE_9 configuration values Start*/
	#define		PIN_DIR_PORTE_9																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_9														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_9 == ENABLE)

	#define INTRP_TYPE_PORTE_9																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_9																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_9															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_9																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_9														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_9													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_9 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_9													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_9 configuration values End*/



	/*PORTE_10 configuration values Start*/
	#define		PIN_DIR_PORTE_10																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_10														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_10 == ENABLE)

	#define INTRP_TYPE_PORTE_10																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_10																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_10															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_10																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_10														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_10														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_10													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_10 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_10													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_10 configuration values End*/



	/*PORTE_11 configuration values Start*/
	#define		PIN_DIR_PORTE_11																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_11														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_11 == ENABLE)

	#define INTRP_TYPE_PORTE_11																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_11																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_11															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_11																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_11														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_11														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_11													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_11 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_11													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_11 configuration values End*/



	/*PORTE_12 configuration values Start*/
	#define		PIN_DIR_PORTE_12																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_12														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_12 == ENABLE)

	#define INTRP_TYPE_PORTE_12																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_12																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_12															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_12																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_12														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_12														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_12													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_12 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_12													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_12 configuration values End*/



	/*PORTE_13 configuration values Start*/
	#define		PIN_DIR_PORTE_13																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_13														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_13 == ENABLE)

	#define INTRP_TYPE_PORTE_13																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_13																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_13															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_13																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_13														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_13														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_13													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_13 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_13													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_13 configuration values End*/



	/*PORTE_14 configuration values Start*/
	#define		PIN_DIR_PORTE_14																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_14														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_14 == ENABLE)

	#define INTRP_TYPE_PORTE_14																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_14																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_14															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_14																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_14														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_14														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_14													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_14 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_14													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_14 configuration values End*/



	/*PORTE_15 configuration values Start*/
	#define		PIN_DIR_PORTE_15																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_15														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_15 == ENABLE)

	#define INTRP_TYPE_PORTE_15																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_15																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_15															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_15																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_15														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_15														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_15													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_15 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_15													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_15 configuration values End*/



	/*PORTE_16 configuration values Start*/
	#define		PIN_DIR_PORTE_16																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_16														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_16 == ENABLE)

	#define INTRP_TYPE_PORTE_16																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_16																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_16															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_16																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_16														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_16														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_16													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_16 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_16													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_16 configuration values End*/



	/*PORTE_17 configuration values Start*/
	#define		PIN_DIR_PORTE_17																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_17														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_17 == ENABLE)

	#define INTRP_TYPE_PORTE_17																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_17																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_17															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_17																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_17														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_17													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_17 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_17													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_17 configuration values End*/



#if(S32K146 | S32K148 == TRUE)  /* (S32K146 | S32K148 == TRUE) */


	/*PORTE_18 configuration values Start*/
	#define		PIN_DIR_PORTE_18															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_18														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_18 == ENABLE)

	#define INTRP_TYPE_PORTE_18																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_18																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_18															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_18															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_18													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_18														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_18													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_18 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_18													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_18 configuration values End*/




	/*PORTE_19 configuration values Start*/
	#define		PIN_DIR_PORTE_19															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_19														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_19 == ENABLE)

	#define INTRP_TYPE_PORTE_19																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTE_19																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTE_19															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_19															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTE_19													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_19														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_19													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_19 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_19													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_19 configuration values End*/





	/*PORTE_20 configuration values Start*/
	#define		PIN_DIR_PORTE_20															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_20														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_20 == ENABLE)

	#define INTRP_TYPE_PORTE_20																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_20																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_20															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_20															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTE_20													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_20														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_20													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_20 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_20													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_20 configuration values End*/



	/*PORTE_21 configuration values Start*/
	#define		PIN_DIR_PORTE_21															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_21														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_21 == ENABLE)

	#define INTRP_TYPE_PORTE_21																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_21																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_21															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_21															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_21													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_21														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_21													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_21 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_21													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_21 configuration values End*/



	/*PORTE_22 configuration values Start*/
	#define		PIN_DIR_PORTE_22															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_22														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_22 == ENABLE)

	#define INTRP_TYPE_PORTE_22																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_22																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_22															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_22															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_22													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_22														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_22													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_22 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_22													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_22 configuration values End*/



	/*PORTE_23 configuration values Start*/
	#define		PIN_DIR_PORTE_23															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_23														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_23 == ENABLE)

	#define INTRP_TYPE_PORTE_23																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_23																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_23															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_23															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_23													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_23														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_23													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_23 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_23													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_23 configuration values End*/



#endif /*S32K146 | S32K148 end*/

#if(S32K148 == TRUE) /*S32K146 Start*/

	/*PORTE_24 configuration values Start*/
	#define		PIN_DIR_PORTE_24															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_24														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_24 == ENABLE)

	#define INTRP_TYPE_PORTE_24																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_24																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_24															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_24															GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_24													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_24														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_24													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_24 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_24													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_24 configuration values End*/



	/*PORTE_25 configuration values Start*/
	#define		PIN_DIR_PORTE_25															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_25														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_25 == ENABLE)

	#define INTRP_TYPE_PORTE_25																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_25																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTE_25															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_25																GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTE_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_25														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_25													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_25 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_25													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_25 configuration values End*/




	/*PORTE_26 configuration values Start*/
	#define		PIN_DIR_PORTE_26																OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_26														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_26 == ENABLE)

	#define INTRP_TYPE_PORTE_26																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_26																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_26															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_26																GPIO		/* Cfg values Dev. Note 2 */

	#define 	DRIVE_STRNTH_ON_PORTE_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_26														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_26													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_26 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_26													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_26 configuration values End*/



	/*PORTE_27 configuration values Start*/
	#define		PIN_DIR_PORTE_27															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_27														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_27 == ENABLE)

	#define INTRP_TYPE_PORTE_27																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_27																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif


	#define 	LOCK_REG_PORTE_27															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_27															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTE_27													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_27														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_27													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_27 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_27													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_27 configuration values End*/



	/*PORTE_28 configuration values Start*/
	#define		PIN_DIR_PORTE_28															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_28														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_28 == ENABLE)

	#define INTRP_TYPE_PORTE_28																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/


	#else

	#define INTRP_TYPE_PORTE_28																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTE_28															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_28															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTE_28													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_28														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_28													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_28 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_28													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_28 configuration values End*/



	/*PORTE_29 configuration values Start*/
	#define		PIN_DIR_PORTE_29															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_29														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_29 == ENABLE)

	#define INTRP_TYPE_PORTE_29																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTE_29																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTE_29															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_29															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTE_29													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_29														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_29													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_29 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_29													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_29 configuration values End*/



	/*PORTE_30 configuration values Start*/
	#define		PIN_DIR_PORTE_30															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_30														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_30 == ENABLE)

	#define INTRP_TYPE_PORTE_30																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTE_30																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTE_30															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_30															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTE_30													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_30														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_30													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_30 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_30													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_30 configuration values End*/




	/*PORTE_31 configuration values Start*/
	#define		PIN_DIR_PORTE_31															OUTPUT      /* Cfg values INPUT, OUTPUT, NOTUSED*/
	#define 	INTRP_SVC_ON_PORTE_31														DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(INTRP_SVC_ON_PORTE_31 == ENABLE)

	#define INTRP_TYPE_PORTE_31																ISF_FLG_UPON_INTRPT_BOTH_EDGES			/* Cfg values Dev. Note 2*/

	#else

	#define INTRP_TYPE_PORTE_31																INRTP_STATUS_FLG_ISF_DISABLED          /*Not to be Modified*/

	#endif

	#define 	LOCK_REG_PORTE_31															FALSE       /* Cfg values TRUE, FALSE */
	#define     PIN_MUX_PORTE_31															GPIO		/* Cfg values Dev. Note 2 */
	#define 	DRIVE_STRNTH_ON_PORTE_31													DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PASSIVEFIL_ON_PORTE_31														DISABLE     /* Cfg values ENABLE, DISABLE */
	#define 	PULL_RESISTOR_ON_PORTE_31													DISABLE     /* Cfg values ENABLE, DISABLE */

	#if(PULL_RESISTOR_ON_PORTE_31 == ENABLE)

	#define 	PULLUP_OR_DOWN_ON_PORTE_31													PULL_UP     /* Cfg values PULL_UP, PULL_DWN allowed only if PULL_RESISTOR_ON_PORTx_n is ENABLED */

	#endif
	/*PORTE_31 configuration values End*/

#endif/*S32K148 End*/

#endif/*Port E End*/



#endif /* PORT_CFG_H_ */
