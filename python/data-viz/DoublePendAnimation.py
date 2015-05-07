from visual import *

# The analysis is in terms of Lagrangian mechanics.
# The Lagrangian variables are angle of upper bar, angle of lower bar,
# measured from the vertical.

twopendula = 0 # if true, show two pendula
different = 1 # if true, start with theta1 differing by 0.001 radians

print """
Set twopendula = 1 to show two identical pendula.
Set different = 1 to make initial upper angles differ by 0.001 radian.
"""

print 'Currently, twopendula =', twopendula, ', different =', different,'.'
print 'Click to start the motion.'

scene.title = 'Double Pendulum'
scene.height = scene.width = 800

g = 9.8
M1 = 2.0
M2 = 1.0
d = 0.05 # thickness of each bar
gap = 2.*d # distance between two parts of upper, U-shaped assembly
L1 = 0.5 # physical length of upper assembly; distance between axles
L1display = L1+d # show upper assembly a bit longer than physical, to overlap axle
L2 = 1.0 # physical length of lower bar
L2display = L2+d/2. # show lower bar a bit longer than physical, to overlap axle
# Coefficients used in Lagrangian calculation
A = (1./4.)*M1*L1**2+(1./12.)*M1*L1**2+M2*L1**2
B = (1./2.)*M2*L1*L2
C = g*L1*(M1/2.+M2)
D = M2*L1*L2/2.
E = (1./12.)*M2*L2**2+(1./4.)*M2*L2**2
F = g*L2*M2/2.

hpedestal = 1.3*(L1+L2) # height of pedestal
wpedestal = 0.1 # width of pedestal
tbase = 0.05 # thickness of base
wbase = 8.*gap # width of base
offset = 2.*gap # from center of pedestal to center of U-shaped upper assembly
top = vector(0,0,0) # top of inner bar of U-shaped upper assembly
scene.center = top-vector(0,(L1+L2)/2.,0)

pedestal = box(pos=top-vector(0,hpedestal/2.,0),
                 height=1.1*hpedestal, length=wpedestal, width=wpedestal,
                 color=(0.4,0.4,0.5))
base = box(pos=top-vector(0,hpedestal+tbase/2.,0),
                 height=tbase, length=wbase, width=wbase,
                 color=pedestal.color)
axle = cylinder(pos=top-vector(0,0,offset-gap/2.+d/5), axis=(0,0,2*(offset-gap/2.+d/5)), radius=d/4., color=color.yellow)

class pendulum(object):
# theta1 initial upper angle (from vertical)
# theta1dot initial rate of change of theta1
# theta2 initial lower angle (from vertical)
# theta2dot initial rate of change of theta2
    def __init__(self, pos=top, theta1=1., theta1dot=0, theta2=0., theta2dot=0):
        self.pos = pos
        self.frame1 = frame(pos=self.pos)
        self.theta1 = theta1
        self.theta1dot = theta1dot
        self.theta2 = theta2
        self.theta2dot = theta2dot
        box(frame=self.frame1, pos=(L1display/2.-d/2.,0,-(gap+d)/2.), size=(L1display,d,d), color=color.red)
        box(frame=self.frame1, pos=(L1display/2.-d/2.,0,(gap+d)/2.), size=(L1display,d,d), color=color.red)
        cylinder(frame=self.frame1, pos=(L1,0,-(gap+d)/2.), axis=(0,0,gap+d),
                         radius=axle.radius, color=axle.color)
        self.frame1.axis = (0,-1,0)
        self.frame2 = frame(pos=pos+self.frame1.axis*L1)
        box(frame=self.frame2, pos=(L2display/2.-d/2.,0,0), size=(L2display,d,d), color=color.green)
        self.frame2.axis = (0,-1,0)
        self.update(dtheta1=self.theta1, dtheta2=self.theta2)
        
    def update(self, dtheta1=0, dtheta2=0):
        self.frame1.rotate(axis=(0,0,1), angle=dtheta1)
        self.frame2.pos = self.pos+self.frame1.axis*L1
        self.frame2.rotate(axis=(0,0,1), angle=dtheta2)

pend1 = pendulum(pos=top+vector(0,0,offset), theta1=1.3*pi/2.)
#pend1 = pendulum(pos=top+vector(0,0,offset), theta1=1.0*pi/6.)
pendula = [pend1]
if twopendula:
    theta1 = pend1.theta1
    if different:
        theta1 += 0.001
    pend2 = pendulum(pos=top+vector(0,0,-offset), theta1=theta1)
    pendula.append(pend2)
scene.autoscale = 0
scene.mouse.getclick()

dt = 0.001
t = 0.

while 1:
    rate(1./dt)
    for pend in pendula:
        # Calculate accelerations of the Lagrangian coordinates:
        atheta1 = ((E*C/B)*sin(pend.theta1)-F*sin(pend.theta2))/(D-E*A/B)
        atheta2 = -(A*atheta1+C*sin(pend.theta1))/B
        # Update velocities of the Lagrangian coordinates:
        pend.theta1dot += atheta1*dt
        pend.theta2dot += atheta2*dt
        # Update Lagrangian coordinates:
        dtheta1 = pend.theta1dot*dt
        dtheta2 = pend.theta2dot*dt
        pend.theta1 += dtheta1
        pend.theta2 += dtheta2
        pend.update(dtheta1=dtheta1, dtheta2=dtheta2)

    t = t+dt
