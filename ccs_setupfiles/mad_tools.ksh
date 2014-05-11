arp -i eth0 -s 192.168.2.100 40:5f:c2:bb:bb:3b
chmod 777 /dev/ttyUSB0
export DSP_REPO=/home/auv/catkin_ws/src/Acoustics/
cd $DSP_REPO/ccs_setupfiles/map-tool
python maptool.py config-files/maptoolCfg_C6670_bypass_prelink.json bypass-prelink
cp ./images/c6670-le.bin $DSP_REPO/tftp/app.out

