"""
driven_bouncing_balls.py

    Three balls bouncing on an oscillating plate.

    Copyright (c) 2012 University of Toronto
    Last Modification:  26 May 2012 by David Bailey
    Original Version:   26 May 2012 by David Bailey 
    Contact: David Bailey <dbailey@physics.utoronto.ca>
                            (http://www.physics.utoronto.ca/~dbailey)
    License: Released under the MIT License; the full terms are this license
                are appended to the end of this file, and are also available
                at http://www.opensource.org/licenses/mit-license.php

    References (Just of a few of many):
        Alvarez75: "Mechanical analog of the synchrotron, illustrating phase
            stability and two-dimensional focusing", Luis W. Alvarez,
            Robert Smits, Gerard Senecal, American Journal of Physics 43 (1975)
            293-296. (http://dx.doi.org/10.1119/1.9855)
        Tufillaro86: "Chaotic dynamics of a bouncing ball", N. B. Tufillaro and
            A.M. Albano, American Journal of Physics 54 (1986)
            939-944. (http://dx.doi.org./10.1119/1.14796)
        Luo96: "The Dynamics of a Bouncing Ball with a Sinusoidally Vibrating
            Table Revisited", Albert C. J. Luo andRay P.S. Han, Nonlinear
            Dynamics 10 (1996) 1-18. (http://dx.doi.org/10.1007/BF00114795)
        Barroso09: "Bouncing ball problem: Stability of the periodic modes",
            Joaquim J. Barroso, Marcus V. Carneiro and Elbert E. N. Macau,
            Physical Review E 79 (2009) 026206.
            (http://dx.doi.org/10.1103/PhysRevE.79.026206)

    The plate is horizontal, moving sinusoidally vertically (in y direction).
        Its motion is assumed to be unaffected by its collisions with the balls.

    All quantities are in SI units, i.e. metre, second, ...

    Five primary physical parameters can be set by the user in the code :
        e   : Coefficient of Restitution ("elasticity" in Alvarez75),
                        i.e. ratio of speeds before and after bounce
        f   : frequency of plate oscillations
        A   : amplitude of plate oscillations
        h_0 : release height for dropping middle ball at time t=0
        phi : phase of plate at time t=0

    Other importnat user parameters that can be set:
        delta_h             : fractional difference in drop height
                                between the three balls
        cycles_to_simulate  : stop after this many plate oscillations
        save_bounces        : set true to save bounce times for further analysis
    
    Some phase stable values (for plate y=A*sin(omega*t+phi) are
        e   ,   f,   A    ,  h_0,  phi
        0.95,   1,   0.05 ,  y_b,  pi+arccos(K)  (Alvarez75)
        0.6 ,   3,   0.03 ,  y_b,  pi+arccos(K)
        0.3 ,   8,   0.007,  y_b,  pi+arccos(K)     
        0.3 ,  16,  0.0035,  0.02, 0.4           (2nd harmonic)
        0.3 ,  24,  0.0023,  0.02, 3.5           (3rd harmonic)
        0.2 ,  12,   0.004,  y_b,  pi+arccos(K)
            
        y_b is a critical drop height and K is a stability parameter that can be
            calculated from e, f, A (see Alvarez75 or code below)

    Phase stability usually occurs for h_0 = y_b as long as K is a bit less than
        one, or equivalently, as long as the amplitude, A, is not much greater
        than a critical value of (pi*g/omega**2)*(1-e)/(1+e).

    For true phase stability
        (1) The kinetic energy gained by the ball when colliding with the plate
            must equal the energy loss due to inelasticity.
        (2) The period of bouncing matches the period of the plate (or some
            even multiple.
        (3) The bounces must occur when the plate is rising but slowing down.
            If the ball has bit too little speed, its bounce period will be
            a bit less than the period of the plate. It will arrive a
            bit early for the next bounce, which means it will be hit a bit
            harder which will lengthen its period a bit moving it closer to the
            period of the plate. Conversely, if the ball has a bit too much
            speed, it will arrive a bit late and be receive less energy from
            the plate slowing it down and its bounce period will shorten a bit
            becoming closer to the plate period.

    Another form of stability can occur when a ball is relatively inelastic
        and it hits the plate with very little relative velocity when the
        plate is moving down. The ball can then sit on the plate and if the
        amplitude and frequency are suitable it can be thrown up and then
        caught again one or more cycles laterin exactly the same way. e.g.:
        e   ,   f,   A    ,   h_0,  phi
        0.3 ,  16, 0.0045 ,   y_b,  pi+0.5*arccos(K)
        0.2 ,  12, 0.008  , 2*y_b,  pi+arccos(K)
        0.2 ,  18, 0.006  ,   y_b,  pi+arccos(K)   delta_h = 0.005
        0.2 ,18.8, 0.008  ,  0.08,  0.7            delta_h = 0.02

    Some other interesting values
        e   ,   f,   A   ,      h_0,  phi
        0.3 ,  19, 0.006 ,  2.7*y_b,  pi+arccos(K) Becomes bimodal
        0.4 ,  19, 0.006 ,      y_b,  pi+arccos(K) Becomes trimodal
        0.6 ,  19, 0.006 ,      y_b,  pi+arccos(K) Somewhat chaotic
        0.8 ,  19, 0.006 ,      y_b,  pi+arccos(K) More chaotic

    The program would run about 10 times faster if the visualization were
        eliminated and only the bounce time outputs saved to a file. Writing
        it in C++ would speed it up by another order of magnitude or two.
        
 """

# Import desired vPython, numpy, graphing objects, and constants
from visual import box, color, rate, scene,  sphere,  vector
from numpy import arccos, cos, mod, pi,  sin, sqrt
from visual.graph import gcurve, gdisplay, gdots
g = vector(0,-9.8,0)    # vertical acceleration due to gravity

#************** Most parameters are set in this section ************************
#**** Primary Physics parameters
e         = 0.3      #**** Elasticity of plate ball collisions
frequency = 8        #**** Plate frequency and amplitude
A         = 0.007    #**** Plate frequency and amplitude

period = 1.0/ frequency # Period of plate oscillations (T in Alvarez75)
omega = 2*pi*frequency  # Angular frequency of plate

# Parameters from Alvarez75
K = ((1-e)/(1+e))*(g.mag/(A*omega**2))*pi     # Stability parameter
y_b = 0.5*g.mag*(period/2.)**2+A*sqrt(1-K**2) # Phase stable drop height
# To get Nth harmonic, replace K by N*K and period by N*period in y_b
# i.e. for 2nd harmonic N=2, use
#   K = 2 * ((1-e)/(1+e))*(g.mag/(A*omega**2))*pi
#   y_b = 0.5*g.mag*(2*period/2.)**2+A*sqrt(1-K**2)

h_0       = y_b            #**** Drop height of middle ball at time t=0
phi       = pi+arccos(K)   #**** Initial plate phase at time t=0

#**** Other user parameters
#   Fractional variation of side balls drop height
delta_h            = 0.05   # Drop height difference between the 3 balls.      
cycles_to_simulate = 20     # Stop after this many plate oscillations.
save_bounces       = False  # Save bounce times to file for further analysis.

#**** Visualization and simulation parameters
plate_size = 0.05           # Side length of plate                    
ball_size  = plate_size/6   # Diameter of balls
dt         = 0.01/omega     # Simulation time step
#*******************************************************************************

# A little function that writes output to both the terminal and a log file
def note(*text):
    output_string = ""
    for item in text: output_string += str(item)+" "
    print(output_string)
    try:
        logfile.write(output_string+"\n")
    except:
        pass
    
# Output file names are created from current date and time
if save_bounces:
    import datetime
    date_time = datetime.datetime.now().strftime("%Y_%m_%d_%H_%M_%S")
    logfile  = open('ball_bounces_'+ date_time +'.txt',"w")

note("Input and Calculated Parameters")
note("  elasticity (e)      = ", e )
note("  frequency           = ", frequency, "(Hz)" )
note("  omega               = ", omega, "(Hz)" )
note("  K                   = ", K )
note("  Drop height (h_0)   = ", h_0, "(m)" )
note("  delta_h             = ", 100*delta_h, "(%)" )
note("  Drop phase (phi)    = ", phi )
note("  Plate amplitude (A) = ", A, "(m)" )
note("  Critical amplitude  = ", K*A, "(m)" )
note("  Number of cycles    = ", cycles_to_simulate )
if save_bounces:
    note("\n**** Bounce times recorded in ",logfile.name)

# Balls are dropped from slightly different heights
height = [ (1-delta_h)*h_0, h_0, (1+delta_h)*h_0 ]

# Set vPython scene
scene.range = (2*max(height[2],plate_size, 2*(A*omega)**2/g.mag) ) # scene x,y,z scales
scene.uniform = True                         # ensure all axes have same scale
scene.title = 'Bouncing Balls'               # scene title
scene.height = 600                           # scene height in pixels
scene.width  = 200                           # scene width in pixels

# Define plate
plate = box( pos=(0, A*sin(phi), 0), length=plate_size,
             height=0.005, width=plate_size, color=color.blue )
plate.velocity = vector(0, A*omega*cos(phi), 0)

# Define balls
balls = [ sphere(pos=(-plate_size/4, 0, 0), color=color.yellow),
          sphere(pos=( 0           , 0, 0), color=color.red   ),
          sphere(pos=( plate_size/4, 0, 0), color=color.green ) ]
for i in range(len(height)) :
    balls[i].pos.y  = height[i]+plate.height
    balls[i].radius = ball_size/2.0
    balls[i].id = str(i) # Tag ball
for b in balls: b.velocity = vector(0,0,0)

# Define y position plots
position_plots = gdisplay(width=800, height=240,
                  title='Vertical position of balls and plate vs time',
                  xtitle='time', ytitle='y', y=400,
                  foreground=color.black, background=(0.5,0.5,0.5))
plateplot    = gcurve(gdisplay=position_plots, color=color.blue)
for b in balls: b.y_plot = gcurve(gdisplay=position_plots, color=b.color)

# Define bounce time plots
step_plots = gdisplay(width=600, height=400, x=200,
                  title='Current vs previous bounce intervals',
                  xtitle='previous bounce',
                  ytitle='current bounce (in units of plate oscillation period)',
                  foreground=color.black, background=(0.5,0.5,0.5))
for b in balls: b.step_plot = gdots(gdisplay=step_plots, color=b.color)

def bounce(ball,a,L):
    bounced = False
    # Calculate new ball velocity and position using symplectic Euler method.
    ball.velocity = ball.velocity + a*dt
    ball.pos = ball.pos + ball.velocity*dt
    # (Verlet algorithm is an possible alternative, i.e.
    #       ball.pos = ball.pos + ball.velocity*dt + 0.5*a*dt**2
    #       ball.velocity = ball.velocity + a*dt)
    # Ball can only bounce if it is over plate.
    if (-(L/2+ball.radius) < ball.x < L/2+ball.radius) :
        # Bounce if ball is on plate, otherwise let it fall.
        if ( ball.pos.y < ball.radius+plate.height/2+plate.pos.y ) :
            # Calculate ball velocity in plate reference frame
            ball.velocity.y = ball.velocity.y - plate.velocity.y
            # Move ball to surface of plate
            ball.pos.y = ball.radius + plate.height/2 + plate.pos.y
            # Flip velocity sign (i.e. bounce) if ball is falling.
            if ball.velocity.y < 0 :
                ball.velocity.y = -ball.velocity.y
                # Apply energy loss
                ball.velocity.y = e*ball.velocity.y
                bounced = True
            # Revert to velocity in external reference frame
            ball.velocity.y = ball.velocity.y + plate.velocity.y
    return bounced

# Initialize bounce time parameters
for b in balls:
    b.t_previous = -1
    b.delta_t_previous = -1
    b.bounce_times = [] # Create list to store bounce times

from time import time
start_time = time()

# Main visualization loop
t  = 0              # Initialize simulation time
for i in range(int(cycles_to_simulate/(frequency*dt))) :
    t = t+dt
    
    plate.y          = A *       sin(omega*t+phi)
    plate.velocity.y = A*omega * cos(omega*t+phi)
    # Calculate new ball positions
    for b in balls :
        bounced = bounce(b,g,plate_size,)
        if bounced :
            # Store time of bounce
            if b.t_previous > 0 :
                delta_t = t - b.t_previous            
                b.bounce_times.append(delta_t)
                if save_bounces: logfile.write(b.id+" "+str(delta_t)+"\n")
                if b.delta_t_previous > 0 :
                    b.step_plot.plot(pos=(frequency*b.delta_t_previous,
                                          frequency*delta_t))
                b.delta_t_previous = delta_t
            b.t_previous = t                             

    plateplot.plot(pos=(t*frequency,balls[0].radius + plate.height/2 + plate.y))
    for b in balls : b.y_plot.plot(pos=(t*frequency,b.y))

print "\nMain loop took ", time()-start_time, " seconds"
if save_bounces: logfile.close()

# End of driven_bouncing_balls.py

"""

Full text of MIT License:

    Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
"""