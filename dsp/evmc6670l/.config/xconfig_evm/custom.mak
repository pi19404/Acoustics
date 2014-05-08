## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/evm_pe66.oe66 \

linker.cmd: package/cfg/evm_pe66.xdl
	$(SED) 's"^\"\(package/cfg/evm_pe66cfg.cmd\)\"$""\"/media/software/hyd/hua/evmc6670l/.config/xconfig_evm/\1\""' package/cfg/evm_pe66.xdl > $@
