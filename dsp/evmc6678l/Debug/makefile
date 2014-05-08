################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/gtbldadm/ti/TI_CGT_C6000_7.4.0

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./src/benchmark/ndkloopback.obj" \
"./src/benchmark/ndkbenchmark.obj" \
"./src/hpdspua.obj" \
"./src/system/resourcemgr.obj" \
"./src/system/platform_osal.obj" \
"./src/webpages/webserver.obj" \
"./src/webpages/webpage.obj" \
"./src/webpages/tasks.obj" \
"./src/webpages/statistics.obj" \
"./src/webpages/information.obj" \
"./src/webpages/i2cwrite.obj" \
"./src/webpages/i2cread.obj" \
"./src/webpages/flashwrite.obj" \
"./src/webpages/flashread.obj" \
"./src/webpages/flasherase.obj" \
"./src/webpages/flash.obj" \
"./src/webpages/diagpage.obj" \
"./src/webpages/diagnostic.obj" \
-l"libc.a" \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include src/webpages/subdir_vars.mk
-include src/system/subdir_vars.mk
-include src/subdir_vars.mk
-include src/benchmark/subdir_vars.mk
-include subdir_rules.mk
-include src/webpages/subdir_rules.mk
-include src/system/subdir_rules.mk
-include src/subdir_rules.mk
-include src/benchmark/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: hua_evmc6678l.out

# Tool invocations
hua_evmc6678l.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C6000 Linker'
	"/home/gtbldadm/ti/TI_CGT_C6000_7.4.0/bin/cl6x" -mv6600 --abi=eabi -g --define=_INCLUDE_NIMU_CODE --define=C66_PLATFORMS --define=_NDK_EXTERN_CONFIG --display_error_number --diag_warning=225 -z --stack_size=4096 -m"hua_evmc6678l.map" --heap_size=0x2710 -i"/home/gtbldadm/ti/TI_CGT_C6000_7.4.0/lib" -i"/home/gtbldadm/ti/TI_CGT_C6000_7.4.0/include" --reread_libs --warn_sections --rom_model -o "hua_evmc6678l.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_SRCS__QUOTED)$(GEN_MISC_FILES__QUOTED)$(C6000_EXECUTABLE_OUTPUTS__QUOTED)$(GEN_OPTS__QUOTED)$(GEN_CMDS__QUOTED) "hua_evmc6678l.out"
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-$(RM) "src/webpages/diagnostic.pp" "src/webpages/diagpage.pp" "src/webpages/flash.pp" "src/webpages/flasherase.pp" "src/webpages/flashread.pp" "src/webpages/flashwrite.pp" "src/webpages/i2cread.pp" "src/webpages/i2cwrite.pp" "src/webpages/information.pp" "src/webpages/statistics.pp" "src/webpages/tasks.pp" "src/webpages/webpage.pp" "src/webpages/webserver.pp" "src/system/platform_osal.pp" "src/system/resourcemgr.pp" "src/hpdspua.pp" "src/benchmark/ndkbenchmark.pp" "src/benchmark/ndkloopback.pp" 
	-$(RM) "src/webpages/diagnostic.obj" "src/webpages/diagpage.obj" "src/webpages/flash.obj" "src/webpages/flasherase.obj" "src/webpages/flashread.obj" "src/webpages/flashwrite.obj" "src/webpages/i2cread.obj" "src/webpages/i2cwrite.obj" "src/webpages/information.obj" "src/webpages/statistics.obj" "src/webpages/tasks.obj" "src/webpages/webpage.obj" "src/webpages/webserver.obj" "src/system/platform_osal.obj" "src/system/resourcemgr.obj" "src/hpdspua.obj" "src/benchmark/ndkbenchmark.obj" "src/benchmark/ndkloopback.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
