#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

def loadDataSet(filename):
    x = np.loadtxt(filename)
    return x

def gaussDensity(x, mu, sigma):
    return 1.0/np.sqrt(2.0*np.pi)/sigma * \
            np.exp(-1.0/(2.0*sigma**2)*(x-mu)**2)

def mixGauss(x):
    m = len(x) 
    w = np.random.rand(2, m)

    #parameters of model
    muOld = mu = np.random.rand(2)
    sigmaOld = sigma = np.random.rand(2)
    fiOld = fi = np.random.rand(2)
    
    isConverged = False
    epsion = 1e-10
    step = 0
    while not isConverged:
        print 'Step', step
        print mu[0], sigma[0], fi[0]
        print mu[1], sigma[1], fi[1]
        step += 1

        # E step
        w[0,:] = gaussDensity(x, mu[0], sigma[0]) * fi[0]
        w[1,:] = gaussDensity(x, mu[1], sigma[1]) * fi[1]
        w /= w.sum(axis=0)

        # M step
        wSum = w.sum(axis=1)
        fi = wSum / m
        mu[0] = np.sum(w[0]*x) / wSum[0]
        mu[1] = np.sum(w[1]*x) / wSum[1]
        sigma[0] = np.sqrt(np.dot(w[0]*(x-mu[0]), (x-mu[0]).T) / wSum[0])
        sigma[1] = np.sqrt(np.dot(w[1]*(x-mu[1]), (x-mu[1]).T) / wSum[1])

        isConverged = True
        if np.any(np.fabs(fi - fiOld) > epsion): isConverged = False
        if np.any(np.fabs(mu - muOld) > epsion): isConverged = False
        if np.any(np.fabs(sigma - sigmaOld) > epsion): isConverged = False

        muOld, sigmaOld, fiOld = mu, sigma, fi

    return w, mu, sigma, fi

def predict(mu, sigma, fi, x):
    pro = np.empty((2, len(x)))
    pro[0]  = gaussDensity(x, mu[0], sigma[0])
    pro[1]  = gaussDensity(x, mu[1], sigma[1])
    return np.dot(fi, pro)


if __name__ == '__main__':
    x = loadDataSet("data.txt")
    w, mu, sigma, fi = mixGauss(x)
    print 'RESULT:'
    print 'Gauss 0:', mu[0], sigma[0], fi[0]
    print 'Gauss 1:', mu[1], sigma[1], fi[1]
    
    x1 = x[w[0,:] > w[1,:]]
    x2 = x[w[0,:] <= w[1,:]]
    #plt.plot(x1, np.zeros(len(x1)), 'ro')
    #plt.plot(x2, np.zeros(len(x2)), 'b^')
    plt.hist(x1, 40, normed=True)
    plt.hist(x2, 40, normed=True)
    pred = predict(mu, sigma, fi, np.sort(x))
    plt.plot(np.sort(x), pred, 'r-', lw=2)
    plt.show()
