################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/TimerConf.c \
../Src/exti.c \
../Src/main.c \
../Src/myClockConf.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/TimerConf.o \
./Src/exti.o \
./Src/main.o \
./Src/myClockConf.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/TimerConf.d \
./Src/exti.d \
./Src/main.d \
./Src/myClockConf.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -I../Inc -I"../../CMSIS/Include" -I"../../CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/TimerConf.cyclo ./Src/TimerConf.d ./Src/TimerConf.o ./Src/TimerConf.su ./Src/exti.cyclo ./Src/exti.d ./Src/exti.o ./Src/exti.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/myClockConf.cyclo ./Src/myClockConf.d ./Src/myClockConf.o ./Src/myClockConf.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

