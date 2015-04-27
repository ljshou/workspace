"""Animates Walker"""
#
# See the exercise "Walker.pdf" from Walker.html
# in  http://www.physics.cornell.edu/~myers/teaching/ComputationalMethods/ComputerExercises/
#
import visual as V

V.scene.title = 'Walker'
V.scene.height = V.scene.width = 600
# Follow walker as it moves forward
V.scene.autocenter = 1
# Scale set automatically by system, but don't keep rescaling as walker moves
V.scene.autoscale = 1
# Slow down walker to reasonable speed
framesPerSecond = 120

# kludge required to get visual window up and running before import scipy/numpy
c = V.cone(radius=1.0e-10)
c.visible = 0

import Walker as W
reload(W)	# for ipython to reload properly after changes in Walker
import scipy

# Walker Display

class WalkerDisplay:
    """Defines VPython cylinders for stanceLeg, swingLeg."""
    def __init__(self, w):
        """Store walker being displayed.
	Set up stanceLeg and swingLeg to be cylinders.
	stanceLeg extends from stance foot position to body position.
	swingLeg extends from body position to swing foot position."""
    	self.w = w # the walker being displayed
	d = 0.06   # thickness of legs
	self.stanceLeg = V.cone(pos=w.GetBodyPos(), radius = d, 
                                color = V.color.red,
                                axis = -w.GetBodyPos()+w.GetStanceFootPos())
	self.swingLeg = V.cone(pos=w.GetBodyPos(), radius = d, 
                               color = V.color.orange,
                               axis = w.GetSwingFootPos()-w.GetBodyPos())

    def update(self):
        """Updates pos and axis for stanceLeg and swingLeg."""
	self.stanceLeg.pos = self.w.GetBodyPos()
	self.stanceLeg.axis = (-self.w.GetBodyPos()+self.w.GetStanceFootPos())
	self.swingLeg.pos = self.w.GetBodyPos()
	self.swingLeg.axis = self.w.GetSwingFootPos()-self.w.GetBodyPos()

class CenteredWalkerDisplay:
    """Defines display centered on midpoint between stance and swing feet."""
    def __init__(self, w):
        """Store walker being displayed.
	Set up stanceLeg and swingLeg to be cylinders.
	stanceLeg extends from stance foot position to body position.
	swingLeg extends from body position to swing foot position."""
    	self.w = w # the walker being displayed
	d = 0.06   # thickness of legs
        center = (w.GetStanceFootPos() + w.GetSwingFootPos())/2.0
	self.stanceLeg = V.cone(pos=w.GetBodyPos()-center, radius = d, 
                                color = V.color.red,
                                axis = -w.GetBodyPos()+w.GetStanceFootPos())
	self.swingLeg = V.cone(pos=w.GetBodyPos()-center, radius = d, 
                               color = V.color.orange,
                               axis = w.GetSwingFootPos()-w.GetBodyPos())
    def update(self):
        """Updates pos and axis for stanceLeg and swingLeg."""
        center = (self.w.GetStanceFootPos() + self.w.GetSwingFootPos())/2.0
	self.stanceLeg.pos = self.w.GetBodyPos()-center
	self.stanceLeg.axis = (-self.w.GetBodyPos()+self.w.GetStanceFootPos())
	self.swingLeg.pos = self.w.GetBodyPos()-center
	self.swingLeg.axis = self.w.GetSwingFootPos()-self.w.GetBodyPos() 


def SillyWalk(w, dt=0.02):
    """Integrates walker differential equations, but ignores heel strikes.
    (1) Set scene.autocenter=0 to avoid following walker center of mass.
    (2) Pick times for some reasonable range (say to 100), 
        find trajectory from odeint.
    (3) Run through trajectory, setting state of system and 
        then updating display. Run rate(framesPerSecond) inside loop
	to slow things down.
    (4) Set scene.autocenter back to 1."""
    V.scene.autoscale = 1
    V.scene.autocenter = 1
    dw = WalkerDisplay(w)
    V.scene.autoscale = 0
    V.scene.autocenter = 0
    time = scipy.arange(0.0,100.0,dt)
    y0 = w.GetStateVector()[:]
    y_trajectory = scipy.integrate.odeint(w.dydt, y0, time, atol=1.0e-10)
    for n in range(len(time)):
        V.rate(framesPerSecond)
        w.SetStateVector(y_trajectory[n])
        dw.update()
    V.scene.autocenter = 1
    dw.stanceLeg.visible = 0
    dw.swingLeg.visible = 0


def SimpleWalk(w, dwc=None, gamma=0.009, t_initial=0., t_final=40.2, dt=0.02):
    """Set gamma for walker w. Walk forward in steps of dt, 
    and update display."""
    w.gamma = gamma
    if dwc is None:
        dwc = CenteredWalkerDisplay(w)
    for t in scipy.arange(t_initial, t_final, dt):
        V.rate(framesPerSecond)	# Pause to show all frames
        w.Walk(t, t+dt, dt*29./30.)
        dwc.update()
    dwc.stanceLeg.visible = 0
    dwc.swingLeg.visible = 0


def MultiWalkFromFile(w, filename="AttractorPointsPruned.dat"):
    """Reads gammas, initial conditions from file to start on attractor"""
    V.scene.autoscale = 1
    V.scene.autocenter = 1
    dwc = CenteredWalkerDisplay(w)
    V.scene.autoscale = 0
    V.scene.autocenter = 0
    for line in file(filename):
        w.gamma, w.theta, w.thetaDot, w.phi, w.phiDot = \
                 map(float, line.split())
        # File states saved just after heel strike
	w.RoundCollisionConditionPositive()
        SimpleWalk(dwc, w.gamma, dt=0.02, t_final=20.)
    dwc.stanceLeg.visible = 0
    dwc.swingLeg.visible = 0

def yesno():
    response = raw_input('    Continue? (y/n) ')
    if len(response)==0:        # [CR] returns true
        return True
    elif response[0] == 'n' or response[0] == 'N':
        return False
    else:                       # Default
        return True
    
def demo():
    print "Walker Animation Demo"
    if not yesno(): return
    print "Silly Walk"
    w = W.Walker()
    SillyWalk(w)
    if not yesno(): return
    w = W.Walker()
    print "Simple Walk, gamma=0.009"
    SimpleWalk(w, gamma=0.009)
    if not yesno(): return
    print "Simple Walk, gamma=0.012"
    SimpleWalk(w, gamma=0.012)
    if not yesno(): return
    print "Simple Walk, gamma=0.015"
    SimpleWalk(w, gamma=0.015)
    if not yesno(): return
    print "Simple Walk, gamma=0.017"
    SimpleWalk(w, gamma=0.017)
    if not yesno(): return
    print "Simple Walk, gamma=0.020"
    SimpleWalk(w, gamma=0.020)
    
if __name__ == '__main__':
    demo()

# Copyright (C) Cornell University
# All rights reserved.
# Apache License, Version 2.0


