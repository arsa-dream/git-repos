# S32K144 Automotive Firmware — Claude Code Context

## Project Overview
Bare-metal automotive MCAL firmware stack on NXP S32K144 (ARM Cortex-M4F,
AEC-Q100, ASIL-B). No vendor HAL. Every peripheral written directly against
silicon registers. FreeRTOS V11.1.0 integrated. ISO 26262 ASIL-B aligned.

## Toolchain
- IDE: NXP S32 Design Studio v2.2 (Eclipse CDT)
- Compiler: GCC ARM 4.9 (arm-none-eabi)
- Project name in S32DS: S32K144_Driver
- Compiler flags: -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
- Linker flags: -mfpu=fpv4-sp-d16 -mfloat-abi=hard --gc-sections

## Repository Structure
```
src/s32k/                   S32DS Eclipse project root
  src/
    APPL/                   Application layer (main.c, KIT_Appl.c, Bldc.c)
    MCAL/                   Register-level peripheral drivers
    MDLW/                   Middleware (FreeRTOS linked files)
    STRD/                   Standard types (STRD_Types.h)
  include/
    APPL/                   KIT_Appl.h
    MCAL/                   Driver headers + Cfg headers
    MDLW/                   FreeRTOSConfig.h
    STRD/                   Headers.h, STRD_Types.h
  third_party/
    free_rtos/              FreeRTOS V11.1.0 Git submodule (pinned V11.1.0)
  Project_Settings/
    Startup_Code/           startup_S32K144.S, system_S32K144.c, startup.c
    Linker_Files/           Custom linker script
```

## Architecture Rules
- APPL depends on MCAL and MDLW, never the reverse
- Headers.h is the single include for all source files
- Each MCAL module has: _Cfg.h (user params) and _Core.c/.h (implementation)
- Compile-time feature gating: #if(ENABLE == MODULE_NAME)
- ENABLE = TRUE = 1u, DISABLE = FALSE = 0u (defined in STRD_Types.h)
- All types use explicit-width typedefs from STRD_Types.h (uint8, sint8, etc.)
- INTERRUPT_ macro marks ISR functions (empty macro, documentation only)

## MCAL Drivers Implemented
| Module      | Files                              | Notes                              |
|-------------|------------------------------------|------------------------------------|
| PORT        | PORT_Core.c/.h, PORT_Cfg.h         | Data-driven pin table, table-driven|
| GPIO        | GPIO_Core.h                        | Macros only, no .c needed          |
| FTM         | FTMn_Core.c/.h, FTMn_Cfg.h         | FTM0 PWM CH0/1/2, FTM1 1ms timer  |
| ADC         | ADC_Core.c/.h, ADC_Cfg.h           | ADC0+ADC1, 16ch each               |
| LPUART      | LPUART_Core.c, LPUARTn_Core.h/.Cfg | LPUART1 active, interrupt-driven Tx|
| WDOG        | WDOG_Core.c/.h, WDOG_Cfg.h         | LPO 128kHz, 256x prescaler, 4s TO  |
| NVIC        | NVIC_Core.c/.h                     | Data-driven IRQ table              |

## FreeRTOS Integration
- Version: V11.1.0 pinned in Git submodule
- Port: GCC/ARM_CM4F (Cortex-M4 hard-float FPU)
- Heap: heap_4 (20KB)
- FreeRTOSConfig.h: include/MDLW/FreeRTOSConfig.h (NOT inside submodule)
- 7 source files linked as Eclipse linked resources in src/MDLW/:
  tasks.c, queue.c, list.c, timers.c, event_groups.c, port.c, heap_4.c
- SysTick/PendSV/SVC handlers mapped in FreeRTOSConfig.h to avoid SDK conflicts
- configCPU_CLOCK_HZ = 80000000 (80MHz core after SPLL/DIVCORE)
- configMAX_SYSCALL_INTERRUPT_PRIORITY = 5 (0x50 shifted)
  -- ISRs using FreeRTOS API must have NVIC priority >= 5
  -- ISRs with priority 0-4 MUST NOT call FreeRTOS API

## Task Map
| Task            | Priority              | Period | Purpose                     |
|-----------------|-----------------------|--------|-----------------------------|
| vTask_WdogRefresh | configMAX_PRIORITIES-1 | 500ms | WDOG kick, safety gate     |
| vTask_RgbPwm    | 3                     | 20ms   | HSV rainbow on FTM0 PWM     |
| vTask_SwitchMonitor | 2               | 10ms   | SW2 debounce pause/resume   |
| vTask_UartStatus | 1                    | 500ms  | LPUART1 RGB status print    |

## Board Pin Assignment (S32K144EVB)
| Pin   | Function         | Driver        |
|-------|------------------|---------------|
| PTD15 | Red LED          | FTM0 CH0 PWM  |
| PTD16 | Green LED        | FTM0 CH1 PWM  |
| PTD0  | Blue LED         | FTM0 CH2 PWM  |
| PTC12 | SW2 input        | GPIO, pull-up |
| PTC13 | SW3 input        | GPIO, pull-up |
| PTB0  | LPUART1 RX       | ALT2          |
| PTB1  | LPUART1 TX       | ALT2          |

## Clock Configuration (in main.c, TODO: migrate to SCG_Core.c)
- SOSC: 8MHz external XTAL
- SPLL: 160MHz (8MHz * 40 / 2)
- Core: 80MHz (SPLL / DIVCORE=2)
- Bus: 40MHz (SPLL / DIVBUS=2)
- Flash: 26.67MHz (SPLL / DIVSLOW=3)
- SIRCDIV1/2: 8MHz (for FTM, LPUART async clocks)

## Known TODOs (next development priorities)
1. SCG_Core.c -- migrate clock init from main.c
2. FlexCAN driver -- CAN FD, highest priority next MCAL module
3. DMA driver -- for production ADC and UART
4. LPSPI, LPI2C drivers
5. Replace vApplicationStackOverflowHook halt with DEM error reporting
6. ADC result reading in ADC0/1_IRQHandler (currently empty TODO)
7. FTM0_CHx_MODULO_VAL -- verify value in FTMn_Cfg.h matches PWM period

## Important Coding Conventions
- No printf/sprintf -- build strings manually to avoid newlib stdio overhead
- No malloc -- FreeRTOS heap_4 only, all allocations at task creation
- No float in ISRs or tasks (use integer HSV conversion instead)
- Interrupt-safe sections: DISABLE_INTERRUPTS() / ENABLE_INTERRUPTS()
- WDOG_Refresh() called ONLY from vTask_WdogRefresh -- ISO 26262 constraint
- ISR function names must match startup_S32K144.S vector table exactly
- Cfg files use LPUART_0_, LPUART_1_, LPUART_2_ prefix (with trailing underscore)

## Common Build Issues and Fixes
- sources.mk not found: caused by wrong project name in .cproject builder path
  Fix: ensure buildPath points to S32K144_Driver, not S32K144_Project_Hello
- VFP register arguments error: missing -mfpu/mfloat-abi in linker flags
- ENABLE/DISABLE undeclared: add to STRD_Types.h as 1u and 0u
- NULLPTR undeclared: add to STRD_Types.h as ((void*)0u)
- LPUART2 defines: prefix is LPUART_2_ (underscore after digit), not LPUART2_
- LPUart0/2_TransmitString return type: void (blocking); only LPUart1 returns STD_FsmStates
- FreeRTOS handler conflicts: xPortPendSVHandler etc mapped in FreeRTOSConfig.h

## Git Submodule Commands
```bash
# Update FreeRTOS to latest
git submodule update --remote src/s32k/third_party/free_rtos
git add src/s32k/third_party/free_rtos
git commit -m "chore: update FreeRTOS to latest"

# Clone repo with submodules
git clone --recurse-submodules <repo-url>

# After plain git pull
git submodule update --init --recursive
```
