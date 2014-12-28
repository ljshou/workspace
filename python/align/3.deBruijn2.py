#!/usr/bin/env python

__author__ = "QingXu"

'build the de Bruijn graph'

import sys
import getopt


########### analysis command line #########
def usage():
	print '[USAGE] ./3.deBruijn2.py -K [Kmer size] -b [Bin size,default 1]' 
	sys.exit()

opts, args = getopt.getopt(sys.argv[1:],"K:b:")
if len(opts) < 1:
	usage()
	sys.exit()

for op , value in opts:
	if op == "-K":
		K = int(value)
	elif op == "-b":
		binSize = int(value)
	else:
		break

if binSize == -1: binSize = 1 #default value

########################################


########### read input #################
print "[Info] read input"

f = open("./input.bins","r")
all_contigs = []
try:
    while 1:
        line = f.next().strip()
        part = line.split()
        for i in range(len(part)):
            part[i] = int(part[i])
        all_contigs.append(part)
except:
    f.close()
    info = sys.exc_info()
    print "[Info] ", info[0], info[1]
    print "[Info] all_contigs len = " ,len(all_contigs)
########################################


########### define align function #####
def valid(pos1,pos2):
	return abs(pos1-pos2) <= 1

def align(left,start_i, end_i, right, start_j, end_j):
	global all_contigs
	len1 = len(left)
	len2 = len(right)
	i ,j = start_i, start_j
	cnt = 0
	curLen = [0,0]
	flag1 = False
	flag2 = False
	while i < end_i and j < end_j:
		print i, j, curLen[0], curLen[1]
		if valid(curLen[0] + left[i] , curLen[1] + right[j]):
			i ,j ,cnt = i+1,j+1,cnt+1
			curLen = [0,0]
			flag1 = False
			flag2 = False
		else:
			if flag1 and flag2 : return i == end_i and j == end_j
			if left[i] < right[j]:
				curLen[0] += left[i]
				i += 1
				if flag1: return i ==  end_i and j == end_j
				flag1 = True
			else:
				curLen[1] += right[j]
				j += 1
				if flag2: return i == end_i and j == end_j
				flag2 = True
	return i == end_i and j == end_j

	  
def align2(left,start_i, end_i, right, start_j, end_j):
	global all_contigs
	len1 = len(left)
	len2 = len(right)
	i ,j = start_i, start_j
	cnt = 0
	curLen = [0,0]
	flag1 = False
	flag2 = False
	while i < end_i and j < end_j:
		print i, j, curLen[0], curLen[1]
		ret1 ,ret2 = False, False
		if valid(curLen[0] + left[i] , curLen[1] + right[j]):
			ret = align2(left,i+1,end_i,right,j+1,end_j)
			if ret == True: return True
			#if i+1 == end_i or j +1 == end_j: return False
			#else
			if curLen[0] == 0 and i+1 < end_i:
				if valid(left[i] + left[i+1], curLen[1] + right[j]):
					Flag1 = True
					ret1 = align2(left,i+2, end_i, right,j+1, end_j)

			if curLen[1] == 0 and j+1 < end_j:
				if valid(curLen[0] + left[i],right[j] + right[j+1]):
					Flag2 = True
					ret2 = align2(left,i+1,end_i, right, j+2,end_j)
			return ret1 or ret2
			#i ,j ,cnt = i+1,j+1,cnt+1
			#curLen = [0,0]
			#flag1 = False
			#flag2 = False
		else:
			if flag1 and flag2 : return i == end_i and j == end_j
			if left[i] < right[j]:
				curLen[0] += left[i]
				i += 1
				if flag1: return i ==  end_i and j == end_j
				flag1 = True
			else:
				curLen[1] += right[j]
				j += 1
				if flag2: return i == end_i and j == end_j
				flag2 = True
	return i == end_i and j == end_j



def readInput():
	f = open("in","r")
	f.next()
	f.next()
	line = f.next().strip()
	left = line.split()
	line = f.next().strip()
	right = line.split()
	for i in range(len(left)): left[i] = int(left[i])
	for i in range(len(right)): right[i] = int(right[i])
	return left, right

left,right = readInput()
print left
print right
print align(left,0,len(left),right,0,len(right))
print align2(left,0,len(left),right,0,len(right))
######################################
	
