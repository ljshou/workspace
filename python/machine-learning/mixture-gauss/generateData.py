#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

N = 1000
mu1, sigma1 = 0, 0.1
x1 = np.random.normal(mu1, sigma1, 2*N)
mu2, sigma2 = 1.0, 0.1
x2 = np.random.normal(mu2, sigma2, N)

x = x1.tolist() + x2.tolist()
np.savetxt("data.txt", x)

plt.hist(x1, 20)
plt.hist(x2, 25)
plt.show()
#y = np.zeros(N)
#plt.plot(x1, y, 'ro')
#plt.plot(x2, y, 'b^')
#plt.show()
