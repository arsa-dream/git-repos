/*
 * FreeRTOSConfig.h
 *
 * Target:      NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Core:        ARM Cortex-M4F
 * Clock:       112 MHz (max)
 * Compiler:    GCC (S32 Design Studio)
 * FreeRTOS:    V11.1.0
 *
 * Place this file in: src/s32k/include/MDLW/FreeRTOSConfig.h
 * Do NOT modify the FreeRTOS submodule — only this file.
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*---------------------------------------------------------------------------
 * APPLICATION SPECIFIC DEFINITIONS
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * See: https://www.freertos.org/a00110.html
 *--------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
 * CORE SCHEDULER CONFIGURATION
 *--------------------------------------------------------------------------*/

/* Use preemptive scheduling (1) or cooperative scheduling (0).
 * Preemptive: higher priority tasks immediately preempt lower ones.
 * Recommended: 1 for automotive/real-time use cases. */
#define configUSE_PREEMPTION                        1

/* Enable time slicing between tasks of equal priority.
 * Recommended: 1 */
#define configUSE_TIME_SLICING                      1

/* Tickless idle: disable systick when CPU is idle to save power.
 * Set to 0 for now — enable later when learning low-power modes. */
#define configUSE_TICKLESS_IDLE                     0

/*---------------------------------------------------------------------------
 * CLOCK & TICK CONFIGURATION
 *--------------------------------------------------------------------------*/

/* S32K144 maximum CPU clock: 112 MHz.
 * Update this if you configure a lower clock in your SCG settings. */
#define configCPU_CLOCK_HZ                          ( ( unsigned long ) 112000000UL )

/* Tick rate: 1000 Hz = 1ms tick period.
 * This is the standard for automotive embedded systems. */
#define configTICK_RATE_HZ                          ( ( TickType_t ) 1000 )

/*---------------------------------------------------------------------------
 * TASK CONFIGURATION
 *--------------------------------------------------------------------------*/

/* Maximum number of task priority levels.
 * 8 levels: 0 (lowest/idle) to 7 (highest).
 * Keep this small — each level costs RAM in the ready list. */
#define configMAX_PRIORITIES                        ( 8 )

/* Stack size for the idle task in words (not bytes).
 * 128 words = 512 bytes. Do not set below 128 on Cortex-M4F. */
#define configMINIMAL_STACK_SIZE                    ( ( unsigned short ) 128 )

/* Maximum length of a task name string (including null terminator).
 * Used only for debugging — reduce to 8 to save RAM if needed. */
#define configMAX_TASK_NAME_LEN                     ( 16 )

/* Use 32-bit tick counter (0) or 16-bit (1).
 * Always use 0 (32-bit) on 32-bit Cortex-M4F. */
#define configUSE_16_BIT_TICKS                      0

/* Idle task yields to application tasks of equal priority.
 * Recommended: 1 */
#define configIDLE_SHOULD_YIELD                     1

/* Allow tasks to share a stack — NOT recommended for production.
 * Keep 0. */
#define configUSE_TASK_NOTIFICATIONS                1
#define configTASK_NOTIFICATION_ARRAY_ENTRIES       1

/*---------------------------------------------------------------------------
 * HEAP & MEMORY
 *--------------------------------------------------------------------------*/

/* Total heap size available to FreeRTOS in bytes.
 * S32K144 has 64KB RAM total. Budget breakdown:
 *   - FreeRTOS heap:  20480 bytes (20KB)
 *   - Task stacks:    ~16KB (varies)
 *   - Global/static:  ~8KB
 *   - Remaining:      ~20KB buffer
 * Adjust if you add more tasks or larger stacks. */
#define configTOTAL_HEAP_SIZE                       ( ( size_t ) ( 20480 ) )

/*---------------------------------------------------------------------------
 * SYNCHRONISATION PRIMITIVES
 *--------------------------------------------------------------------------*/

/* Mutexes: used for resource protection with priority inheritance. */
#define configUSE_MUTEXES                           1

/* Recursive mutexes: a task can lock the same mutex multiple times. */
#define configUSE_RECURSIVE_MUTEXES                 1

/* Counting semaphores: semaphores with a count > 1. */
#define configUSE_COUNTING_SEMAPHORES               1

/* Queue sets: wait on multiple queues/semaphores simultaneously. */
#define configUSE_QUEUE_SETS                        1

/* Number of queues/semaphores that can be registered for debugging.
 * Set to 0 to disable queue registry and save RAM. */
#define configQUEUE_REGISTRY_SIZE                   8

/*---------------------------------------------------------------------------
 * SOFTWARE TIMERS
 *--------------------------------------------------------------------------*/

/* Enable software timer functionality. */
#define configUSE_TIMERS                            1

/* Priority of the timer service task.
 * Should be higher than most application tasks. */
#define configTIMER_TASK_PRIORITY                   ( configMAX_PRIORITIES - 1 )

/* Length of the timer command queue. */
#define configTIMER_QUEUE_LENGTH                    10

/* Stack depth of the timer service task in words. */
#define configTIMER_TASK_STACK_DEPTH                ( configMINIMAL_STACK_SIZE * 2 )

/*---------------------------------------------------------------------------
 * RUNTIME STATISTICS & DEBUGGING
 *--------------------------------------------------------------------------*/

/* Generate runtime statistics (CPU usage per task).
 * Requires a high-resolution timer — set to 1 only when profiling. */
#define configGENERATE_RUN_TIME_STATS               0

/* Enable visualisation of execution using RTOS trace tools (e.g. Tracealyzer).
 * Keep 1 — low overhead, needed for uxTaskGetSystemState(). */
#define configUSE_TRACE_FACILITY                    1

/* Enable vTaskList() and vTaskGetRunTimeStats() helper functions.
 * Useful for printing task state via UART during development. */
#define configUSE_STATS_FORMATTING_FUNCTIONS        1

/*---------------------------------------------------------------------------
 * STACK OVERFLOW DETECTION
 *
 * CRITICAL: Keep this enabled during all development and testing.
 * Method 2: checks stack watermark pattern on every context switch.
 * Calls vApplicationStackOverflowHook() — you must implement this.
 *--------------------------------------------------------------------------*/
#define configCHECK_FOR_STACK_OVERFLOW              2

/*---------------------------------------------------------------------------
 * MALLOC FAILURE HOOK
 *
 * Called when pvPortMalloc() fails (heap exhausted).
 * You must implement vApplicationMallocFailedHook() in your APPL layer.
 *--------------------------------------------------------------------------*/
#define configUSE_MALLOC_FAILED_HOOK                1

/*---------------------------------------------------------------------------
 * IDLE TASK HOOK
 *
 * Called repeatedly from the idle task.
 * Useful for low-power sleep entry or watchdog kicking.
 * You must implement vApplicationIdleHook() if set to 1.
 *--------------------------------------------------------------------------*/
#define configUSE_IDLE_HOOK                         0

/*---------------------------------------------------------------------------
 * TICK HOOK
 *
 * Called from the SysTick ISR on every tick.
 * Keep 0 unless you need per-tick callbacks (high overhead).
 *--------------------------------------------------------------------------*/
#define configUSE_TICK_HOOK                         0

/*---------------------------------------------------------------------------
 * CORTEX-M4F INTERRUPT PRIORITY CONFIGURATION
 *
 * S32K144 uses 4 bits for interrupt priority (16 levels: 0-15).
 * FreeRTOS requires interrupts that call FreeRTOS API to have priority
 * NUMERICALLY EQUAL OR GREATER than configMAX_SYSCALL_INTERRUPT_PRIORITY.
 *
 * Rule:
 *   - ISRs using FreeRTOS API (e.g. xQueueSendFromISR):
 *       priority >= configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY (5..15)
 *   - ISRs NOT using FreeRTOS API (e.g. safety-critical fast ISRs):
 *       priority < configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY (0..4)
 *
 * NEVER call FreeRTOS API from ISRs with priority 0-4.
 *--------------------------------------------------------------------------*/

/* Lowest possible interrupt priority on this device (15 for 4-bit). */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         15

/* Highest priority from which FreeRTOS API calls are safe.
 * Priorities 0-4 are reserved for safety-critical ISRs (e.g. motor control).
 * Priorities 5-15 can use FreeRTOS fromISR() functions. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY     5

/* Do not modify these — derived from above values for CMSIS register format. */
#define configKERNEL_INTERRUPT_PRIORITY \
    ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << ( 8 - 4 ) )

#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << ( 8 - 4 ) )

/* Alias for newer FreeRTOS versions. */
#define configMAX_API_CALL_INTERRUPT_PRIORITY \
    configMAX_SYSCALL_INTERRUPT_PRIORITY

/*---------------------------------------------------------------------------
 * CORTEX-M4F EXCEPTION HANDLER MAPPING
 *
 * Maps FreeRTOS ISR names to the CMSIS/S32K SDK handler names.
 * This prevents duplicate symbol errors at link time.
 * If you get "multiple definition of SysTick_Handler" errors,
 * comment out the SDK's weak definition in startup_S32K144.S or
 * exceptions.c — do NOT remove these defines.
 *--------------------------------------------------------------------------*/
#define xPortPendSVHandler      PendSV_Handler
#define vPortSVCHandler         SVC_Handler
#define xPortSysTickHandler     SysTick_Handler

/*---------------------------------------------------------------------------
 * OPTIONAL API INCLUDES
 *
 * Set to 1 to include the named API function in the build.
 * Set to 0 to exclude and save flash space.
 *--------------------------------------------------------------------------*/
#define INCLUDE_vTaskDelay                          1
#define INCLUDE_vTaskDelayUntil                     1
#define INCLUDE_uxTaskGetStackHighWaterMark         1
#define INCLUDE_xTaskGetCurrentTaskHandle           1
#define INCLUDE_vTaskDelete                         1
#define INCLUDE_vTaskSuspend                        1
#define INCLUDE_xTaskGetHandle                      1
#define INCLUDE_xTaskGetIdleTaskHandle              1
#define INCLUDE_xTimerGetTimerDaemonTaskHandle      1
#define INCLUDE_pcTaskGetName                       1
#define INCLUDE_uxTaskPriorityGet                   1
#define INCLUDE_vTaskPrioritySet                    1
#define INCLUDE_eTaskGetState                       1

#endif /* FREERTOS_CONFIG_H */
