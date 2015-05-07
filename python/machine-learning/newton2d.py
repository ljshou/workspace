from numpy import *
from random import *
import matplotlib.pyplot as plt

def f(x1, x2):
    return 0.5*(x1**2 + 10*x2**2)
def fx(x1, x2):
    return x1
def fy(x1, x2):
    return 10*x2

def plotContour():
    x = arange(-12, 12, 0.1)
    y = arange(-5, 5, 0.1)
    z = [[f(x1, x2) for x1 in x] for x2 in y]
    plt.contour(x, y, z, 10)
    #plt.show()

maxIter = 100
errorTol = 1e-10
learningRate = 0.1

def CoordinateDescent(x1, x2):
    iter = 0
    error = 1e5
    flag = True
    while error > errorTol and iter < maxIter:
        iter += 1
        #print x1, x2
        plt.plot(x1, x2, 'ro')
        if flag:
            x1 -= (learningRate/iter + 0.1) * fx(x1, x2)
            flag = False
        else:
            x2 -= (learningRate/iter + 0.1) * fy(x1, x2)
            flag = True
        error = fabs(f(x1, x2))

def GradDescent(x1, x2):
    iter = 0
    error = 1e5
    while error > errorTol and iter < maxIter:
        iter += 1
        #print x1, x2
        plt.plot(x1, x2, 'go')

        x1 -= (learningRate/iter+0.1) * fx(x1, x2)
        x2 -= (learningRate/iter+0.1) * fy(x1, x2)
        error = fabs(f(x1, x2))

if __name__ == "__main__":
    plotContour()
    x1, x2 = (10, 1)
    #CoordinateDescent(x1, x2)
    GradDescent(x1, x2)
    plt.show()
