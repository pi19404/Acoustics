export DSP_REPO=/home/auv/catkin_ws/src/Acoustics/
cd $DSP_REPO/ccs_setupfiles
ln -s /opt/ti/mcsdk_2_01_02_06/tools/boot_loader/mad-utils/map-tool map-tool
cp deployment_template_C6670_bypass_prelink.json map-tool/config-files
cp maptoolCfg_C6670_bypass_prelink.json map-tool/config-files
ln -s $DSP_REPO/ccs_setupfiles/mad_tools.ksh /usr/bin/mad_tools.ksh 
chmod 755 mad_tools.ksh
chown root mad_tools.ksh
chgrp root mad_tools.ksh
chmod u+s mad_tools.ksh
gcc sudo_power.c -o mad_tools
chmod 777 mad_tools
chown root mad_tools
chgrp root mad_tools
chmod u+s mad_tools
cp tftp.conf  /etc/xinetd.d/tftp
sudo /etc/init.d/xinetd restart


