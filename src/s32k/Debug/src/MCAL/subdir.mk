################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/ADC_Core.c \
../src/MCAL/FTMn_Core.c \
../src/MCAL/LPTMR_Core.c \
../src/MCAL/LPUART_Core.c \
../src/MCAL/NVIC_Core.c \
../src/MCAL/PORT_Core.c \
../src/MCAL/WDOG_Core.c 

OBJS += \
./src/MCAL/ADC_Core.o \
./src/MCAL/FTMn_Core.o \
./src/MCAL/LPTMR_Core.o \
./src/MCAL/LPUART_Core.o \
./src/MCAL/NVIC_Core.o \
./src/MCAL/PORT_Core.o \
./src/MCAL/WDOG_Core.o 

C_DEPS += \
./src/MCAL/ADC_Core.d \
./src/MCAL/FTMn_Core.d \
./src/MCAL/LPTMR_Core.d \
./src/MCAL/LPUART_Core.d \
./src/MCAL/NVIC_Core.d \
./src/MCAL/PORT_Core.d \
./src/MCAL/WDOG_Core.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/%.o: ../src/MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/MCAL/ADC_Core.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


