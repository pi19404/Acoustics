## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/evm_pe66.oe66 \

linker.cmd: package/cfg/evm_pe66.xdl
	$(SED) 's"^\"\(package/cfg/evm_pe66cfg.cmd\)\"$""\"/home/gtbldadm/ti/mcsdk_2_01_02_06/demos/hua/evmc6670l/Release/configPkg/\1\""' package/cfg/evm_pe66.xdl > $@
