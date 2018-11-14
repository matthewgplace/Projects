# -*- coding: utf-8 -*-
"""
Created on Tue Nov 13 21:31:13 2018

@author: Matthew Place

This was created using Python 2.7
"""

from __future__ import division
from numpy import linspace, exp, pi, sin, fft
from pylab import plot, show, title, xlabel, ylabel

"""
First, we need to define the fft function.
This is a classic recursive fft function based on the Cooley and Tukey approach.

"""
def myfft(y):
    N = len(y)
    if N <= 1:
        return y
    elif N % 2 > 0:
        print "size of y must be a power of 2"
    else:
        evenfft = myfft(y[0::2])
        oddfft = myfft(y[1::2])
        r = xrange(N//2)
        factor = [exp(-2j*pi*k/N)*oddfft[k] for k in r]
        result = ([evenfft[k] + factor[k] for k in r] + [evenfft[k] - factor[k] for k in r])
        return result
        
"""
Next, let's generate a signal to test out my function and compare it with numpy's fft function
"""

freq = 0.05 #Hz
duration = 100 #s
poweroftwo = 2048 #samples

t = linspace(0, duration, poweroftwo) #Makes a list of time values

sinsignal = sin(2*pi*freq*t) #generates a sinusoidal signal

fft1 = fft.fft(sinsignal) #Numpy's fft function
fft2 = myfft(sinsignal) #myfft function

plot(t, sinsignal)
title("Sine Wave")
xlabel("Time (s)")
ylabel("Amplitude")
show()

print fft1[0:3]
print fft2[0:3]

"""
From looking at the printed values, myfft function appears to be behaving virtually
identical to numpy's fft function, so long as the size of y is a power of 2.
"""