#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

def loadData(file_name):
    data = np.loadtxt(file_name)
    return data

def plotLine(weight):
    print 'ploting line', weight
    x = np.arange(-2, 14, 0.1)
    y = (-weight[0]-weight[1]*x)/weight[2]
    plt.plot(x, y)

def plotBestfit(data, weight):
    xcoord1 = []; ycoord1 = []
    xcoord2 = []; ycoord2 = []
    for i in range(len(data)):
        if data[i, 2] == -1:
            xcoord1.append(data[i, 0])
            ycoord1.append(data[i, 1])
        else:
            xcoord2.append(data[i, 0])
            ycoord2.append(data[i, 1])

    plt.scatter(xcoord1, ycoord1, s=90, c='red', marker='^')
    plt.scatter(xcoord2, ycoord2, s=90, c='green', marker='o')

    plotLine(weight)
    
    plt.xlabel('X1')
    plt.ylabel('X2')
    plt.show()

maxIteration = 1e3

def Perceptron(data):
    weight = [0, 0, 0]
    learningRate = 1.0 
    step = 0
    while step < maxIteration:
        step += 1
        isConverged = True
        for i in range(len(data)):
            x1, x2, y = data[i]
            predict = -1 
            if weight[0] + weight[1]*x1 + weight[2]*x2 >= 0:
                predict = 1
            if predict != y:
                weight[0] += learningRate * y 
                weight[1] += learningRate * y * x1
                weight[2] += learningRate * y * x2
                isConverged = False
                break #stocastic gradient descent
        if isConverged: return weight
        print weight

    return weight


if __name__ == "__main__":
    data = loadData("testSet.txt")
    weight = Perceptron(data)
    plotBestfit(data, weight)
