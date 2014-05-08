################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../evm.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/media/software/CCS/xdctools_3_23_04_60/xs" --xdcpath="/media/software/CCS/ndk_2_21_01_38/packages;/media/software/hyd/hua;/media/software/CCS/bios_6_33_06_50/packages;/media/software/CCS/pdk_C6670_1_1_2_6/packages;/media/software/CCS/mcsdk_2_01_02_06/demos;/media/software/CCS/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p custom.hpdspua.evmc6670l -r release -c "/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


