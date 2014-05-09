## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/evm_pe66.oe66 \

linker.cmd: package/cfg/evm_pe66.xdl
	$(SED) 's"^\"\(package/cfg/evm_pe66cfg.cmd\)\"$""\"/home/pi19404/catkin_ws/src/Acoustics/dsp/evmc6670l/Debug/configPkg/\1\""' package/cfg/evm_pe66.xdl > $@
