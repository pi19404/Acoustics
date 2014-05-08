#
_XDCBUILDCOUNT = 2
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = 
override XDCROOT = C:/ti/xdctools_3_23_01_43
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/xdctools_3_23_01_43/packages;../../..
HOSTOS = Windows
endif
