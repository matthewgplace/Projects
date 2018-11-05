"""
Author: Matthew Place
Date: November 16, 2017
Exercise 7.6
This program reads data from a file, plots the data, then takes the fft of this
data. Upon taking the fft, then it takes the inverse fft of a percentage of the
original fft and plots it on the same graph as the original data. Also compares
the irfft of a cosine fourier transform vs. the regular rfft function.
"""

from __future__ import division
from numpy import loadtxt, linspace
from numpy.fft import rfft, irfft
from pylab import show, figure
from dcstmp import dct


data = loadtxt("dow2.txt", float) #loads our text file
waveform = data[:] #This data is one dimensional, so puts it into an array.

x = linspace(0, len(waveform), len(waveform), endpoint=False) #This creates
            #our horizontal axis here, which is actually time, since the data
            #represents the daily closing value of the Dow Jones per day.

u = rfft(waveform) #takes our Fourier transform of dow2.txt
w = dct(waveform) #takes the cosine transform of dow2.txt

u[0.02*len(u):] = 0 #Now that we have the fft, we set the last 90% of it to 0
w[0.02*len(w):] = 0 #Do the same for our cosine waveform

u2 = irfft(u) #Takes the inverse fft of the fft.
u3 = irfft(w) #takes the inverse fft of the cft.


fig = figure() #Now we will make many plots on the same graph here.
ax1 = fig.add_subplot(111) #all subplots will be the same 111 here.

ax1.plot(x, waveform, "pink") #Plots our initial wave, I set it to pink
ax1.set_title("Dow Jones Industrial Average, 2004-208")
ax1.set_xlabel("Time (days)")
ax1.set_ylabel("Daily closing value")

ax2 = fig.add_subplot(111)
ax2.plot(abs(u2), "green") #Plots our Inverse Fourier transform.

#Notice how this irfft actually deviates from the original wave quite a bit at
#the ends, in an attempt to make the function periodic.

ax3 = fig.add_subplot(111)
ax3.plot(abs(u3), "black")
ax3.set_xlim(0, len(waveform))

#Here, I had to set an xlim because the cosine Fourier transform actually makes
#the function periodic by mirroring the function across the vertical axis located
#at the end of the dataset. To see this feature, comment out the set_xlim line.

#By setting these xlimits, however, and using a cosine transform, we get a much
#better inverse fourier transform at the ends of the original waveform than the
#other method.

show()