import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("input2.txt")
x = range(0, 99)

p0 = plt.plot(x, data[:, 0], '*-', linewidth=3.5, label='fem')

p1 = plt.plot(x, data[:, 1], '>-', linewidth=3.5, label='mfree')

p2 = plt.plot(x, data[:, 2], '+-', linewidth=3.5, label='math')

p4 = plt.plot(x, data[:, 3], 'h-', linewidth=3.5, label='ref')

plt.title('Strip with Two Holes')
plt.xlabel('load steps')
plt.ylabel('movement of top-right tip')
plt.legend(loc='best')

plt.show()


