import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("input.txt")
x = range(0, 155, 5)

p0 = plt.plot(x, data[:, 0], '*-', linewidth=3.5, label='fem_ref')
#plt.scatter(x, data[:, 0])

p1 = plt.plot(x, data[:, 1], '>-', linewidth=3.5, label='mfree')
#plt.scatter(x, data[:, 1])

p2 = plt.plot(x, data[:, 2], '+-', linewidth=3.5, label='interface')
#plt.scatter(x, data[:, 2])

p4 = plt.plot(x, data[:, 4], 'h-', linewidth=3.5, label='math')
#plt.scatter(x, data[:, 4])

plt.title('Assembly Mesh Cantilever Bending')
plt.xlabel('load steps')
plt.ylabel('movement of cantilever tip')
plt.legend(loc='best')

plt.show()


