#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

N = 200
mu1, sigma1 = 0, 0.1
x1 = np.random.normal(mu1, sigma1, N)
mu2, sigma2 = 0.3, 0.3
x2 = np.random.normal(mu2, sigma2, N)
#mu3, sigma3 = 1.0, 0.1
#x3 = np.random.normal(mu3, sigma3, N)

x = x1.tolist() + x2.tolist() #+ x3.tolist()
np.savetxt("data.txt", x)

plt.hist(x1, 20)
plt.hist(x2, 25)
#plt.hist(x3, 25)
plt.show()
#y = np.zeros(N)
#plt.plot(x1, y, 'ro')
#plt.plot(x2, y, 'b^')
#plt.show()
