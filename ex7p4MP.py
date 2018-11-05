"""
Author: Matthew Place
Date: November 16, 2017
Exercise 7.4
This program reads data from a file, plots the data, then takes the fft of this
data. Upon taking the fft, then it takes the inverse fft of a percentage of the
original fft and plots it on the same graph as the original data.
"""

from __future__ import division
from numpy import loadtxt, linspace
from numpy.fft import rfft, irfft
from pylab import show, figure


data = loadtxt("dow.txt", float) #loads our text file
waveform = data[:] #This data is one dimensional, so puts it into an array.

x = linspace(0, len(waveform), len(waveform), endpoint=False) #This creates
            #our horizontal axis here, which is actually time, since the data
            #represents the daily closing value of the Dow Jones per day.

u = rfft(waveform) #takes our Fourier transform of dow.txt
u[0.1*len(u):] = 0 #Now that we have the fft, we set the last 90% of it to 0

u2 = irfft(u) #Takes the inverse fft of the fft.

u[0.02*len(u):] = 0 #Now we set all but the first 2% of the fft to 0

u3 = irfft(u) #Again, take the inverse fft of the fft.

fig = figure() #Now we make three plots, all on the same graph
ax1 = fig.add_subplot(111) #set all to subplot(111) to be on same graph

ax1.plot(x, waveform, "pink") #Plots our initial wave, I set it to pink
ax1.set_title("Dow Jones Industrial Average, 2006-2010")
ax1.set_xlabel("Time (days)")
ax1.set_ylabel("Daily closing value")

ax2 = fig.add_subplot(111)
ax2.plot(abs(u2), "black") #Plots our Inverse Fourier transform.

#This inverse fft actually looks like the original data, only the "noise" has
#been reduced. You can more easily see the trends over a slightly longer time
#scale here. So this could be useful if you wanted to see how the Dow Jones
#was looking over a few months or years period. You won't care as much about
#The day to day changes, so this sort of eliminates them. Very interesting how
#That works.

ax3 = fig.add_subplot(111)
ax3.plot(abs(u3), "green") #Plots our Fourier Transform

#This last irfft actually appears to be even more broad than the second plot.
#Here, you can just see very broadly what the Dow Jones was doing over the course
#of four years, but you have very little information about each month in those
#years. 

#It appears to average the data less and less precisely as you decrease how much
#percentage of the rfft the irfft actually takes. It smooths the curve.

show()