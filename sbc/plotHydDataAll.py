#! /usr/bin/python

import sys
import csv
from pyqtgraph.Qt import QtGui, QtCore
#import numpy as np
import pyqtgraph as pg
import thread
import threading
import rospy
import roslib
import time
from std_srvs.srv import *

roslib.load_manifest('auv_debug')

#prepare datasets
data1=[]
data2=[]
alive=True
fileName1='Server/'
fileName2='Server/'
hyd1=0
hyd2=0
curve1=0
curve2=0
#prepre GUI
app = QtGui.QApplication([])
win = pg.GraphicsWindow(title="Hydrophone data")
currentRow1 =0;
currentRow2 =0;




def plotData(data1, data2):
    global hyd1, hyd2, curve1, curve2, win
    print "Preparing GUI"

    win.resize(1000,750)
    win.setWindowTitle('data source: csv, data type: n(a,b)')

    # for pretty plots
    pg.setConfigOptions(antialias=True)

    # first row
    hyd1 = win.addPlot(title="Hydrophone 1")
    hyd1.showGrid(x=True, alpha=0.75)
    curve1 = hyd1.plot(data1, pen=(255,0,0))

    win.nextRow()
    # second row
    hyd2 = win.addPlot(title="Hydrophone 2")
    hyd2.showGrid(x=True, alpha=0.75)
    curve2 = hyd2.plot(data2, pen=(0,0,255))

def graphPlotCallBack(i):
    print("Thread started");
    global alive,data1, data2, fileName1,fileName2,currentRow1,currentRow2
    print("SHould be updating graph");
    readFile(fileName1,fileName2)
    curve1.setData(data1)
    curve2.setData(data2)
    currentRow1 = currentRow1 + 1
    currentRow2 = currentRow2 + 1
    return EmptyResponse()



def plotServer():
    global data1, data2, fileName1,fileName2,alive
    #readFile(fileName1,fileName2)
    data1.append(int(0));
    data2.append(int(0));
    plotData(data1, data2)
    graphPlotCallBack(0);

    rospy.init_node('graph_plot_server')
    #server = rospy.Service('/auv_debug/hydrophone_interface/graph_plot', Empty, graphPlotCallBack)
    #t =threading.Thread(target=graphPlotCallBack, args=(1,));
    #t.start();
#   r = rospy.Rate(10) # 10hz
#   while not rospy.is_shutdown():
#   rospy.spin()
#       r.sleep()
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtGui.QApplication.instance().exec_()
    #alive = False
    #t.join();

## Start Qt event loop unless running in interactive mode or using pyside.
if __name__ == '__main__':
        print sys.argv[1];
        fileName = sys.argv[1] 
        fileName1 = fileName1 + fileName + '_0.txt'
        fileName2 = fileName2 + fileName + '_1.txt'
        plotServer()
