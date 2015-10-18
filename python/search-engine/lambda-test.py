#!/usr/bin/env python

# L = [lambda x: x ** 2, lambda x: x ** 3, lambda x: x ** 4]
# 
L = []
power = [2, 3, 4]
# L.append(lambda x : x ** 2)
# L.append(lambda x : x ** 3)
# L.append(lambda x : x ** 4)
for i in range(len(power)):
	L.append(lambda x, i=i : x ** power[i])

print i
i = 1
print L[0](2)
print L[1](2)
print L[2](2)


for i in range(len(L)):
	print i, L[i](2)


print L[0](2), L[1](2), L[2](2)


L = []
power = [2, 3, 4]

for i in range(len(power)):
	L.append(lambda x : x ** power[i])

L = []
power = [2, 3, 4]

def Power(i):
    return lambda x : x ** power[i]

for i in range(len(power)):
    L.append(Power(i))
    

print L[0](2), L[1](2), L[2](2)