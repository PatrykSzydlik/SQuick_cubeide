################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API_VL53L0X/platform/src/vl53l0x_i2c_win_serial_comms.c \
../Drivers/API_VL53L0X/platform/src/vl53l0x_platform.c \
../Drivers/API_VL53L0X/platform/src/vl53l0x_platform_log.c 

C_DEPS += \
./Drivers/API_VL53L0X/platform/src/vl53l0x_i2c_win_serial_comms.d \
./Drivers/API_VL53L0X/platform/src/vl53l0x_platform.d \
./Drivers/API_VL53L0X/platform/src/vl53l0x_platform_log.d 

OBJS += \
./Drivers/API_VL53L0X/platform/src/vl53l0x_i2c_win_serial_comms.o \
./Drivers/API_VL53L0X/platform/src/vl53l0x_platform.o \
./Drivers/API_VL53L0X/platform/src/vl53l0x_platform_log.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API_VL53L0X/platform/src/vl53l0x_i2c_win_serial_comms.o: ../Drivers/API_VL53L0X/platform/src/vl53l0x_i2c_win_serial_comms.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/platform/src/vl53l0x_i2c_win_serial_comms.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/API_VL53L0X/platform/src/vl53l0x_platform.o: ../Drivers/API_VL53L0X/platform/src/vl53l0x_platform.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/platform/src/vl53l0x_platform.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/API_VL53L0X/platform/src/vl53l0x_platform_log.o: ../Drivers/API_VL53L0X/platform/src/vl53l0x_platform_log.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/platform/src/vl53l0x_platform_log.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

