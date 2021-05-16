################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API_VL53L0X/core/src/vl53l0x_api.c \
../Drivers/API_VL53L0X/core/src/vl53l0x_api_calibration.c \
../Drivers/API_VL53L0X/core/src/vl53l0x_api_core.c \
../Drivers/API_VL53L0X/core/src/vl53l0x_api_ranging.c \
../Drivers/API_VL53L0X/core/src/vl53l0x_api_strings.c 

C_DEPS += \
./Drivers/API_VL53L0X/core/src/vl53l0x_api.d \
./Drivers/API_VL53L0X/core/src/vl53l0x_api_calibration.d \
./Drivers/API_VL53L0X/core/src/vl53l0x_api_core.d \
./Drivers/API_VL53L0X/core/src/vl53l0x_api_ranging.d \
./Drivers/API_VL53L0X/core/src/vl53l0x_api_strings.d 

OBJS += \
./Drivers/API_VL53L0X/core/src/vl53l0x_api.o \
./Drivers/API_VL53L0X/core/src/vl53l0x_api_calibration.o \
./Drivers/API_VL53L0X/core/src/vl53l0x_api_core.o \
./Drivers/API_VL53L0X/core/src/vl53l0x_api_ranging.o \
./Drivers/API_VL53L0X/core/src/vl53l0x_api_strings.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API_VL53L0X/core/src/vl53l0x_api.o: ../Drivers/API_VL53L0X/core/src/vl53l0x_api.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/core/src/vl53l0x_api.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/API_VL53L0X/core/src/vl53l0x_api_calibration.o: ../Drivers/API_VL53L0X/core/src/vl53l0x_api_calibration.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/core/src/vl53l0x_api_calibration.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/API_VL53L0X/core/src/vl53l0x_api_core.o: ../Drivers/API_VL53L0X/core/src/vl53l0x_api_core.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/core/src/vl53l0x_api_core.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/API_VL53L0X/core/src/vl53l0x_api_ranging.o: ../Drivers/API_VL53L0X/core/src/vl53l0x_api_ranging.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/core/src/vl53l0x_api_ranging.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/API_VL53L0X/core/src/vl53l0x_api_strings.o: ../Drivers/API_VL53L0X/core/src/vl53l0x_api_strings.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/core/src/vl53l0x_api_strings.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

