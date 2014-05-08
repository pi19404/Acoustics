#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/gtbldadm/ti/ndk_2_21_01_38/packages;/home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua;/home/gtbldadm/ti/bios_6_33_06_50/packages;/home/gtbldadm/ti/pdk_C6670_1_1_2_6/packages;/home/gtbldadm/ti/mcsdk_2_01_02_06/demos;/home/gtbldadm/ti/ccsv5/ccs_base
override XDCROOT = /home/gtbldadm/ti/xdctools_3_23_04_60
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/gtbldadm/ti/ndk_2_21_01_38/packages;/home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua;/home/gtbldadm/ti/bios_6_33_06_50/packages;/home/gtbldadm/ti/pdk_C6670_1_1_2_6/packages;/home/gtbldadm/ti/mcsdk_2_01_02_06/demos;/home/gtbldadm/ti/ccsv5/ccs_base;/home/gtbldadm/ti/xdctools_3_23_04_60/packages;..
HOSTOS = Linux
endif
