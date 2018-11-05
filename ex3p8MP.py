"""
Author: Matthew Place
Date: September 19, 2017
Exercise 3.8
This program is designed to read data from a file, plot that data along
with a best fit line running through it. Then, the program estimates
Planck's constant using this data.
"""

from __future__ import division
from numpy import loadtxt
from pylab import plot, show, title, xlabel, ylabel

electroncharge = 1.602e-19 #(C) This is a constant value, charge of an electron
#The next two empty lists are for the y values for the best fit line, and the
#y values which will equal each voltage multiplied by the electroncharge above.
#The findh list will be used to do just that, find Planck's constant, h.
ybest = []
findh = []

#First, we must load the data and assign it to two separate arrays.
data = loadtxt("millikanMP.txt", float)
x = data[:,0]
y = data[:,1]

#Now, we must calculate the slope and y-intercept of our best fit line.
#Both the slope and shift involve equations with sums
Ex = (1/len(x))*sum(x)
Ey = (1/len(x))*sum(y)
Exx = (1/len(x))*sum(x**2)
Exy = (1/len(x))*sum(x*y)
#The previous four variables are all used to find the least-squares fit of our
#line, which will best fit the 6 points in the data set

#Now the next time lines actually calculate the slope and y-intercept of the
#best fit line
m = (Exy-Ex*Ey)/(Exx-Ex**2)
c = (Exx*Ey-Ex*Exy)/(Exx-Ex**2)

#Now to print these values, as per instructions in Exercise 3.8
print "The slope of the best fit line is",m
print "The shift of the best fit line is",c


#Now we need to get values to plot our best fit line, for each point x we
#will need a y value equal to mx+c where m is the best fit slope and c is the
#best fit y-intercept, and each x corresponds to a different y value along 
#the best fit line.

#So, we create a for loop ranging from 0 to the number of values of x or y.
for a in range(0, len(x)):
    #Now we append each y value to the best fit line y list.
    ybest.append(m*x[a]+c)
    
    #Also, since we don't want to do another for loop later, we might as well
    #append our y values for finding h, since we will be finding Planck's constant
    #later.
    #this comes from Ve = hv+W, where V is the voltage measured, e is the charge
    #of an electron, v is the frequency measured, h is Planck's constant, and W
    #is the work function, which is the energy needed to remove an electron from
    #the surface due to the photoelectric effect.
    
    #Note, Ve = hv+W looks a lot like y = mx+c, hence why we have a "y" list where
    #we append V*e, with V being what our y array is currently comprised of. By finding
    #the best fit line's slope through this particular set of data we will be able to
    #estimate Planck's constant.
    
    findh.append((y[a]*electroncharge))

#Now, since we have used our previous best fit line calculations all up and they
#are stored in the ybest list, we can redo our best fit calculation to now match
#our stored values in the findh list, where this time the slope will be equal to
#h and the y-intercept will be equal to the work function.

#Note, this is all possible because MillikanMP.txt has frequency measurements for
#its x values and voltage measurements for its y values, corresponding to tests of
#the photoelectric effect.

#So, now, using our findh list for "y" values, we redo the calculation for the
#best fit line.
Ex = (1/len(x))*sum(x)
Ey = (1/len(x))*sum(findh)
Exx = (1/len(x))*sum(x**2)
Exy = (1/len(x))*sum(x*findh)
m = (Exy-Ex*Ey)/(Exx-Ex**2)
c = (Exx*Ey-Ex*Exy)/(Exx-Ex**2)

#We now have enough information to print our estimation for Planck's constant
#as well as the percentage of the actual agreed value it is.
print "The estimated Planck's constant here is",m,"(m^2 kg s^-1)"
print "This is",m/6.626e-34,"percent of the true value"

#All that is left to do now is plot the graphs. We make two plots, one with
#the best fit line, and then one with just the x and y original values read
#from the file. The points read from the file are set to be black circles
#while the best fit line is left in the default line format.
plot(x,ybest)
plot(x,y, "ko")

#Now we title our graph and label our axes.
title("Millikan's Experimental Data")
xlabel("Frequency (Hz)")
ylabel("Voltage (V)")

#Now we show our plot and then we are done.
show()