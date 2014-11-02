#!/usr/bin/python

s1 = 'AATTGCCGTAATTGG'
s2 = 'TAATTGGTCGACGTGA'

matrix = [[0 for j in range(len(s2)+1)] for i in range(len(s1)+1)]

for i in range(len(s1)):
    for j in range(len(s2)):
        if s1[i] == s2[j]:
            matrix[i+1][j+1] = matrix[i][j] + 1
        else:
            matrix[i+1][j+1] = 0#max(matrix[i][j+1]-5, matrix[i+1][j]-5)
for i in range(len(s1)+1):
    print matrix[i]
length = 0
for j in xrange(len(s2)+1):
  if j == matrix[len(s1)][j]:
    if j > length: length = j
print "aligned length is", length
