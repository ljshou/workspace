# 
# See the exercise "Pendulum.pdf" from Pendulum.html 
# in  http://www.physics.cornell.edu/~myers/teaching/ComputationalMethods/ComputerExercises/
#
"""Simple example animating the motion of a pendulum."""

# The "visual" module can create 3D objects (such as spheres, curves, etc.)
# and animate their motions in space.
# See www.vpython.org
import visual
# kludge required to get visual window up and running before import scipy
scene2 = visual.display()
c = visual.cone(radius=1.0e-10)
c.visible = 0

# scipy allows us to use "array", "sin", "cos" etc.
# scipy is also imported in "visual"
from scipy import *	

# Physical properties and initial conditions for pendulum

g = 9.8
L = 1.0				# physical length of bar
d = 0.02 			# thickness of bar: needed for graphics
theta = 1.*pi/6. 		# initial upper angle (from vertical)
thetaDot = 0. 			# start pendulum at rest

# Set up graphics display

visual.scene.title = 'Pendulum'
visual.scene.height = visual.scene.width = 800
pivot = array([0,0,0]) 		# pivot position of pendulum
visual.scene.center = pivot	# graphics center

# Build a cylinder representing current position of pendulum
# Cylinder extends from bar.pos to bar.pos + bar.axis.
#
# "visual" will automagically move the image of the pendulum whenever
# one of its properties changes: we'll be moving bar.axis

bar = visual.cylinder(pos=pivot, axis = (L*sin(theta),
                      -L*cos(theta),0), 
                      radius = d, color=visual.color.red)

# The scale of the graph is set automatically by the system by default. 
# We allow it to do so for the first frame (created above when we
# constructed "bar"), but don't want it to keep rescaling as the pendulum moves

visual.scene.autoscale = False

# visual.rate(rateWait) will pause to ensure not too many frames are drawn
# so that the graphics can keep up

framesPerSecond = 50

# Time steps for our pendulum

# Simple time stepping algorithm

dt = 0.01
t = 0.

while 1:
    # Calculate accelleration due to gravity
    thetaDotDot = -(g/L) * sin(theta)
    # Change velocity according to accelleration
    thetaDot += thetaDotDot * dt
    # Change position according to (updated) velocity
    theta += thetaDot * dt
    # Change position according to (updated) velocity
    bar.axis = (L*sin(theta), -L*cos(theta), 0)
    t = t+dt

    # Slow down graphics
    visual.rate(framesPerSecond)


# Copyright (C) Cornell University
# All rights reserved.
# Apache License, Version 2.0


