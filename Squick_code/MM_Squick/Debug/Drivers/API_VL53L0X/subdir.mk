################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API_VL53L0X/vl_api_config.c \
../Drivers/API_VL53L0X/vl_stm32_api.c 

C_DEPS += \
./Drivers/API_VL53L0X/vl_api_config.d \
./Drivers/API_VL53L0X/vl_stm32_api.d 

OBJS += \
./Drivers/API_VL53L0X/vl_api_config.o \
./Drivers/API_VL53L0X/vl_stm32_api.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API_VL53L0X/vl_api_config.o: ../Drivers/API_VL53L0X/vl_api_config.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/vl_api_config.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/API_VL53L0X/vl_stm32_api.o: ../Drivers/API_VL53L0X/vl_stm32_api.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F411xE -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/API_VL53L0X/vl_stm32_api.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

