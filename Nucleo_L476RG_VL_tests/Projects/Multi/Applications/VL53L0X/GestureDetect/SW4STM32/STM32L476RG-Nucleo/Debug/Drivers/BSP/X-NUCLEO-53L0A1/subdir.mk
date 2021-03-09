################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1/X-NUCLEO-53L0A1.c \
C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1/uart_trace.c \
C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1/vl53l0a1-x4msp.c \
C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1/vl53l0x_platform.c 

OBJS += \
./Drivers/BSP/X-NUCLEO-53L0A1/X-NUCLEO-53L0A1.o \
./Drivers/BSP/X-NUCLEO-53L0A1/uart_trace.o \
./Drivers/BSP/X-NUCLEO-53L0A1/vl53l0a1-x4msp.o \
./Drivers/BSP/X-NUCLEO-53L0A1/vl53l0x_platform.o 

C_DEPS += \
./Drivers/BSP/X-NUCLEO-53L0A1/X-NUCLEO-53L0A1.d \
./Drivers/BSP/X-NUCLEO-53L0A1/uart_trace.d \
./Drivers/BSP/X-NUCLEO-53L0A1/vl53l0a1-x4msp.d \
./Drivers/BSP/X-NUCLEO-53L0A1/vl53l0x_platform.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/X-NUCLEO-53L0A1/X-NUCLEO-53L0A1.o: C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1/X-NUCLEO-53L0A1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/Components/vl53l0x" -I../../../../../../../../Middlewares/ST/Gestures/GesturesDetect/Inc -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/X-NUCLEO-53L0A1/X-NUCLEO-53L0A1.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/X-NUCLEO-53L0A1/uart_trace.o: C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1/uart_trace.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/Components/vl53l0x" -I../../../../../../../../Middlewares/ST/Gestures/GesturesDetect/Inc -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/X-NUCLEO-53L0A1/uart_trace.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/X-NUCLEO-53L0A1/vl53l0a1-x4msp.o: C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1/vl53l0a1-x4msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/Components/vl53l0x" -I../../../../../../../../Middlewares/ST/Gestures/GesturesDetect/Inc -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/X-NUCLEO-53L0A1/vl53l0a1-x4msp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/X-NUCLEO-53L0A1/vl53l0x_platform.o: C:/Users/patry/Desktop/MM\ Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1/vl53l0x_platform.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/patry/Desktop/MM Squick/squick_cubeide/Nucleo_L476RG_VL_tests/en.X-CUBE-53L0A1/X-CUBE-53L0A1/STM32CubeExpansion_VL53L0X_V1.2.0/Drivers/BSP/Components/vl53l0x" -I../../../../../../../../Middlewares/ST/Gestures/GesturesDetect/Inc -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/X-NUCLEO-53L0A1/vl53l0x_platform.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

