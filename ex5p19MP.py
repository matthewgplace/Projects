"""
Author: Matthew Place
Date: December 6, 2017 (Although actually coded sometime in September, I think)
Exercise 5.19 part a through part e i. I never got around to e ii.
This program simulates light going through a transmission diffraction grating,
going through a converging lens, and then hitting a screen. 
It creates a density plot of the resulting interference pattern 
by using computational integration techniques.
"""

from __future__ import division
from pylab import show, imshow, hot
from numpy import sin, pi, sqrt, empty
from cmath import exp

"""
Part a) Here, we need to understand that u is the distance from the central axis,
and if we let u = d = the slit spacing the find when sin(ad) = 0 note, a is alpha here.

sin(ad) = 0 when au = n*pi. n can be any integer, we will let it be 1 here for
simplicity. So a = pi/d

So our transmission function becomes sin^2(u*pi/d) with d being the slit spacing
and u is our position from the center axis.
"""


xwidth = 0.1 #The screen is 10 cm by 10 cm, so this xwidth will represent that.
dx = 0.0001 #This is our step size as we move from left to right and making
    #our density plot of the screen.
points = xwidth/dx #This gives us the total number of grid points along any
    #of the sides of the screen. 
d = 2e-5 #slit separation in meters (20 micrometers)
slits = 10 #total number of slits on the diffraction grating
w = slits*d #total width of the diffraction grating
wave = 500e-9 #wavelength of the incoming light, in meters.
focus = 1 #focal length of the converging lens
xdplot = empty([points, points], float) #an empty array which serves as our
    #eventual density plot
n = 100 #slices for Simpson's integration later, making this number too low 
#actually has quite drastic effects on the density plot. Try making it 30. 
#Part c) I chose 100 since making it much higher has negligible effects on the
#density plot, but making it lower you can start to see the differences. Also,
#100 is a nice round number. I chose Simpson's Method at the time of
#programming this because it is what I knew, primarily. It is also nice and fast.

def transmissionfunc1(u):
    func = sin((pi*u)/d)**2
    return func #this is the function for part b
    
def transmissionfunc2(u):
    func = sin((pi*u)/d)**2*sin((pi*u)/(2*d))**2
    return func #this is the function for part e i.
    
def intensityfunc(u):
    func = sqrt(transmissionfunc1(u))*exp((1j*2*pi*x*u)/(wave*focus))
    return func #This is the integrand from the intensity function given in the problem.


#Now we have a function for taking an integration via Simpson's method.
#This method is a technique from chapter 5.
def integrate(f, a, b, N):
    h = (b-a)/N
    k = 0
    s = a+h
    for i in range(1, int(N/2+1)):
        k += 4*f(s)
        s += 2*h
    
    s = a+2*h
    for i in range(1, int(N/2)):
        k += 2*f(s)
        s += 2*h
    
    return (h/3)*(f(a)+f(b)+k)
    
x = -xwidth/2 #Now we will be checking each horizontal point from the left
#edge of our screen, located at a position of -xwidth/2, all the way to
#the other edge, located at a position of xwidth/2. We have centered the screen
#so that our density plot has the center of the image being where the origin
#is located.
#Note: Since the pattern only varies along the horizontal, once we have our
#intensity at an x-position here, we can then just set that same intensity all 
#along that vertical line in the density plot. Our interference pattern will be
#vertical lines.


while x <= xwidth/2:
    
    #First, we calculate the intensity at this given x point, given our integration
    #limits of -w/2 to w/2, making sure to square the absolute value of it, as shown
    #in the problem. We use 100 slices, as that is enough here.
    
    #Note, change intensityfunc to intensityfunc2 in order to see part e i.
    I = abs(integrate(intensityfunc, -w/2, w/2, n))**2
    #Now that we have the intensity at this point, we will set every other value
    #along the vertical (array column) to this same intensity value. Remembering
    #that our interference pattern has vertical lines
    for p in range(int(points-1)):
        xdplot[p, int((x+xwidth/2)*(1/dx))] = I
    x+=dx

#Now we plot our density plot, making sure to set its extent so that the screen
#is centered at the origin.
imshow(xdplot, origin="lower", extent=[-xwidth/2, xwidth/2, -xwidth/2, xwidth/2])  
hot()
show()