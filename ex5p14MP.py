"""
Author: Matthew Place
Date: October 25, 2017
Exercise 5.14
This program is designs to use Guassian quadrature to evaluate the gravitational
pull of a sheet on a 1kg mass above it, but only along the vertical axis.
"""

from __future__ import division
from pylab import plot, show, title, xlabel, ylabel #These are for graphing
from gaussxwMP import gaussxw #For Gaussian Quadrature

#Define constants
G = 6.674e-11 #m^3 kg^-1 s^-2
N = 100 #slices
MperA = 100 #kg/m^2 This is sigma from the formula
L = 10 #meters, length of the sides of square sheet
zlist=[] #this is a list to append horizontal axis values
Fzlist=[] #this is a list to append vertical axis values
z = 0 #starting value for z
zmax = 10 #ending value for z
zstep = 0.1 #step size for plot points

def func(x, y, z): #This is our mathematical function to calculate
                            #The force of gravity
    C1 = G*MperA*z
    C2 = 1/((x**2+y**2+z**2)**(3/2))
    return C1*C2
    
def Fz(z, L): #This is our function to take the integral using Gaussian quadrature.
    a = -L/2 #limits of integration, dependent on L
    b = L/2 
    x, wi = gaussxw(N) #use our called function from the library.
    y, wj = gaussxw(N)
    #Next, we calculate our sample points and weights, and map them to the 
    #required integration domain.
    xp = 0.5*(b-a)*x+0.5*(b+a) #this will be for our dx values
    yp = 0.5*(b-a)*x+0.5*(b+a) #this will be for our dy values                              
    wpi = 0.5*(b-a)*wi #subsequently, we need two values for weighting too.
    wpj = 0.5*(b-a)*wj #i and j this time instead of x and y.
    s = 0
    
    #Now, we perform the actual integration on our function from before.
    for k in range(N):
        for p in range(N):
            s += wpi[k]*wpj[p]*func(xp[k], yp[p], z) #This performs a double
            #integral by running two loops and calculating both nested sums.
            #every possible combination of xp[k] and yp[p], our x and y values.
        #note that this calls our function from before, and plugs in our z value.
            #so calling this function Fz will also call our func function.
    return s


while z <= zmax: #Using a while loop to make stepsize small.
    zlist.append(z)
    Fzlist.append(Fz(z, L)) #append to our plot lists and iterate the while loop.
    z += zstep
    
#label and plot our lists, then show them.
plot(zlist, Fzlist)
title("Gravitational Pull of a Uniform Sheet")
ylabel("Force of gravity in z-direction (N)")
xlabel("Distance along z-axis (m)")
show()