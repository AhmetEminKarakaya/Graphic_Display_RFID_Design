################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/GUIConf.c \
../Core/Src/GUI_X.c \
../Core/Src/LCDConf_FlexColor.c \
../Core/Src/PersonalEntryDLG.c \
../Core/Src/fatfs_sd.c \
../Core/Src/main.c \
../Core/Src/rc522.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/GUIConf.o \
./Core/Src/GUI_X.o \
./Core/Src/LCDConf_FlexColor.o \
./Core/Src/PersonalEntryDLG.o \
./Core/Src/fatfs_sd.o \
./Core/Src/main.o \
./Core/Src/rc522.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/GUIConf.d \
./Core/Src/GUI_X.d \
./Core/Src/LCDConf_FlexColor.d \
./Core/Src/PersonalEntryDLG.d \
./Core/Src/fatfs_sd.d \
./Core/Src/main.d \
./Core/Src/rc522.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../GUI/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/GUIConf.d ./Core/Src/GUIConf.o ./Core/Src/GUI_X.d ./Core/Src/GUI_X.o ./Core/Src/LCDConf_FlexColor.d ./Core/Src/LCDConf_FlexColor.o ./Core/Src/PersonalEntryDLG.d ./Core/Src/PersonalEntryDLG.o ./Core/Src/fatfs_sd.d ./Core/Src/fatfs_sd.o ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/rc522.d ./Core/Src/rc522.o ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o

.PHONY: clean-Core-2f-Src

