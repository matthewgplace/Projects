"""
Author: Matthew Place
Date: November 7, 2017
Exercise 6.18
This program is designed to plot the efficiency of a lightbulb at various 
temperatures and then find the temperature of maximum efficiency within
1 K by using the golden ratio search method.

Part c of this assignment is at the bottom of this code.
"""

from __future__ import division
from numpy import exp, pi, sqrt
from gaussxwMP import gaussxw #For Gaussian Quadrature
from pylab import plot, show, title, xlabel, ylabel


#lots of constants incoming
h = 6.626e-34 #m^2 kg s^-1
c = 299792458 #m/s
k = 1.3806e-23 #J K^-1
N = 100 #slices
wave1 = 390e-9 #lower limit of visible wavelengths
wave2 = 750e-9 #upper limit of visible wavelengths
intconst1 = (h*c)/(wave1*k) #used for limit of integration
intconst2 = (h*c)/(wave2*k) #used for limit of integration

Tempi = 300 #K, starting test temperature
Tempf = 10000 #K final temperature

xlist = [] #used for plotting graph
ylist = [] #used for plotting graph

accuracy = 1 #K, we want an accuracy of 1 K temperature for maximum efficiency

z = (1+sqrt(5))/2 #golden ratio
#Initial positions of the four points used for the golden ratio method for
#finding the maximum of the efficiency function.
T1 = Tempi #We will use our initial and final temperatures above as the outer
T4 = Tempf #boundaries for these points
T2 = T4 - (T4-T1)/z #inner points defined by golden ratio rule
T3 = T1 + (T4-T1)/z


def func(x): #The integral of this function is for the efficiency of a lightbulb
    
    C1 = 15/pi**4
    C2 = (x**3)/(exp(x)-1)
    
    return C1*C2
    
def Gauss(T): #This is our function to take the integral using Gaussian quadrature.
    a = intconst2/T #limits of integration, dependent on T
    b = intconst1/T
    
    x, w = gaussxw(N) #use our called function from the library.
    #Next, we calculate our sample points and weights, and map them to the 
    #required integration domain.
    xp = 0.5*(b-a)*x+0.5*(b+a) #this will be for our dx values
                            
    wp = 0.5*(b-a)*w #used for weighting
    
    s = 0
    
    #Now, we perform the actual integration on our function from before.
    for k in range(N):
        s += wp[k]*func(xp[k]) #This performs our integral, whose limits depend
                                #on T
    return s




for i in range(Tempi, Tempf): #Here we simply run through our temperature range and
                            #put the points in our lists for the final plot.
    xlist.append(i)
    ylist.append(Gauss(i))
  
    
#Now, we will focus on finding what the efficiency at maximum is by using
#the golden ratio method

#Initial values of the function at the four points, they are negative because
#we want the maximum and not the minimum.
f1 = -Gauss(T1)
f2 = -Gauss(T2)
f3 = -Gauss(T3)
f4 = -Gauss(T4)

#Next, the main loop of the golden ratio search process
while T4-T1 > accuracy:
    if f2 < f3:
        T4, f4 = T3, f3
        T3, f3 = T2, f2
        T2 = T4 - (T4-T1)/z
        f2 = -Gauss(T2)
    else:
        T1, f1 = T2, f2
        T2, f2 = T3, f3
        T3 = T1 + (T4 - T1)/z
        f3 = -Gauss(T3)
    

#Next, label and plot our graph
plot(xlist, ylist)
title("Efficiency of a lightbulb as a function of temperature")
ylabel("Efficiency")
xlabel("Temperature (K)")
show()

#Now print the maximum efficiency temperature
print "The temperature of maximum efficiency is", 0.5*(T1+T4), "Kelvin"


"""
Incandescent light bulbs are not very efficient it seems. Even at the theoretical
maximum efficiency temperature, the efficiency does not reach 50%.

Also, since this temperature is over 6000 Kelvin it would NOT be advisable to
run the lightbulb at this temperature. The tungsten filament will melt at that
temperature.
"""