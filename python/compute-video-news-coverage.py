#!/usr/bin/python
import sys, os

def ComputeVideoCoverage(file_name):
	input_file = open(file_name)
	header = input_file.readline().strip().split('\t')
	#print header
	video_indexes = header.index('ArticleHasVideo1'), header.index('ArticleHasVideo2'), header.index('ArticleHasVideo3')
	count = 0
	covered = 0
	line = input_file.readline().strip()
	while line:
		line = line.split('\t')
		print line[video_indexes[0]], line[video_indexes[1]], line[video_indexes[2]]
		if line[video_indexes[0]] == "True"  \
		or line[video_indexes[1]] == "True"  \
		or line[video_indexes[2]] == "True":
			covered += 1
		count += 1
		line = input_file.readline().strip()
	print covered, '\t', count, '\t', "%.2f%%" % (100 * 1.0*covered/count)
	return 1.0*covered/count

ComputeVideoCoverage("BingAnswer_videoNewsT1_20150922_0.tsv")