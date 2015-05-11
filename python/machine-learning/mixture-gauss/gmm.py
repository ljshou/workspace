#!/usr/local/bin/python3
#enconding=uft-8
"""
GMM algorithm
"""
import numpy as np
from numpy import matlib,random,linalg
from matplotlib import pyplot as plt
 
#load data from file
def loadData(filename):
    dataMat=np.genfromtxt(filename)
    return dataMat
 
#generate simulation data,generate three Gaussian Distributions here
def gene1DData(K=1,nSmp=200): #K is the number of Gaussian Distributions
    mu=np.linspace(-1,1,K)
    sigma=np.random.uniform(0,1,K)
    data=np.zeros((K,nSmp))
    for idx in range(K):
        data[idx]=np.random.normal(mu[idx],sigma[idx],nSmp)
    return data.reshape(1,-1),mu.reshape(1,K),sigma.reshape(K,1,1)
 
 
class GMM:
    def __init__(self,K=0,phi=np.array([]),mu=np.array([]),sigma=np.array([])):
        self.K=K #number of Gaussian components
        self.phi=phi #1*k ndarray
        self.mu=mu #n*k ndarray
        self.sigma=sigma #k*n*n ndarray
    def __init_parameters(self,k,n): #private attribute
        self.phi=np.random.rand(k,)
        self.mu=np.random.rand(n,k)
        self.sigma=np.random.rand(k,n,n)
        for idx in range(k):
            self.sigma[idx]=np.eye(n)
    def __computeGaussPro(self,X): #compute probability according to Gaussian Distribution
        nDim,nSmp=X.shape #number of features and samples
        Pro=np.random.rand(self.K,nSmp)
        for idx in range(self.K):
            detSigmaK=linalg.det(self.sigma[idx])
            invSigmaK=linalg.inv(self.sigma[idx])
            muK=self.mu[:,idx]
            for idy in range(nSmp):
                sample=X[:,idy]
                t=sample-muK
                Pro[idx,idy]=np.exp(-np.dot(np.dot(t,invSigmaK).T,t)/2)
                Pro[idx,idy]/=(np.power(2*np.pi,nDim/2)*(np.sqrt(detSigmaK)))
        return Pro
    def __computeLogLikelihood(self,Pro):#comupte the log likelihood
        val=np.dot(Pro.T,self.phi)
        return np.sum(np.log(val))
 
    def train(self,X): #N*M ndarray for training GMM,each column is a sample
        N,M=X.shape
        if not self.phi.shape[0]*self.mu.shape[0]*self.sigma.shape[0]:
            self.__init_parameters(self.K,N)
        tolerance=1e-3 #threshold of convergence
        convergence=False
        obj_old=-1e10
        obj_his=[] #stroing the objective function of each iteration
        while not convergence:
            Pro=self.__computeGaussPro(X)
            obj=self.__computeLogLikelihood(Pro)
            diff=obj-obj_old
            print('Diff:%f' %diff)
            if np.fabs(diff)<tolerance:
                break;
            obj_old=obj
            obj_his.append(obj)
            #E-step
            Q=(self.phi*Pro.T).T #used for storing p(z=k|x_i)
            Q/=np.sum(Q,axis=0)
            #M-step
            self.phi=(np.sum(Q.T,axis=0)/M)
            for idx in range(self.K):
                self.mu[:,idx]=np.sum(Q[idx]*X,axis=1)/sum(Q[idx])
                X1=X-self.mu[:,idx].reshape(N,1)
                self.sigma[idx]=np.dot(Q[idx]*X1,X1.T)/sum(Q[idx])
         
        return self.phi,self.mu,self.sigma,obj_his
    def predict(self,testdata):
        pro=self.__computeGaussPro(testdata)
        val=np.dot(self.phi,pro)
        return val #the estimated probability value
 
def plotGMM(x,predi,nSmp):
    data=x.reshape(-1,nSmp)
    k=data.shape[0]
    for i in range(k):
        plt.hist(data[i],40,normed=True)
    plt.plot(np.sort(x[0]),pred,'r-',lw=2)
    plt.xlabel('x') #'$...$' will trigger later interpreter
    plt.ylabel('Probabilistic Denstiy Function')
    plt.title('GMM')
    plt.show()
    #plt.savefig('GMM.png',dpi=120) #save a figure
 
def plotObjVal(data):
    plt.plot(data,'g-',linewidth=2)
    plt.grid(True)
    plt.xlabel('#Iteration')
    plt.ylabel('Value of Log-likelihood')
    plt.title('Convergence Analysis')
    plt.show()
    #plt.savefig('GMM_convergence.png')
 
if __name__=='__main__':
    nSmp=800
    x,mu,sigma=gene1DData(3,nSmp)
    gmm=GMM(3)
    phi,mu,sigma,his=gmm.train(x)
    print(phi,mu,sigma)
    plotObjVal(his)
    pred=gmm.predict(np.sort(x))
    plotGMM(x,pred,nSmp)