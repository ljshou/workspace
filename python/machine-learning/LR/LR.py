'''
copyright @ L.J.SHOU
this is a simple Linear Regression implementation. 
pysedo-inverse is used to compute weight vector.
w = (x'*x).inv * x' * y
'''

from numpy import *
import input
x,y = input.file2matrix('data')
x2 = x**2
x3 = x**3
x4 = x**4
x5 = x**5
x6 = x**6
x7 = x**7
x8 = x**8
x9 = x**9
x10 = x**10
x11 = x**11
x12 = x**12
x13 = x**13
x14 = x**14
x15 = x**15
x16 = x**16
x17 = x**17

x = mat(x).transpose()
y = mat(y).transpose()

x = append(ones([len(x),1]), x, 1)
x = append(x, mat(x2).transpose(), 1)
x = append(x, mat(x3).transpose(), 1)
'''
x = append(x, mat(x4).transpose(), 1)
x = append(x, mat(x5).transpose(), 1)
x = append(x, mat(x6).transpose(), 1)
x = append(x, mat(x7).transpose(), 1)
x = append(x, mat(x8).transpose(), 1)
x = append(x, mat(x9).transpose(), 1)
x = append(x, mat(x10).transpose(), 1)
x = append(x, mat(x11).transpose(), 1)
x = append(x, mat(x12).transpose(), 1)
x = append(x, mat(x13).transpose(), 1)
x = append(x, mat(x14).transpose(), 1)
x = append(x, mat(x15).transpose(), 1)
x = append(x, mat(x16).transpose(), 1)
x = append(x, mat(x17).transpose(), 1)
'''

w = (x.transpose() * x).I * x.transpose() * y
print w


# plot 
import pylab as pl
pl.title('Linear regression')
pl.xlabel('x axis')
pl.ylabel('y axis')

x = array(x[:,1])
y = array(y)
w = array(w)
pl.plot(x, y, 'o')# use pylab to plot x and y

x1 = []
for i in range(600):
  x1.append(-0.1+0.01*i)
x1 = array(x1)
y1 = w[0] + w[1]*x1 + w[2]*x1**2 + w[3]*x1**3 #+ w[4]*x1**4 + w[5]*x1**5 \
   #+ w[6]*x1**6 + w[7]*x1**7 #+ w[8]*x1**8 + w[9]*x1**9 + w[10]*x1**10 \
   #+ w[11]*x1**11 + w[12]*x1**12 + w[13]*x1**13 + w[14]*x1**14 \
   #+ w[15]*x1**15 + w[16]*x1**16 + w[17]*x1**17 
pl.plot(x1, y1)

new_x = array(random.random(20)*6)
new_y = 0.7*new_x**3 - 5*new_x**2
pl.plot(new_x, new_y, 'or')
pl.show()# show the plot on the screen


