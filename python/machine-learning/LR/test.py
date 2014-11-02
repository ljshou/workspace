from numpy import*
import math

x = []
for i in range(10):
  x.append(i*0.1)
x = array(x)*6.28
y = 0.7*x**3 -5*x**2
for i in range(10):
  print x[i], y[i]
