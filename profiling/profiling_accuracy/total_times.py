#!/usr/bin/python

import sys
import matplotlib.pyplot as plt
import numpy as np

arg=""

if(len(sys.argv) != 2):
        arg="."
else:
	arg=sys.argv[1]

v1 = np.fromfile(arg+"/profiling_total.txt", dtype=np.dtype([("oneshot", np.int64), ("cumulated", np.int64)]))

diff = (v1["oneshot"] - v1["cumulated"]).astype(float) / v1["oneshot"].astype(float)

plt.figure().suptitle("Total CTU analysis time compared to profiling time", fontsize=20)
plt.figure(1)
plt.subplot(2,1,1)
plt.title("CTU Total Time")
plt.hist(v1["oneshot"], bins=200)

plt.subplot(2,1,2)
plt.title("CTU with CU cumulated Time")
plt.hist(v1["cumulated"], bins=200)

plt.figure(2)
plt.title("Time error")
plt.hist(diff, bins=200)


plt.show()
