#!/usr/bin/python

import sys
import numpy as np

if(len(sys.argv) != 3):
	print "<file> <count>"
	exit()

count = int(sys.argv[2])

v = np.fromfile(sys.argv[1], dtype=np.int64, count=count)

print v
