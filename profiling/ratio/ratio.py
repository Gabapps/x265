#!/usr/bin/python

import sys
import matplotlib.pyplot as plt
import numpy as np

if(len(sys.argv) != 2):
        print "Need preset num"
        exit()

v1 = np.fromfile(sys.argv[1]+"/profiling_8.txt", dtype=np.int64)
v2 = np.fromfile(sys.argv[1]+"/profiling_16.txt", dtype=np.int64)
v1 = v1[v1 != 0]
v2 = v2[v2 != 0]

vadd16 = np.ndarray([1, 1, 0, 0, 1, 1, 0, 0])
vadd8 = np.ndarray([1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0])

vout16 = np.ndarray(v1)
vout8 = np.ndarray(v2)

for i in range(0, v1.size):
	vout16[i] = vadd16 * v1[:].T

for i in range(0, v2.size):
	

vout16.tofile("profiling_32_sum.txt")
vout8.tofile("profiling_16_sum.txt")
