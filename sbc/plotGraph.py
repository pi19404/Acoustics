################################################################################
# showdata.py
#
# Display analog data from Arduino using Python (matplotlib)
#
# electronut.in
#
################################################################################
 
import sys, serial
import numpy as np
from time import sleep
from collections import deque
from matplotlib import pyplot as plt
import sys
import csv
from pyqtgraph.Qt import QtGui, QtCore
#import numpy as np
import pyqtgraph as pg
from random import randint
import time

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


 
# class that holds analog data for N samples
class AnalogData:

	def __init__(self, maxLen):
		self.ax = deque([0.0]*maxLen)
		self.ay = deque([0.0]*maxLen)
		self.maxLen = maxLen
 
# ring buffer
	def addToBuf(self, buf, val):
		if len(buf) < self.maxLen:
			buf.append(val)
		else:
			buf.popleft()
			buf.append(val)
 
# add data
	def add(self, data):
		#assert(len(data) == 2)
		self.addToBuf(self.ax, data[0])
		self.addToBuf(self.ay, data[1])
		#print self.ax
# plot class

class AnalogPlot:
	def plotData(self,data1, data2):
		self.app = QtGui.QApplication([])
		self.win = pg.GraphicsWindow(title="Hydrophone data")
		self.hyd1=0
		self.hyd2=0
		self.curve1=0
		self.curve2=0

		    #global hyd1, hyd2, curve1, curve2, win
  	        print "Preparing GUI"

	        self.win.resize(1000,750)
	        self.win.setWindowTitle('data source: csv, data type: n(a,b)')

    # for pretty plots
	        #pg.setConfigOptions(antialias=True)

	    # first row
	        self.hyd1 = self.win.addPlot(title="Hydrophone 1")
	        self.hyd1.showGrid(x=True, alpha=0.75)
	        self.curve1 = self.hyd1.plot(data1, pen=(255,0,0))

	        self.win.nextRow()
	    # second row
	        self.hyd2 = self.win.addPlot(title="Hydrophone 2")
	        self.hyd2.showGrid(x=True, alpha=0.75)
	        self.curve2 = self.hyd2.plot(data2, pen=(0,0,255))


	def __init__(self, analogData):
# set plot to animated
		#plt.ion()
		#self.axline, = plt.plot(analogData.ax)
		#self.ayline, = plt.plot(analogData.ay)
		#plt.ylim([-1000,1000])
		#data1=deque([1]);
		#data1.append(1);
		self.plotData((analogData[0].ay),(analogData[1].ay));
 
# update plot
	def update(self, analogData):
		#self.axline.set_xdata(analogData.ax)
		#self.ayline.set_ydata(analogData.ay)
		#plt.draw()
   	        self.curve1.setData((analogData[0].ay))
		self.curve2.setData((analogData[1].ay))
 	        self.app.processEvents()

 


# main() function
def main(fileName1,fileName2):

	#fileName1='/home/sachin/auv/Server/hydrophone_60_30_625_0.txt'
	#fileName2='/home/sachin/auv/Server/hydrophone_60_30_625_1.txt'
 
# plot parameters
	analogData1 = AnalogData(2000);
	analogData2 = AnalogData(2000);
	analogPlot = AnalogPlot([analogData1,analogData2])
	cnt=0;
	tmpfile=fileName1
	with open(tmpfile, 'rb') as csvfile:
		        for row in csv.reader(csvfile):
				cnt=cnt+1;
	i=0;
	j=0;
	print 'plotting data...'
        k=0;
	while True:
		try:
		    print "row"+str(cnt)
		    if k==0:
	  	    	tmpfile=fileName1;
		    else:
			tmpfile=fileName2;
		    j=0;
		    i=0;
		    rc=0;
		    with open(tmpfile, 'rb') as csvfile:
		        for row in csv.reader(csvfile):
		            if i==cnt:
				rc=len(row);
				j=0;
				j1=0;				
		                while j < len(row)-1:
				    if k==0:
				    	analogData1.add([j1,int(row[j])]);
				    else:
					analogData2.add([j1,int(row[j])]);
				    j1=j1+1;
		                    j=j+100;
			    i=i+1;
		    csvfile.close();
		
 		    
		    if k==1 and rc!=0:
		    	analogPlot.update([analogData1,analogData2])
		    	cnt=cnt+1;
		    	#time.sleep(0.5);
		        k=0;
    		    elif k==0 and rc!=0:
		    	k=k+1;
		    else:
			k=0;
		    


		except KeyboardInterrupt:
			print 'exiting'
			break
 
# call main
if __name__ == '__main__':
        fileName = sys.argv[1] 
	fileName11='./'
	fileName21='./'
        fileName1 = fileName11 + fileName + '_0.txt'
        fileName2 = fileName21 + fileName + '_1.txt'
	main(fileName1,fileName2)
