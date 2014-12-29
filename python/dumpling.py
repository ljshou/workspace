#!/usr/bin/env python
import sys

def compute(m,n,f,g):
    if n > m: return -1
    for i in range(m+1):
        f[i][0][0] = 1
    for j in range(n+1):
        f[0][j][0] = 0
        g[0][j][0] = 0
    f[0][0][0] = 1
    g[0][0][0] = 1

    for i in range(1,m+1):
        for j in range(1,min(i,n)+1):
            for k in range(0,j):
                f[i][j][k] = f[i-1][j][k] + g[i-1][j][k]

                if k != 0: g[i][j][k] = f[i-1][j-1][k] + g[i-1][j-1][k-1]
                else: g[i][j][k] = f[i-1][j-1][k]
   
    cnt = [0 for i in range(n)]            
    for k in range(0,n):
        cnt[k] = f[100][10][k] + g[100][10][k]
    print cnt[1:]


    #(100, 10)
    allSum = 1.0
    for i in range(91,101):  allSum = allSum * i
    for i in range(1,11): allSum /= i

    allSum2 = 0
    for i in range(1,n): allSum2 += (i * cnt[i])
    print allSum2/float(allSum)
    
if __name__ == "__main__":
    m = 100 
    n = 10 
    k = n-1
    f = [[[0 for k in range(k+1)] for j in range(n+1)] for i in range(m+1)]
    g = [[[0 for k in range(k+1)] for j in range(n+1)] for i in range(m+1)]

    compute(m,n,f,g)
