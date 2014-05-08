################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/benchmark/ndkbenchmark.obj: /home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua/src/benchmark/ndkbenchmark.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/gtbldadm/ti/TI_CGT_C6000_7.4.0/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/home/gtbldadm/ti/TI_CGT_C6000_7.4.0/include" --include_path="/home/gtbldadm/ti/bios_6_33_06_50/packages/ti/bios/include" --include_path="/home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua/src" --include_path="/home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua/src/webpages" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/platform" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/transport/ndk/nimu" --include_path="/home/gtbldadm/ti/ndk_2_21_01_38/packages/ti/ndk/inc" --include_path="/home/gtbldadm/ti/ndk_2_21_01_38/packages/ti/ndk/inc/tools" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/drv/qmss" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/drv/cppi" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/drv/pa" --define=_INCLUDE_NIMU_CODE --define=C66_PLATFORMS --define=_NDK_EXTERN_CONFIG --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/benchmark/ndkbenchmark.pp" --obj_directory="src/benchmark" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/benchmark/ndkloopback.obj: /home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua/src/benchmark/ndkloopback.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/gtbldadm/ti/TI_CGT_C6000_7.4.0/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/home/gtbldadm/ti/TI_CGT_C6000_7.4.0/include" --include_path="/home/gtbldadm/ti/bios_6_33_06_50/packages/ti/bios/include" --include_path="/home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua/src" --include_path="/home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua/src/webpages" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/csl" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/platform" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/transport/ndk/nimu" --include_path="/home/gtbldadm/ti/ndk_2_21_01_38/packages/ti/ndk/inc" --include_path="/home/gtbldadm/ti/ndk_2_21_01_38/packages/ti/ndk/inc/tools" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/drv/qmss" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/drv/cppi" --include_path="/home/gtbldadm/ti/pdk_C6678_1_1_2_6/packages/ti/drv/pa" --define=_INCLUDE_NIMU_CODE --define=C66_PLATFORMS --define=_NDK_EXTERN_CONFIG --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/benchmark/ndkloopback.pp" --obj_directory="src/benchmark" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


