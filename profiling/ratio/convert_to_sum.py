#!/usr/bin/python

import sys
import matplotlib.pyplot as plt
import numpy as np

if(len(sys.argv) != 2):
        print "Need preset num"
        exit()

v1 = np.fromfile(sys.argv[1]+"/profiling_8.txt", dtype=np.int64)
v2 = np.fromfile(sys.argv[1]+"/profiling_16.txt", dtype=np.int64)

print v1.size
print v2.size

vadd16 = np.array([1, 1, 0, 0, 1, 1])
vadd8 = np.array([1, 1, 0, 0, 0, 0, 0, 0, 1, 1])

vout16 = np.zeros(v2.size/4)
vout8 = np.zeros(v1.size/4)

for i in range(0, v2.size/4):
	istart = 16*(i/4) + (i%4)*2
	vcut = v2[istart:istart+vadd16.size]
	vout16[i] = np.vdot(vadd16, vcut)

print vout16[0]

for i in range(0, v1.size/4):
	istart = 32*(i/8) + (i%8)*2
	vcut = v1[istart:istart+vadd8.size]
	vout8[i] = np.vdot(vadd8, vcut)

vout16.astype(np.int64).tofile("profiling_32.txt")
vout8.astype(np.int64).tofile("profiling_16.txt")
