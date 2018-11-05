"""
Author: Matthew Place
Date: October 3, 2017
Exercise 5.7
This program is designed to use an adaptive trapezoidal rule method of
integration to find the integral of a function to a specific error accuracy.
The program then does the same integral using a Romberg technique for
comparison.
"""

from __future__ import division
from numpy import sqrt, sin

n = 1 #Initial number of slices
c = 0 #limits of integration will be from c to d
d = 1
acc = 1e-6 #we want the accuracy to 6 decimal places

def func(x):
    return sin(sqrt(100*x))**2 #This is the function that we will be integrating

def Trapezoidal(f, a, b, N): #This is our regular Trapezoidal integration
                            #function, which we will use only once when doing
                            #the adaptive technique.
    h = (b-a)/N
    s = 0.5*f(a)+0.5*f(b)
    for k in range(1, N):
        s += f(a+k*h)
        
    return h*s
    
def AdaptiveTrapezoidal(f, a, b, N, accuracy): #This is our adaptive Trapezoidal
    Iinit = Trapezoidal(f, a, b, N) #First find the initial I estimate
    N = 2*N #Double the number of slices
    error = 1
    print N #We must print all N values, I values, and error values for this assignment
    print Iinit
    print error
    while error > accuracy:
        s = 0 #s here is just a variable for use in the integration sum
        h = (b-a)/N #find our h for this N value
        
        for k in range(1, N, 2): #This is to find s while k goes to all odd
                                #numbers from 1 to N
            s += f(a+k*h)
            
        Ifinal = 0.5*Iinit+h*s #This calculates a new estimate for I
        error = abs((1/3)*(Ifinal - Iinit)) #checks error on new I
        Iinit = Ifinal #updates I init to = I final so loop can go again
        print "N =",N #print things again for first task in assignment.
        print "error =",error
        print "Integration Estimate = ",Ifinal
        N = 2*N  # double N
    return Ifinal

#integrationthing = AdaptiveTrapezoidal(func, c, d, n, acc)
#Remove above pound symbol to run part a of assignment.
#Note, we do not need to print integrationthing here because the function itself
#does the printing for us, the function being AdaptiveTrapezoidal.


#Now let's do a fairly complicated Romberg function just to save a little 
#run time!
def Romberg(f, a, b, N, accuracy):
    Rlist = [] #First, I assign a list. The Romberg method will calculate the
    #integral an unknown number of times, and use previous calculations to
    #calculate the next estimation. So here, a list is a wise choice, to store
    #all the calculations of the "Romberg pyramid."
    error = 1 #set error default to 1, a high number for error.
    m = 3 #Here, m is technically 1 while I calculate I1, and then m is technically 2
    #while I calculate I2 and R22, so I just define it as 3 default, since
    #the actual while loop below will start with m = 3, where the m will be used
    
    I1 = Trapezoidal(f, a, b, N) #Using our Trapezoidal function from before,
    #calculate the first integral I1.
    Rlist.append(I1) #This is our first entry in the Rlist.
    N = 2*N #Double the number of slices for I2.
    print "I 1 =",Rlist   #The assignment asks us to print the Romberg triangle
    #of values, so here is where that begins.
    
    I2 = Trapezoidal(f, a, b, N) #now that N has doubled, calculate I2.
    Rlist.append(I2) #This is the next value in our Rlist.
    
    R22 = I2+(1/3)*(I2-I1) #Now we can use our first actual Romberg method technique.
    #Here, we use the previous two integration estimations to calculate a third
    #estimation, which I label as R22, referring to R(2,2) on the pyramid from
    #page 161 of the book. In this case, I calculated 1/(4**1-1) manually and
    #set it to 1/3. I could have technically placed this calculation in the 
    #while loop below, but I was following the book's methodology from pages 160, 161.
    Rlist.append(R22)
    print "I 2 =",Rlist[1:] #Append to list and print next level of triangle
    
    while error > accuracy:
        t = 1 #Here, t is just a chosen variable to represent 4**m-1, only I have
        #labeled it 4**t-1 instead, because m is being used to represent what
        #level of the Romberg triangle I am on and to help give me the proper
        #for loop range for each iteration. So this t value will go from 1 to 2 for
        #level m = 3, then go from 1 to 3 for m = 4, and so forth.
        N = 2*N #gotta double our slices here.
        I = Trapezoidal(f, a, b, N) #This calculates the first value for this
        #level of the Romberg pyramid.
        Rlist.append(I)
        index = len(Rlist)-1 #So here, I am setting the variable 'index' to be at
        #whatever the index value is of the I variable I just appended to the Rlist.
        #I will then refer to this index as the starting value for my for loop
        #below. Essentially, I am taking this triangular matrix and turning into
        #a single row inside of a list, and I need to make sure I know where I
        #am supposed to be at all times. This is the most confusing part of the code
        #I think.
        for k in range(index, index+m-1):  #So here, I start with k equal to the
        #index I just set, and then have it run to index+m-1. This means that k
        #will actually run from k=index to k=index+m-2. I do this because I want
        #Rlist[k] to actually be equal to my R(i,m) value at all times, when looking
        #at equation 5.51 on page 160. So what this means is that, for level 3, I only
        #want two iterations of this k, not 3, even though m is equal to 3. This is
        #because I have already calculated one of the 3 values for level 3 above.
            R = Rlist[k]+(1/(4**t-1))*(Rlist[k]-Rlist[(k+1)-m]) #This is equation
            #5.51, only fitting this Rlist instead of a triangluar matrix.
            t += 1 #Now I need to iterate my t value since I just used it.
            Rlist.append(R)
        error = abs((1/(4**m-1))*(Rlist[index+m-1]-Rlist[index-1])) #The book
        #mentions that only the error on the last estimation on each level is
        #actually desired, on page 161. So here is where I perform that calculation.
        #Again, taking care to make sure I am referring to the correct index in the
        #list.
        print "I",m,"=",Rlist[index:] #This prints the next row of the triangle.
        m += 1 #Now we iterate m.
    print "Number of slices needed =",N #just curious to what number of slices we get to with this method.    
    return Rlist[len(Rlist)-1] #This returns the last calculated value once the
    #desired accuracy has been reached.

pleasework = Romberg(func, c, d, n, acc)
print pleasework
        
#Romberg method uses FAR less slices, meaning far fewer calculations needed.