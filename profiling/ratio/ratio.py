#!/usr/bin/python

import os
import sys
import matplotlib.pyplot as plt
import numpy as np

if(len(sys.argv) != 3):
        print "<path> <cusize-x>"
        exit()

#os.system("sh convert_to_sum.py " + sys.argv[1])

v1 = np.fromfile(sys.argv[1]+"/profiling_" + sys.argv[2] + ".txt", dtype=np.int64)
v2 = np.fromfile("profiling_" + sys.argv[2] + ".txt", dtype=np.int64)

mask1 = (v1 != 0)
mask2 = (v2 != 0)

mask = np.ma.mask_or(mask1, mask2)

vout1 = v1[mask]
vout2 = v2[mask]

print v1.size
print v2.size

plt.scatter(vout1,vout2)
plt.show()
