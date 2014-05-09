################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/system/platform_osal.obj: /home/pi19404/catkin_ws/src/Acoustics/dsp/src/system/platform_osal.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src" --include_path="/media/software/CCS/bios_6_34_02_18/packages/ti/bios/include" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src/webpages" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/csl" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/platform" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc/tools" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/qmss" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/cppi" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/transport/ndk/nimu" --define=_INCLUDE_NIMU_CODE --define=C66_PLATFORMS --define=_NDK_EXTERN_CONFIG --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/system/platform_osal.pp" --obj_directory="src/system" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/system/resourcemgr.obj: /home/pi19404/catkin_ws/src/Acoustics/dsp/src/system/resourcemgr.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src" --include_path="/media/software/CCS/bios_6_34_02_18/packages/ti/bios/include" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src/webpages" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/csl" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/platform" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc/tools" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/qmss" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/cppi" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/transport/ndk/nimu" --define=_INCLUDE_NIMU_CODE --define=C66_PLATFORMS --define=_NDK_EXTERN_CONFIG --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/system/resourcemgr.pp" --obj_directory="src/system" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


