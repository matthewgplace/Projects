"""
Author: Matthew Place
Date: October 3, 2017
Exercise 5.8
This program is designed to use an adaptive Simpson's rule method of
integration to find the integral of a function to a specific error accuracy.
"""


from __future__ import division
from numpy import sqrt, sin

n = 2 #Initial number of slices
c = 0 #limits of integration will be from c to d
d = 1
acc = 1e-6 #we want the accuracy to 6 decimal places

def func(x):
    return sin(sqrt(100*x))**2 #This is the function that we will be integrating
    

def S1(f, a, b, N): #This will be used to calculate the first S value, from
#equation 5.36. This function will only be called once later.
    h = (b-a)/N
    s = 0.5*f(a)+0.5*f(b)
    
    for k in range(2, N, 2): #even numbered k values only.
        s += f(a +k*h)
        
    return (2/3)*s
    
def T(f, a, b, N): #This is to calculate our T value, equation 5.37 on page 158
    h = (b-a)/N
    s = 0 #define s as 0 at first, just to have it defined.
    for k in range(1, N, 2): #odd numbered k values only.
        s += f(a + k*h)
    return (2/3)*s
    
    
#Now we can use the previously defined functions S1 and T to perform an 
#adaptive technique.
    
def AdaptiveSimpson(f, a, b, N, accuracy):
    error = 1 #Start with a high error.
    h = (b-a)/N
    Si = S1(f, a, b, N) #This calculates our initial value for Si, which is used
    #along with Ti to calculate each integral estimation I.
    Ti = T(f, a, b, N) #This calculates our initial value for Ti, which is combined
    #with Si to calculate I below.
    Iold = h*(Si+2*Ti) #I will need an Inew integral estimation and an Iold
    #integral estimation to calculate the error below, so this first one will
    #simply be Iold, since there is a second interation coming immediately once
    #the while loop starts.
    
    while error > accuracy:
        N = 2*N #double our number of slices
        h = (b-a)/N #calculate our new h
        Si = Si + Ti #calculate our new Si using the Si we found above plus the
        #Ti found above. Note we only called the S1 function once, initially.
        #Now we find each successive Si value by using previous values.
        Ti = T(f, a, b, N) #This calculates our next Ti value.
        Inew = h*(Si+2*Ti) #calculates our next integration estimation, this time
        #calling it Inew, so that we can find the error.
        error = abs((1/15)*(Inew-Iold)) #Finds the error magnitude, to see if the loop
        #continues.
        Iold = Inew #sets Iold to Inew so the next iteration can have a new
        #Inew
        
    print "Number of slices needed =",N #Curious about the total number here.    
    return Inew
    
pleasework = AdaptiveSimpson(func, c, d, n, acc)
print pleasework

#I found that adaptive Trapezoidal needed 4096 slices, adaptive Simpson's needed
#256 slices, and Romberg needed only 64 slices, making it by far the fastest.