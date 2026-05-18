/*
 * Copyright (c) 2014 - 2016, Freescale Semiconductor, Inc.
 * Copyright (c) 2016 - 2018, NXP.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * Description:
 * =====================================================================
 * S32K144 Driver Set -- RGB Rainbow Demo
 *
 * Target:   NXP S32K144EVB (CPU_S32K144HFT0VLLT)
 * Core:     ARM Cortex-M4F @ 80 MHz
 * OS:       FreeRTOS V11.1.0
 * Standard: ISO 26262 ASIL-B
 *
 * Demo:
 *   RGB LED cycles through full HSV rainbow via FTM0 PWM.
 *   SW2 (PTC12) pauses and resumes the rainbow.
 *   UART1 prints RGB values and state every 500ms.
 *
 * Responsibilities of this file:
 *   1. Hardware initialization sequence (MCAL layer)
 *   2. FreeRTOS task creation
 *   3. Scheduler start
 *
 * Note: Clock init functions (SOSC, SPLL, RUN mode) are kept here
 *       temporarily until SCG_Core.c MCAL driver is implemented.
 *       TODO: Migrate to SCG_Core.c / SCG_Cfg.h
 */

#include "Headers.h"
#include "KIT_Appl.h"
#include "FreeRTOS.h"
#include "task.h"

/*---------------------------------------------------------------------------
 * PRIVATE FUNCTION PROTOTYPES
 *--------------------------------------------------------------------------*/
static void SOSC_init_8MHz(void);
static void SPLL_init_160MHz(void);
static void NormalRUNmode_80MHz(void);

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName);
void vApplicationMallocFailedHook(void);

/*===========================================================================
 * CLOCK INITIALIZATION
 * TODO: Migrate to SCG_Core.c MCAL driver
 *=========================================================================*/

static void SOSC_init_8MHz(void)
{
	/*!
	 * SOSC Initialization (8 MHz):
	 * ===================================================
	 */
	SCG->SOSCDIV = SCG_SOSCDIV_SOSCDIV1(1) |
				   SCG_SOSCDIV_SOSCDIV2(1);  	/* SOSCDIV1 & SOSCDIV2 =1: divide by 1         */
	SCG->SOSCCFG  =	SCG_SOSCCFG_RANGE(2)   |	/* Range=2: Medium freq (SOSC betw 1MHz-8MHz)  */
					SCG_SOSCCFG_EREFS_MASK;		/* HGO=0:   Config xtal osc for low power      */
												/* EREFS=1: Input is external XTAL             */

	while(SCG->SOSCCSR & SCG_SOSCCSR_LK_MASK); 	/* Ensure SOSCCSR unlocked                 */
	SCG->SOSCCSR = SCG_SOSCCSR_SOSCEN_MASK; 		/* LK=0:          SOSCCSR can be written   */
													/* SOSCCMRE=0:    OSC CLK monitor IRQ if enabled */
													/* SOSCCM=0:      OSC CLK monitor disabled */
													/* SOSCERCLKEN=0: Sys OSC 3V ERCLK output clk disabled */
													/* SOSCLPEN=0:    Sys OSC disabled in VLP modes  */
													/* SOSCSTEN=0:    Sys OSC disabled in Stop modes */
													/* SOSCEN=1:      Enable oscillator        */

	while(!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK)); /* Wait for sys OSC clk valid         */
}

static void SPLL_init_160MHz(void)
{
	/*!
	 * SPLL Initialization (160 MHz):
	 * ===================================================
	 */
	while(SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK);  	/* Ensure SPLLCSR unlocked                */
	SCG->SPLLCSR &= ~SCG_SPLLCSR_SPLLEN_MASK;   	/* SPLLEN=0: SPLL is disabled (default)   */

	SCG->SPLLDIV |= SCG_SPLLDIV_SPLLDIV1(2) |  	/* SPLLDIV1 divide by 2                   */
					SCG_SPLLDIV_SPLLDIV2(3);  		/* SPLLDIV2 divide by 4                   */

	SCG->SPLLCFG = SCG_SPLLCFG_MULT(24);			/* PREDIV=0: Divide SOSC_CLK by 0+1=1     */
													/* MULT=24:  Multiply sys pll by 4+24=40  */
													/* SPLL_CLK = 8MHz / 1 * 40 / 2 = 160 MHz*/

	while(SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK);  	/* Ensure SPLLCSR unlocked                */
	SCG->SPLLCSR |= SCG_SPLLCSR_SPLLEN_MASK;    	/* LK=0:       SPLLCSR can be written     */
													/* SPLLCMRE=0: SPLL CLK monitor IRQ if enabled */
													/* SPLLCM=0:   SPLL CLK monitor disabled  */
													/* SPLLSTEN=0: SPLL disabled in Stop modes*/
													/* SPLLEN=1:   Enable SPLL                */

	while(!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK)); /* Wait for SPLL valid               */
}

static void NormalRUNmode_80MHz(void)
{
	/*! Slow IRC is enabled with high range (8 MHz) in reset.
	 *  Enable SIRCDIV2_CLK and SIRCDIV1_CLK, divide by 1 = 8MHz
	 *  asynchronous clock source.
	 * ==========================================
	 */
	SCG->SIRCDIV = SCG_SIRCDIV_SIRCDIV1(1)
				 | SCG_SIRCDIV_SIRCDIV2(1);

	/*!
	 * Change to normal RUN mode with 8MHz SOSC, 80 MHz PLL:
	 * ====================================================
	 */
	SCG->RCCR = SCG_RCCR_SCS(6)       /* Select PLL as clock source                            */
	    | SCG_RCCR_DIVCORE(0b01)       /* DIVCORE=1, div. by 2: Core clock = 160/2 MHz = 80 MHz */
	    | SCG_RCCR_DIVBUS(0b01)        /* DIVBUS=1,  div. by 2: bus clock = 40 MHz              */
	    | SCG_RCCR_DIVSLOW(0b10);      /* DIVSLOW=2, div. by 2: SCG slow, flash clock= 26 2/3 MHz */

	while(((SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT) != 6) {} /* Wait for sys clk src = SPLL */
}

/*===========================================================================
 * FREERTOS HOOK FUNCTIONS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * Stack Overflow Hook
 *
 * Called by FreeRTOS when a task stack overflow is detected.
 * ISO 26262: Must trigger a safe state.
 * TODO: Replace halt with proper DEM error reporting / safe state handler.
 *--------------------------------------------------------------------------*/
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
	(void)xTask;
	(void)pcTaskName;

	DISABLE_INTERRUPTS();
	for(;;) {}
}

/*---------------------------------------------------------------------------
 * Malloc Failed Hook
 *
 * Called when pvPortMalloc() returns NULL (heap exhausted).
 * Fix: Increase configTOTAL_HEAP_SIZE in FreeRTOSConfig.h.
 * TODO: Replace halt with proper DEM error reporting / safe state handler.
 *--------------------------------------------------------------------------*/
void vApplicationMallocFailedHook(void)
{
	DISABLE_INTERRUPTS();
	for(;;) {}
}

/*===========================================================================
 * MAIN ENTRY POINT
 *=========================================================================*/

int main(void)
{
	asm("nop");
	DISABLE_INTERRUPTS();

	/*-----------------------------------------------------------------------
	 * MCAL Initialization -- strict sequence, do not reorder
	 *
	 * Order rationale:
	 *   WDOG first   -- must be configured before any other peripheral
	 *   Clock next   -- all peripherals depend on stable clock
	 *   Peripherals  -- initialized after clock is stable
	 *   NVIC last    -- enable interrupts only after all peripherals ready
	 *----------------------------------------------------------------------*/
	WDOG_Init();            /* Initialize WDOG -- configure timeout and mode      */
	SOSC_init_8MHz();       /* Initialize system oscillator for 8 MHz XTAL        */
	SPLL_init_160MHz();     /* Initialize SPLL to 160 MHz with 8 MHz SOSC         */
	NormalRUNmode_80MHz();  /* Init clocks: 80 MHz core, 40 MHz bus, 26 MHz flash */
	FTMn_Init();            /* Flexible Timers -- PWM on FTM0, 1ms timer on FTM1  */
	LPUART_Init();          /* LPUART1 -- interrupt-driven Tx/Rx @ 115200         */
	Port_Init();            /* PORT -- pin mux: PTD0/15/16 PWM, PTC12 input       */
	NVIC_init_IRQs();       /* NVIC -- interrupt priorities                       */

	/*-----------------------------------------------------------------------
	 * FreeRTOS Task Creation
	 *
	 * Task priority map:
	 *   configMAX_PRIORITIES-1  WdogRefresh  -- safety, never starved
	 *   3                       RgbPwm       -- smooth PWM update, 20ms
	 *   2                       SwitchMonitor -- button debounce, 10ms
	 *   1                       UartStatus   -- low priority print, 500ms
	 *
	 * Do NOT call ENABLE_INTERRUPTS() -- FreeRTOS enables interrupts
	 * internally via the SVC exception on first context switch.
	 *----------------------------------------------------------------------*/

	/* Watchdog refresh -- highest priority, must never be preempted        */
	xTaskCreate(vTask_WdogRefresh,          /* Task function                */
				"WdogRefresh",              /* Task name (debug only)       */
				128u,                       /* Stack depth in words         */
				NULL,                       /* Parameters -- none           */
				configMAX_PRIORITIES - 1u,  /* Highest priority             */
				NULL);                      /* Task handle -- not needed    */

	/* RGB PWM rainbow -- smooth colour cycling via FTM0                   */
	xTaskCreate(vTask_RgbPwm,               /* Task function                */
				"RgbPwm",                   /* Task name (debug only)       */
				256u,                       /* Stack depth in words         */
				NULL,                       /* Parameters -- none           */
				3u,                         /* High application priority    */
				NULL);                      /* Task handle -- not needed    */

	/* Switch monitor -- SW2 pause/resume on PTC12                         */
	xTaskCreate(vTask_SwitchMonitor,        /* Task function                */
				"SwitchMon",                /* Task name (debug only)       */
				128u,                       /* Stack depth in words         */
				NULL,                       /* Parameters -- none           */
				2u,                         /* Medium application priority  */
				NULL);                      /* Task handle -- not needed    */

	/* UART status -- print RGB values and state every 500ms               */
	xTaskCreate(vTask_UartStatus,           /* Task function                */
				"UartStatus",               /* Task name (debug only)       */
				256u,                       /* Stack depth in words         */
				NULL,                       /* Parameters -- none           */
				1u,                         /* Lowest application priority  */
				NULL);                      /* Task handle -- not needed    */

	/*-----------------------------------------------------------------------
	 * Start FreeRTOS Scheduler
	 *
	 * vTaskStartScheduler() should never return.
	 * If it does, heap is too small to create idle/timer tasks.
	 * Fix: Increase configTOTAL_HEAP_SIZE in FreeRTOSConfig.h.
	 *----------------------------------------------------------------------*/
	vTaskStartScheduler();

	/* Should never reach here */
	DISABLE_INTERRUPTS();
	for(;;) {}

	return 0;
}
