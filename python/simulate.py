#!/usr/bin/python
import random

def helper(vec):
    flag = False
    count = 0
    for i in range(len(vec)):
        if vec[i]:
            if flag: count +=1
            else: flag = True
        else:
            flag = False
    return count

N = 100000
score = 0
cnt = [0 for i in range(100)]
for i in range(N):
    count = 0
    for i in range(len(cnt)): cnt[i] = 0
    while count < 10:
        index = random.randrange(0,100)
        if cnt[index]: continue
        count += 1
        cnt[index] = 1
    score += helper(cnt)
print float(score) / N
