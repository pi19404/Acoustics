#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
override PKGDIR = custom/hpdspua/evmc6670l
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/PackageContents.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/PackageContents.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/xmlgen.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/xmlgen.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/BuildEnvironment.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/BuildEnvironment.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Repository.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Repository.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/package.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/package.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/services/global/Clock.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/services/global/Clock.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/services/global/Trace.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/services/global/Trace.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/_gen.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/_gen.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Library.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Library.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Executable.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Executable.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Utils.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Utils.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Script.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Script.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/ITarget.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/ITarget.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/ITargetFilter.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/ITargetFilter.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/xmlgen2.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/xmlgen2.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Manifest.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/Manifest.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/package.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/package.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/template.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/template.xs
package.mak: config.bld
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/om2.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/om2.xs
package.mak: package.bld
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/include/utils.tci:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/include/utils.tci
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/xdc.tci:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/xdc.tci
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/IPackage.xs:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/IPackage.xs
C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/bld.js:
package.mak: C:/Program\ Files/Texas\ Instruments/ccsv5/xdctools_3_20_08_88/packages/xdc/bld/bld.js
endif


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_custom.hpdspua.evmc6670l.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package custom.hpdspua.evmc6670l" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

ifneq (clean,$(MAKECMDGOALS))
-include package/package.cfg.dep
endif

package/package.ext.xml: package/package.cfg.xdc.inc
package/package.cfg.xdc.inc: $(XDCROOT)/packages/xdc/cfg/cfginc.js package.xdc
	@$(MSG) generating schema include file list ...
	$(CONFIG) -f $(XDCROOT)/packages/xdc/cfg/cfginc.js custom.hpdspua.evmc6670l $@

test:;
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,custom_hpdspua_evmc6670l
custom_hpdspua_evmc6670l.zip: package/build.cfg
custom_hpdspua_evmc6670l.zip: package/package.cfg.xdc.inc
custom_hpdspua_evmc6670l.zip: package/package.ext.xml
custom_hpdspua_evmc6670l.zip: package/package.xdc.inc
custom_hpdspua_evmc6670l.zip: package/package.bld.xml
custom_hpdspua_evmc6670l.zip: package/package.rel.dot
ifneq (clean,$(MAKECMDGOALS))
-include package/rel/custom_hpdspua_evmc6670l.zip.dep
endif
package/rel/custom_hpdspua_evmc6670l/custom/hpdspua/evmc6670l/package/package.rel.xml:

custom_hpdspua_evmc6670l.zip: package/rel/custom_hpdspua_evmc6670l.xdc.inc package/rel/custom_hpdspua_evmc6670l/custom/hpdspua/evmc6670l/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELZIP,package/rel/custom_hpdspua_evmc6670l.xdc.inc,package/rel/custom_hpdspua_evmc6670l.zip.dep)


release release,custom_hpdspua_evmc6670l: all custom_hpdspua_evmc6670l.zip
clean:: .clean
	-$(RM) custom_hpdspua_evmc6670l.zip
	-$(RM) package/rel/custom_hpdspua_evmc6670l.xdc.inc
	-$(RM) package/rel/custom_hpdspua_evmc6670l.zip.dep

clean:: .clean
	-$(RM) .libraries .libraries,*
clean:: 
	-$(RM) .dlls .dlls,*
#
# The following clean rule removes user specified
# generated files or directories.
#

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/external))
    $(shell $(MKDIR) package/external)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
endif
clean::
	-$(RMDIR) package

