################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api.c \
C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api_calibration.c \
C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api_core.c \
C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api_ranging.c \
C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api_strings.c \
C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_platform_log.c 

OBJS += \
./Drivers/BSP/vl53l0x/vl53l0x_api.o \
./Drivers/BSP/vl53l0x/vl53l0x_api_calibration.o \
./Drivers/BSP/vl53l0x/vl53l0x_api_core.o \
./Drivers/BSP/vl53l0x/vl53l0x_api_ranging.o \
./Drivers/BSP/vl53l0x/vl53l0x_api_strings.o \
./Drivers/BSP/vl53l0x/vl53l0x_platform_log.o 

C_DEPS += \
./Drivers/BSP/vl53l0x/vl53l0x_api.d \
./Drivers/BSP/vl53l0x/vl53l0x_api_calibration.d \
./Drivers/BSP/vl53l0x/vl53l0x_api_core.d \
./Drivers/BSP/vl53l0x/vl53l0x_api_ranging.d \
./Drivers/BSP/vl53l0x/vl53l0x_api_strings.d \
./Drivers/BSP/vl53l0x/vl53l0x_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/vl53l0x/vl53l0x_api.o: C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/vl53l0x/vl53l0x_api.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/vl53l0x/vl53l0x_api_calibration.o: C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api_calibration.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/vl53l0x/vl53l0x_api_calibration.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/vl53l0x/vl53l0x_api_core.o: C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api_core.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/vl53l0x/vl53l0x_api_core.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/vl53l0x/vl53l0x_api_ranging.o: C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api_ranging.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/vl53l0x/vl53l0x_api_ranging.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/vl53l0x/vl53l0x_api_strings.o: C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_api_strings.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/vl53l0x/vl53l0x_api_strings.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/vl53l0x/vl53l0x_platform_log.o: C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x/vl53l0x_platform_log.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DNUCLEO_L476RG -DSTM32 -DSTM32L4 -DUSE_HAL_DRIVER -DSTM32L476xx '-DTRACE_UART=1' '-DVL53L0_LOG_ENABLE=1' '-DXNUCLEO53L0A1_TRACE=1' '-DVL53L0A1_HAVE_UART=1' -c -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I./../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I./../../../../../../../../Drivers/CMSIS/Include -I./../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I./../../../Inc -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/X-NUCLEO-53L0A1" -I"C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Nucleo_L476RG_VL_tests/Drivers/BSP/Components/vl53l0x" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/vl53l0x/vl53l0x_platform_log.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

