################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/hpdspua.obj: /home/pi19404/catkin_ws/src/Acoustics/dsp/src/hpdspua.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6600 --abi=eabi -O3 -ms2 --symdebug:none --include_path="/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/transport/ndk/nimu" --include_path="/media/software/CCS/bios_6_33_06_50/packages/ti/bios/include" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src/webpages" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/csl" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/platform" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc/tools" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/qmss" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/cppi" --define=_NDK_EXTERN_CONFIG --define=_INCLUDE_NIMU_CODE --define=C66_PLATFORMS --display_error_number --diag_warning=225 --gen_opt_info=2 --call_assumptions=3 --preproc_with_compile --preproc_dependency="src/hpdspua.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/logger.obj: /home/pi19404/catkin_ws/src/Acoustics/dsp/src/logger.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6600 --abi=eabi -O3 -ms2 --symdebug:none --include_path="/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/transport/ndk/nimu" --include_path="/media/software/CCS/bios_6_33_06_50/packages/ti/bios/include" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src/webpages" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/csl" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/platform" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc/tools" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/qmss" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/cppi" --define=_NDK_EXTERN_CONFIG --define=_INCLUDE_NIMU_CODE --define=C66_PLATFORMS --display_error_number --diag_warning=225 --gen_opt_info=2 --call_assumptions=3 --preproc_with_compile --preproc_dependency="src/logger.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/tpool.obj: /home/pi19404/catkin_ws/src/Acoustics/dsp/src/tpool.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/bin/cl6x" -mv6600 --abi=eabi -O3 -ms2 --symdebug:none --include_path="/media/software/CCS/ccsv5/tools/compiler/c6000_7.4.1/include" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/transport/ndk/nimu" --include_path="/media/software/CCS/bios_6_33_06_50/packages/ti/bios/include" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src" --include_path="/home/pi19404/catkin_ws/src/Acoustics/dsp/src/webpages" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/csl" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/platform" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc" --include_path="/media/software/CCS/ndk_2_21_01_38/packages/ti/ndk/inc/tools" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/qmss" --include_path="/media/software/CCS/pdk_C6670_1_1_2_6/packages/ti/drv/cppi" --define=_NDK_EXTERN_CONFIG --define=_INCLUDE_NIMU_CODE --define=C66_PLATFORMS --display_error_number --diag_warning=225 --gen_opt_info=2 --call_assumptions=3 --preproc_with_compile --preproc_dependency="src/tpool.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


