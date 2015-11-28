#!/usr/bin/env  python

import math

def func1(x, y):
	if abs(x) + abs(y) < abs(x - 100) + abs(y - 40):
		return 0
	else:
		return 1

def func2(x, y):
	if (x**2 + y**2) <= ((x- 100)**2 + (y - 40)**2):
		return 0
	else:
		return 1

print func1(53,10), func2(53,10) 
print func1(51,15), func2(51,15)  
print func1(61,10), func2(61,10) 
print func1(57,5), func2(57,5)
