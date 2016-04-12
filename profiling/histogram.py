#!/usr/bin/python

import sys
import matplotlib.pyplot as plt
import numpy as np

if(len(sys.argv) != 2):
	print "Need preset num"
	exit()

v1 = np.fromfile("profiling/"+sys.argv[1]+"/profiling_8.txt", dtype=np.int64)
v2 = np.fromfile("profiling/"+sys.argv[1]+"/profiling_16.txt", dtype=np.int64)
v3 = np.fromfile("profiling/"+sys.argv[1]+"/profiling_32.txt", dtype=np.int64)
#b1 = v['state'] == 2;
#b2 = v['time'] < 3000;

#print v.size

#(hist, bins)=np.histogram(v['state'][:], bins=np.linspace(0, 7, 8))

#print 1000 * hist / v.size

plt.figure().suptitle("Preset " + sys.argv[1], fontsize=20)
#plt.hist(v['state'][:], bins=np.linspace(0, 7, 8))
#plt.pie(v['state'][:])
if(v1.size>0) :
	plt.subplot(311)
	plt.title("CPU Time 8x8")
	plt.hist(v1, bins=np.linspace(0, 2200, 100))
#	plt.hist(v1)

if(v2.size>0) :
	plt.subplot(312)
	plt.title("CPU Time 16x16")
	plt.hist(v2, bins=np.linspace(0, 4500, 100))

if(v3.size>0) :
	plt.subplot(313)
	plt.title("CPU Time 32x32")
	plt.hist(v3, bins=np.linspace(0, 20000,100))
plt.show()
