#!/usr/bin/python
import sys, os

def ComputeCoverage(file_name):
	input_file = open(file_name)
	header = input_file.readline().split()
	#print header
	url_indexes = header.index('Url1'), header.index('Url2'), header.index('Url3')
	count = 0
	covered = 0
	line = input_file.readline().split()
	while line:
		if line[url_indexes[0]] != '-'  or line[url_indexes[1]] != '-' or line[url_indexes[2]] != '-':
			covered += 1
		count += 1
		line = input_file.readline().split()
	#print covered, count, 1.0*covered/count
	return 1.0*covered/count

def ParseFile(folder_name):
	for root_i, dirs_i, files_i in os.walk(folder_name):
		for name in dirs_i:
			subdir = os.path.join(root_i, name)
			
			cov_t = 0.0 
			cov_c = 0.0
			for root_j, dirs_j, files_j in os.walk(subdir):
					for name in files_j:
						cov = ComputeCoverage(os.path.join(root_j, name))
						if name.find("globalSULT") != -1: 
							cov_t = cov
						else:
							cov_c = cov
			print subdir.split('_')[1], ":\t", cov_t, "\t", cov_c



#print ComputeCoverage("DailySBSwithG_de-DE\BingAnswer_globalSULT1_20150805_0.tsv")
#print ComputeCoverage("DailySBSwithG_de-DE\BingAnswer__20150805_0.tsv")

ParseFile("DailySBS")

