################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include Middlewares/GestureDetect/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/vl53l0x/subdir.mk
-include Drivers/BSP/X-NUCLEO-53L0A1/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
VL53L0X_GestureDetect_L476.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
VL53L0X_GestureDetect_L476.list \

OBJCOPY_BIN += \
VL53L0X_GestureDetect_L476.bin \


# All Target
all: VL53L0X_GestureDetect_L476.elf secondary-outputs

# Tool invocations
VL53L0X_GestureDetect_L476.elf: $(OBJS) $(USER_OBJS) C:\Users\patry\Desktop\MM\ Squick\squick_cubeide\Nucleo_L476RG_VL_tests\en.X-CUBE-53L0A1\X-CUBE-53L0A1\STM32CubeExpansion_VL53L0X_V1.2.0\Projects\Multi\Applications\VL53L0X\GestureDetect\SW4STM32\STM32L476RG-Nucleo\STM32L476RGTx_FLASH.ld
	arm-none-eabi-gcc -o "VL53L0X_GestureDetect_L476.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\patry\Desktop\MM Squick\squick_cubeide\Nucleo_L476RG_VL_tests\en.X-CUBE-53L0A1\X-CUBE-53L0A1\STM32CubeExpansion_VL53L0X_V1.2.0\Projects\Multi\Applications\VL53L0X\GestureDetect\SW4STM32\STM32L476RG-Nucleo\STM32L476RGTx_FLASH.ld" --specs=nosys.specs -Wl,-Map="VL53L0X_GestureDetect_L476.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_GestureDetect_L476.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "VL53L0X_GestureDetect_L476.list"
	@echo 'Finished building: $@'
	@echo ' '

VL53L0X_GestureDetect_L476.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "VL53L0X_GestureDetect_L476.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
