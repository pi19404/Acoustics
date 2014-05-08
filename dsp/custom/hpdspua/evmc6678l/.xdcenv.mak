#
_XDCBUILDCOUNT = 5
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/PROGRA~1/TEXASI~1/ipc_1_21_00_14/packages;C:/PROGRA~1/TEXASI~1/bios_6_21_03_21/packages;C:/PROGRA~1/TEXASI~1/ipc_1_21_00_14/packages;C:/PROGRA~1/TEXASI~1/ti_ndk_src_2_20_00_02_eng/packages
override XDCROOT = C:/PROGRA~1/TEXASI~1/ccsv5/xdctools_3_20_08_88
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/PROGRA~1/TEXASI~1/ipc_1_21_00_14/packages;C:/PROGRA~1/TEXASI~1/bios_6_21_03_21/packages;C:/PROGRA~1/TEXASI~1/ipc_1_21_00_14/packages;C:/PROGRA~1/TEXASI~1/ti_ndk_src_2_20_00_02_eng/packages;C:/PROGRA~1/TEXASI~1/ccsv5/xdctools_3_20_08_88/packages;../../..
HOSTOS = Windows
endif
