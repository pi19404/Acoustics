################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./src/system/resourcemgr.obj" \
"./src/system/platform_osal.obj" \
"./src/tpool.obj" \
"./src/logger.obj" \
"./src/hpdspua.obj" \
-l"ti.platform.evm6670l.ae66" \
-l"ti.transport.ndk.nimu.ae66" \
-l"libc.a" \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include src/subdir_vars.mk
-include src/system/subdir_vars.mk
-include subdir_rules.mk
-include src/subdir_rules.mk
-include src/system/subdir_rules.mk
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
all: hua_evmc6670l.out

# Tool invocations
hua_evmc6670l.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C6000 Linker'
	"/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6600 --abi=eabi -g --define=_INCLUDE_NIMU_CODE --define=C66_PLATFORMS --define=_NDK_EXTERN_CONFIG --display_error_number --diag_warning=225 -z --stack_size=4096 -m"hua_evmc6670l.map" --heap_size=0x2710 -i"/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/lib" -i"/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/include" -i"/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/transport/ndk/nimu/lib/debug" -i"/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/csl/lib" -i"/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/platform/evmc6670l/platform_lib/lib/debug" --reread_libs --warn_sections --rom_model -o "hua_evmc6670l.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_SRCS__QUOTED)$(GEN_MISC_FILES__QUOTED)$(C6000_EXECUTABLE_OUTPUTS__QUOTED)$(GEN_OPTS__QUOTED)$(GEN_CMDS__QUOTED) "hua_evmc6670l.out"
	-$(RM) "src/tpool.pp" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-$(RM) "src/hpdspua.pp" "src/logger.pp" "src/system/platform_osal.pp" "src/system/resourcemgr.pp" 
	-$(RM) "src/hpdspua.obj" "src/logger.obj" "src/tpool.obj" "src/system/platform_osal.obj" "src/system/resourcemgr.obj" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-@echo 'mad tools TFTP copy'
	-/usr/bin/mad_tools.ksh
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
