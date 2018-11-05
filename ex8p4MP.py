"""
Author: Matthew Place
Date: November 20, 2017
Exercise 8.4
This program solves two first order equations for the motion of a nonlinear 
pendulum by using the fourth order Range-Kutta method. A plot of the pendulum's
angle over time is then generated.
"""

from __future__ import division
from math import sin, pi
from numpy import array, arange
from pylab import plot, xlabel, ylabel, title, show


g = 9.81 #m/s - gravity
l = 0.1 #m - length of pendulum arm

a = 0 #initial time value that will be checked
b = 10 #final time value
N = 1000 #sample points
h = (b-a)/N #used for Range-Kutta method

initialtheta = 179*pi/180 #179 degrees converted to radians. Initial angle for pendulum
initialomega = 0 #the pendulum starts with no angularvelocity

tpoints = arange(a, b, h) #makes a set of time values from a to b with h stepsize
thetapoints = [] #we are only concerned with theta over time, not omega. so we
#will only make one list for theta and none for omega here

#Next is our functions for the pendulum
def f(r, t):
    theta = r[0] #sets initial angle, r needs to be an array when calling this function
    omega = r[1] #sets initial angular velocity
    ftheta = omega #first of the two first-order equations
    fomega = -(g/l)*sin(theta) #second first-order equation
    return array([ftheta, fomega], float) #returns updated values in an array
    
r = array([initialtheta, initialomega], float) #creates our r array with initial points
            #this will be used as we iterate our function above.

for t in tpoints:
    thetapoints.append(r[0]*180/pi) #appends theta as degrees instead of radians
    
    #The next steps are the Range-Kutta method from the book page 345.
    k1 = h*f(r, t)
    k2 = h*f(r+0.5*k1, t+0.5*h)
    k3 = h*f(r+0.5*k2, t+0.5*h)
    k4 = h*f(r+k3, t+h)
    r += (k1+2*k2+2*k3+k4)/6


plot(tpoints, thetapoints)
title("Angle of Nonlinear Pendulum over Time")
ylabel("Angle (degrees)")
xlabel("Time (s)")
show()