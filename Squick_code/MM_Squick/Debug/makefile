################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := MM_Squick
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MM_Squick.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MM_Squick.list \

OBJCOPY_BIN += \
MM_Squick.bin \


# All Target
all: main-build

# Main-build Target
main-build: MM_Squick.elf secondary-outputs

dependents:
	-cd C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Squick_code/MM_Squick/Release && $(MAKE) all

# Tool invocations
MM_Squick.elf: $(OBJS) $(USER_OBJS) C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Squick_code/MM_Squick/Release/MM_Squick.elf C:\Users\Piotr\Desktop\6sem\Squick\squick_cubeide\Squick_code\MM_Squick\STM32F411RETX_FLASH.ld
	arm-none-eabi-g++ -o "MM_Squick.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Piotr\Desktop\6sem\Squick\squick_cubeide\Squick_code\MM_Squick\STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="MM_Squick.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MM_Squick.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MM_Squick.list"
	@echo 'Finished building: $@'
	@echo ' '

MM_Squick.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "MM_Squick.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:
C:/Users/Piotr/Desktop/6sem/Squick/squick_cubeide/Squick_code/MM_Squick/Release/MM_Squick.elf:

-include ../makefile.targets
