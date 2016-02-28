#!/usr/bin/env python

import sys

(last_key, count) = (None, 0)
for line in sys.stdin:
	(key, val) = line.strip().split()
	if last_key and last_key == key:
		count += val
	else:
		print last_key, count
		last_key = key
		count = val