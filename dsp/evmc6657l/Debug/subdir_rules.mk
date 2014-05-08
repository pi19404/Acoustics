################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../evm.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/home/gtbldadm/ti/xdctools_3_23_04_60/xs" --xdcpath="/home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua;/home/gtbldadm/ti/bios_6_33_06_50/packages;/home/gtbldadm/ti/ndk_2_21_01_38/packages;/home/gtbldadm/ti/mcsdk_2_01_02_06/demos;/home/gtbldadm/ti/pdk_C6657_1_1_2_6/packages;/home/gtbldadm/ti/ccsv5/ccs_base;" xdc.tools.configuro -o "configPkg" -t ti.targets.elf.C66 -p custom.hpdspua.evmc6657l -r debug -c "/home/gtbldadm/ti/TI_CGT_C6000_7.4.0" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


