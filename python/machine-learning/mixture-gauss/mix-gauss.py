#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

def loadDataSet(filename):
    x = np.loadtxt(filename)
    np.random.shuffle(x)
    return x

def gaussDensity(x, mu, sigma):
    return 1/np.sqrt(2*np.pi)/sigma * \
            np.exp(-1/(2*sigma**2)*(x-mu)**2)

def mixGauss(x):
    m = len(x) 
    w = np.zeros((m, 2))

    #parameters of model
    muOld = mu = np.random.rand(2)
    sigmaOld = sigma = np.random.rand(2)
    fiOld = fi = np.random.rand(2)

    isConverged = False
    epsion = 1e-5
    step = 0
    while not isConverged:
        print 'Step', step
        print mu[0], sigma[0], fi[0]
        print mu[1], sigma[1], fi[1]
        step += 1

        # E step
        w[:,0] = gaussDensity(x, mu[0], sigma[0]) * fi[0]
        w[:,1] = gaussDensity(x, mu[1], sigma[1]) * fi[1]
        w /= w.sum(axis=1).reshape(m, 1)

        # M step
        wSum = w.sum(axis=0)
        assert(np.all(wSum != 0))
        fi = wSum / m
        mu = (w*x.reshape(m,1)).sum(axis=0)/wSum
        sigma = (w*(x.reshape(m,1)-mu)**2).sum(axis=0)/wSum

        isConverged = True
        if np.any(np.fabs(fi - fiOld) > epsion): isConverged = False
        if np.any(np.fabs(mu - muOld) > epsion): isConverged = False
        if np.any(np.fabs(sigma - sigmaOld) > epsion): isConverged = False

        muOld, sigmaOld, fiOld = mu, sigma, fi

    return w, mu, sigma, fi

if __name__ == '__main__':
    x = loadDataSet("data.txt")
    w, mu, sigma, fi = mixGauss(x)
    print 'RESULT:'
    print 'Gauss 0:', mu[0], sigma[0], fi[0]
    print 'Gauss 1:', mu[1], sigma[1], fi[1]
    x1 = x[w[:,0] > w[:,1]]
    x2 = x[w[:,0] <= w[:,1]]
    plt.plot(x1, np.zeros(len(x1)), 'ro')
    plt.plot(x2, np.zeros(len(x2)), 'b^')
    #plt.hist(x1)
    #plt.hist(x2)
    plt.show()
