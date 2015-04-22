import math
import matplotlib.pyplot as plt
import numpy as np

def f(x):
    return (x**4 -x**3 +3*x**2 - x)

# first order derivative
def f1(x):
    return (4*x**3 - 3*x**2 + 6*x - 1)

# second order derivative
def f2(x):
    return (12*x**2 - 6*x + 6)

x = np.arange(-120, 50, 0.1)
y = f(x)
plt.plot(x, y, 'r', linewidth=4)

interval = np.arange(-40, 50, 0.1)
maxnIteration = 20
tol = 1e-10

iter = 0
xn = -80.0
old_xn = xn
error = 1.0

while iter < maxnIteration and error > tol: 
    iter += 1

    print xn
    plt.plot(xn, f(xn), 'ob', markersize=10)

    x = interval + xn
    y = f(xn) + (x-xn)*f1(xn) + 0.5*(x-xn)**2 * f2(xn)
    plt.plot(x, y, 'b', linewidth=1)

    xn = xn - f1(xn)/f2(xn)
    error = math.fabs(xn - old_xn)
    old_xn = xn

plt.title('Newton-Raphson Method')
plt.xlabel('x')
plt.ylabel('y')
plt.show()
