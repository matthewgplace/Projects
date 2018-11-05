"""
Author: Matthew Place
Date: November 7, 2017
Exercise 6.13b
This program is designed to demonstrate a partial pivoting of rows of a matrix to
solve systems of equations.
"""
from __future__ import division
from numpy import exp

h = 6.626e-34 #m^2 kg s^-1
c = 299792458 #m/s
k = 1.3806e-23 #J K^-1

x1 = 5
x2 = -3
xp = 0
mp = 0

error = 1e-6
accuracy = 1

def func(x):
    return 5*exp(-x)+x-5
    
def funcprime(x):
    return -5*exp(-x)+1
    
  
if func(x1)/func(x2) == abs(func(x1/func(x2))):
    print "Try different starting guesses for x1 and x2"
else:
    while accuracy > error:
        mp = 0.5*(x1+x2)
        xp = funcprime(mp)
        if xp == 0:
            break
        else:
            if xp/func(x1) == abs(xp/func(x1)):
                x1 = mp
            else:
                x2 = mp
        
        accuracy = abs(x1 - x2)
        
    mp = 0.5*(x1+x2)
    
    b = (h*c)/(k*mp)
    print "Wien displacement constant estimate:", b
  