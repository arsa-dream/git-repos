################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/APPL/Bldc.c \
../src/APPL/KIT_Appl.c 

OBJS += \
./src/APPL/Bldc.o \
./src/APPL/KIT_Appl.o 

C_DEPS += \
./src/APPL/Bldc.d \
./src/APPL/KIT_Appl.d 


# Each subdirectory must supply rules for building sources it contributes
src/APPL/%.o: ../src/APPL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/APPL/Bldc.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


