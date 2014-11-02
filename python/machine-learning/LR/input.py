from numpy import *

def file2matrix(filename):
  fr = open(filename)
  arrayOfLines = fr.readlines()
  numberOfLines = len(arrayOfLines)
  Mat = zeros((numberOfLines, 2)) 
  index = 0
  for line in arrayOfLines:
    line = line.strip()
    listFromLine = line.split()
    Mat[index, :] = listFromLine[0:2]
    index += 1
  x = Mat[:,0]
  print 'printing x:'
  y = Mat[:,1]
  print 'printing y:'
  return x,y
