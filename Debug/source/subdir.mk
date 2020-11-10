################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Circular_buffer.c \
../source/Command_logger.c \
../source/Command_process.c \
../source/Hexdump.c \
../source/Uart.c \
../source/main.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/sysclock.c \
../source/test_cbfifo.c 

OBJS += \
./source/Circular_buffer.o \
./source/Command_logger.o \
./source/Command_process.o \
./source/Hexdump.o \
./source/Uart.o \
./source/main.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/sysclock.o \
./source/test_cbfifo.o 

C_DEPS += \
./source/Circular_buffer.d \
./source/Command_logger.d \
./source/Command_process.d \
./source/Hexdump.d \
./source/Uart.d \
./source/main.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/sysclock.d \
./source/test_cbfifo.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"D:\BreakfastSerial1\source" -I"D:\BreakfastSerial1" -I"D:\BreakfastSerial1\startup" -I"D:\BreakfastSerial1\CMSIS" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


