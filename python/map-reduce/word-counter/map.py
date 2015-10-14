#!/usr/bin/env python

import sys

for line in sys.stdin:
	line = line.strip()
	if line:
		line = line.split()
		for word in line:
			print word, 1