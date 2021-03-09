################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Projects/Multi/Examples/VL53L0X/RangingWithSatellites/Src/main.c \
C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Projects/Multi/Examples/VL53L0X/RangingWithSatellites/Src/stm32l4xx_hal_msp.c \
C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Projects/Multi/Examples/VL53L0X/RangingWithSatellites/Src/stm32l4xx_it.c 

OBJS += \
./src/main.o \
./src/stm32l4xx_hal_msp.o \
./src/stm32l4xx_it.o 

C_DEPS += \
./src/main.d \
./src/stm32l4xx_hal_msp.d \
./src/stm32l4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
src/main.o: C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Projects/Multi/Examples/VL53L0X/RangingWithSatellites/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/stm32l4xx_hal_msp.o: C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Projects/Multi/Examples/VL53L0X/RangingWithSatellites/Src/stm32l4xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/stm32l4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/stm32l4xx_it.o: C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Projects/Multi/Examples/VL53L0X/RangingWithSatellites/Src/stm32l4xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/stm32l4xx_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

