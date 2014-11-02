#!/usr/bin/python

s1 = 'GCTGATGCAATCGA'
s2 = 'CAATCGATGTCATG'

matrix = [0 for j in range(len(s2)+1)]

for i in range(len(s1)):
    for j in xrange(len(s2)-1, -1, -1): #j decrease
        if s1[i] == s2[j]:
            matrix[j+1] = matrix[j] + 1
        else:
            matrix[j+1] = 0#max(matrix[i][j+1]-5, matrix[i+1][j]-5)
print matrix

# OutPut the result
length = 0
for j in xrange(len(s2), -1, -1):
  if j == matrix[j]:
    if j > length: 
		length = j
		break
print s1
print s2
print "aligned length is", length
