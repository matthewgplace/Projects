"""
Author: Matthew Place
Date: November 14, 2017
Homework Assignment
This program is designed to create a sine wave at a certain period and then
take its Fast Fourier transform to get the frequency. Both the sine wave and the
transform are then plotted.
"""

from __future__ import division
from numpy import pi, sin, linspace
from numpy.fft import rfft, fftfreq
from pylab import show, figure

period = 5 #seconds
freq = 1/period #Convert our period into a frequency, 1/seconds
fs = 100 #This is our sampling rate, number of measurements per second, used to
        #calculate sine wave and also used in converting the FFT into frequency.
tmax = 20 #This is our maximum time value we want on our horizontal axes.

t = linspace(0, tmax, tmax*fs, endpoint=False) #This creates our time values for
                #our sine wave calculation. Starts at 0, goes to tmax, with
                #tmax*fs total steps in between.
sinewave = sin(2*pi*freq*t) #Generates our sine wave
   
u = rfft(sinewave) #takes our Fourier transform of the sine wave.
freqspace = fftfreq(len(u))*fs #Uses the built in Numpy function to convert to 
                                #frequency space.


fig = figure() #Now we make two plots, one on above the other.
ax1 = fig.add_subplot(211)
ax1.plot(t, sinewave) #Plots our sine wave
ax1.set_title("Sine Wave")
ax1.set_xlabel("Time (s)")
ax1.set_ylabel("Amplitude")

ax2 = fig.add_subplot(212)
ax2.plot(freqspace, abs(u)) #Plots our Fourier Transform
ax2.set_xlim(0, tmax)
ax2.set_title("Fourier Transform")
ax2.set_xlabel("Frequency (Hz)")
ax2.set_ylabel("Magnitude")

show()