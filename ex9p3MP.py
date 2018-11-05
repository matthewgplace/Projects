"""
Author: Matthew Place
Date: December 6, 2017
Exercise 9.3
This program makes a density plot of the electric potential of an
electronic capacitor inside a grounded metal box by solving Laplace's equation
and using a set of boundary conditions.
"""

from __future__ import division
from numpy import empty, zeros, max
from pylab import imshow, gray, show, title, xlabel, ylabel

M = 100 #Grid squares on a side
V = 1 #Voltage of one of the capacitor plates, the other is -V
target = 1e-6 #Target accuracy
L = 0.1 #Distance in meters of one side of the box, will be used only when plotting.

#First we must create an array which will hold all of our potential values.
phi = zeros([M+1, M+1], float) #Start by making it 0 everywhere
phi[20:80, 20] = V #These two lines give our fixed potentials at the capacitor plates
phi[20:80, 80] = -V
phiprime = empty([M+1, M+1], float) #Now we make an empty dummy array for 
    #calculating new potentials.

delta = 1 #delta is used here as our variable to check if we are within target accuracy
while delta > target:
    
    for i in range(M+1): #These for loops run through every grid square in our 100x100 array
        for j in range(M+1): 
            #First, we check if we are at the wall of the metal box or at one
            #of the capacitor plates, in which case these potential values are
            #already defined in the phi array.
            if i==0 or i==M or j==0 or j==M or phi[i,j]==V or phi[i,j]==-V:
                phiprime[i,j] = phi[i,j]
                
            #otherwise, calculate a new potential
            else:
                phiprime[i,j] = (phi[i+1,j] + phi[i-1,j] + phi[i,j+1] + phi[i,j-1])/4
     #now we update our accuracy to see if we need to continue       
    delta = max(abs(phi-phiprime))
    
    #Now we swap the arrays
    phi,phiprime = phiprime,phi
 
#all we have left to do is make our density plot
imshow(phi, origin="lower", extent=[0,L,0,L]) #we set the origin to be at the
    #lower left corner and make our sides go from 0 to 10 cm.

#now we set the color, title and label our axes, then show the plot.
gray()
title("Electric Potential of Electronic Capacitor in Grounded Metal Box")
xlabel("Distance (m)")
ylabel("Distance (m)")
show()
