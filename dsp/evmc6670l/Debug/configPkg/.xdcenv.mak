#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/pi19404/catkin_ws/src/Acoustics/dsp;/media/software/CCS/ndk_2_21_01_38/packages;/media/software/CCS/pdk_C6670_1_1_2_6/packages;/media/software/CCS/mcsdk_2_01_02_06/demos;/media/software/CCS/ccsv5/ccs_base;/media/software/CCS/dsplib_c66x_3_1_0_0/packages;/media/software/CCS/edma3_lld_02_11_05_02/packages;/media/software/CCS/imglib_c66x_3_1_1_0/packages;/media/software/CCS/ipc_1_25_00_04/packages;/media/software/CCS/mathlib_c66x_3_0_1_1/packages;/media/software/CCS/openem_1_0_0_2/packages;/media/software/CCS/omp_1_01_03_02/packages;/media/software/CCS/bios_6_34_02_18/packages
override XDCROOT = /media/software/CCS/xdctools_3_23_04_60
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/pi19404/catkin_ws/src/Acoustics/dsp;/media/software/CCS/ndk_2_21_01_38/packages;/media/software/CCS/pdk_C6670_1_1_2_6/packages;/media/software/CCS/mcsdk_2_01_02_06/demos;/media/software/CCS/ccsv5/ccs_base;/media/software/CCS/dsplib_c66x_3_1_0_0/packages;/media/software/CCS/edma3_lld_02_11_05_02/packages;/media/software/CCS/imglib_c66x_3_1_1_0/packages;/media/software/CCS/ipc_1_25_00_04/packages;/media/software/CCS/mathlib_c66x_3_0_1_1/packages;/media/software/CCS/openem_1_0_0_2/packages;/media/software/CCS/omp_1_01_03_02/packages;/media/software/CCS/bios_6_34_02_18/packages;/media/software/CCS/xdctools_3_23_04_60/packages;..
HOSTOS = Linux
endif
