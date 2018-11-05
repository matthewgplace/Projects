"""
Author: Matthew Place
Date: December 12, 2017
Exercise 10.2
This program plots the radioactive decay of a Bi 213 isotope, which has a
decay chain where it can decay into other types of atoms before reaching
Bi 209 in the end. This program uses a random number generator to simulate this.
"""

from __future__ import division
from random import random
from numpy import arange
from pylab import plot, show, title, xlabel, ylabel

Bitau = 46*60 #half life of Bi 213, in seconds
Tltau = 2.2*60 #half life of Tl 209, in seconds
Pbtau = 3.3*60 #half life of Pb 209, in seconds

Bi213 = 10000 #all atoms initially are Bi 213, and decay from there.
Tl209 = 0
Pb209 = 0
Bi209 = 0

dt = 1 #Time step will be 1 second
maxt = 20000 #We will be iterating for 20,000 seconds

#Next we need to calculate our probabilities that each atom will decay per time step, 
#using our dt and half life calculations above.

PBi = 1-2**(-dt/Bitau) #These three our the probabilities we will use later.
PTl = 1-2**(-dt/Tltau)
PPb = 1-2**(-dt/Pbtau)


Bi213list = [] #Make our lists for plotting the atom counts
Tl209list = []
Pb209list = []
Bi209list = []
tpoints = arange(0, maxt, dt) #Makes our entire time axis for our graph


for t in tpoints:
    Bi213list.append(Bi213) #First, append each value to our plotting lists.
    Tl209list.append(Tl209)
    Pb209list.append(Pb209)
    Bi209list.append(Bi209)
    
    #Calculate the number of atoms that decay, starting at the bottom of the
    #decay chain and working up from there.
    decay = 0 #always set this to 0 first.
    for n in range(Pb209):
        if random() < PPb: #Now, for every Pb209 atom, check if it decays at all
            decay += 1 #If it does, add 1 to our decay variable.
    Pb209 -= decay #Then subtract the total decay from Pb209 count
    Bi209 += decay #And add it to the final Bi209 count.
    
    decay = 0 #Next we move up in the decay chain, so we again set this to 0.
    for n in range(Tl209):
        if random() < PTl: #Check if any Tl209 atoms decay
            decay += 1
    Tl209 -= decay #Then subtract the decayed atoms from one count and
    Pb209 += decay #add them to our Pb209 count for the next iteration.
    
    decayTl = 0 #The Bi213 atoms can decay into two separate levels
    decayPb = 0 #So we make two decay variables this time
    for n in range(Bi213):
        if random() < PBi: #First, check if our Bi213 atom decays at all
            if random() <= 0.9791: #If it does decay, then we have to see
                decayPb += 1 #which type of atom it decays into. There is a
            else: #97.91% chance that it will decay into a Pb209 atom, so we
                decayTl += 1 #Check if our random number from 0 to 1 is less
    Bi213 -= decayPb #Than 0.9791, if it is, we decay to Pb209, otherwise we 
    Bi213 -= decayTl #decay to Tl209. Then we add and subtract both decay 
    Pb209 += decayPb #variables accordingly after every iteration.
    Tl209 += decayTl

plot(tpoints, Bi213list, "blue") #Next we plot each list, and set each to 
plot(tpoints, Tl209list, "red") #colors we can see. Tl209 never gets too many
plot(tpoints, Pb209list, "green") #Atoms so we set it to red so we can more 
plot(tpoints, Bi209list, "black") #Easily see it.
title("Radioactive Decay Simulation of Bi 213 isotope")
xlabel("Time (s)") #Label our axes, title, and plot.
ylabel("Number of Atoms")
show()
