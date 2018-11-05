"""
Author: Matthew Place
Date: November 7, 2017
Exercise 7.1
This program is designed to calculate the coefficients in the discrete
Fourier transforms of a few functions and make a plot of these values
"""


from __future__ import division
from numpy import zeros
from cmath import exp, pi, sin
from pylab import plot, show, xlim, title

n = 1000 #number of points sampled
square = [] #these three lists are for holding our different shaped functions
saw = []    #where the functions are going to be just collections of points
modsine = []

def dft(y): #the discrete fourier transform function from the book page 296
    N = len(y)
    c = zeros(N//2+1,complex)
    for k in range(N//2+1):
        for n in range(N):
            c[k] += y[n]*exp(-2j*pi*k*n/N)
    return c
    
    
#Now, we must create our three different waveforms which will be used for
    #calculating the dft of.
for i in range(0, n-1):
    #The next if statement creates a square wave with amplitude 1
    if i < 500:
        square.append(1)
    else:
        square.append(-1)
        
    saw.append(i) #The book says it wants a sawtooth wave with y[n]=n, so this
                    #saw list will do just that, creating a diagonal line of points.
    
    modsine.append(sin((pi*i)/n)*sin((20*pi*i)/n))    #this creates our
                    #modulated sine wave.
    
#Now, we next perform our discrete fourier transform using whichever waveform
#we want. In this case, I have chosen the square one since it is the most
#interesting of the three.    
u = dft(square)

plot(abs(u)) #we plot the absolute value of the dft since many of the coefficients
#are complex.

xlim(0, 20) #Here, we set our xlim to just go to 20 so we can see what the dft
#actually looks like up close, in this case.

title("Discrete Fourier Transform of a Square Wave")

show()    