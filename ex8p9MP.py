"""
Author: Matthew Place
Date: December 3, 2017
Exercise 8.9
This program solves the equations of motion for vibration in a one-dimensional
system involving N number of oscillating masses. It then plots these masses
over time and performs the Fourier Transform of them. This program also 
animates the masses moving back and forth
"""

from __future__ import division
from math import cos
from numpy import arange, zeros
from numpy.fft import rfft, fftfreq
from pylab import show, figure
from matplotlib.animation import FuncAnimation

n = 5 #Number of oscillators, must be >= 2 since given equations in book assume
        #at least 2 oscillators. Note: You can change this value and everything
        #in this program still works properly. Making n much larger here may
        #run fairly slowly though, due primarily to the animation.

nrange = arange(1, n+1) #Makes a range of N values, I use this all over the place

m = 1 #Masses of each oscillator in kg
k = 6 #spring constant (kg/s^2)
omega = 2 #angular velocity for the sinusoidal force on one of the masses, m/s

a = 0 #Initial time for calculation, in seconds
b = 20 #seconds, maximum time
samples = 1000 #accuracy for Range-Kutta method
h = (b-a)/samples #used in Range-Kutta method and also as our timestep here
trange = arange(a, b, h) #makes a range of time values between a and b seconds


xlists = [[] for s in nrange] #Since the problem wants me to make this code good
                                #for N number of oscillators, I make a list of lists...
                                #This assignment would be quite a bit simpler
                            #If I didn't have to make it good for any number
                            #of masses. I wonder if my classmates actually did
                            #did this properly.


def Force(i, t):
    #External force, only existing on the first mass in this case.
    #You could change this force and the rest of the code should still work properly.
    if i == 1:
        return cos(omega*t) #Note, omega is constant as defined above.
    else:
        return 0
        

def f(r, t): #This is for solving the equations of motion using the Range-Kutta method
    returnarray = zeros(2*n) #Make a single-row array of 0 values.
            #It is 2N in size due to splitting the differential equation into
            #first order versions. dx1/dt = x2 and dx2/dt = our given 
            #piecewise function for solving for the displacement.
    
    
    #Importantly, I have chosen my r-vector to operate in a specific way here.
    #Every pair of values will be that corresponding x1 and x2 value for that particular
    #mass i. So mass 1 will be located at r[0] = x1 and r[1] = x2
    #mass 2 will then have r[2] = x1 and r[3] = x2 and so on.
    #This corresponds to x1 = r[2*i-2] and x2 = r[2*i-1] to always point to the
    #correct element in r.
    
    #I am doing it like this because my returnarray here must be of the same size
    #as the array r that I use when applying the Range-Kutta method down below
    #as I am multiplying this by k1, k2, k3, and k4.
    
    
    for i in nrange: #this is similar to assignment 8.4 but instead of 2 equations
                #we have 2N equations, so we need a loop here, we solve two at a time.
        x1 = r[2*i-2] #Finds initial x1 from r vector
        x2 = r[2*i-1] #Finds initial x2 from r vector
        fx1 = x2 #Our first First-Order diff eq.
        
        #Next is our second First-Order diff eq, which is the piecewise one
        #given in the book problem itself. I have changed the indices of the 
        #equation to always make sure I am pointing to the correct mass
        #displacement in my r vector. 
        #If the mass displacement we our currently checking is x,
        #x_i = r[2*i-2] = x1 from above
        #x_i-1 = r[2*i-4]
        #x_i+1 = r[2*i]
        if i == 1:
            fx2 = (1/m)*(k*(r[2*i]-x1)+Force(i, t))
        elif i == n:
            fx2 = (1/m)*(k*(r[2*i-4]-x1)+Force(i, t))
        else:
            fx2 = (1/m)*(k*(r[2*i]-x1)+k*(r[2*i-4]-x1)+Force(i, t))
            
        #Now we update the valuies in the element locations in our 
        #returnarray that correspond #to this particular mass i, and then 
        #move on to the next mass.
            
        returnarray[2*i-2] = fx1
        returnarray[2*i-1] = fx2
        
    return returnarray
        
#We are now ready to perform the Range-Kutta solving, so we make our r vector
#We make it all 0 values since all masses will be starting with no displacements
#Or velocities. The external force will give us the oscillation over time.
        
r = zeros(2*n)

for t in trange:
    for i in nrange:
        xlists[i-1].append(r[2*i-2])
        
    #Each list in xlists corresponds to the displacements of a different mass
    #So I run a loop over time and for each time value I run a loop through
    #All the masses, updating the list for that mass.
    
    k1 = h*f(r, t)
    k2 = h*f(r+0.5*k1, t+0.5*h)
    k3 = h*f(r+0.5*k2, t+0.5*h)
    k4 = h*f(r+k3, t+h)
    r += (k1+2*k2+2*k3+k4)/6
    #The above is the same from the book.
    
#We now have everything we need to plot part a, we plot all of the xlists and
#use the trange as our time axis. But we want to animate this and plot the 
#Fourier Transform and we want it to look nice so we are not done yet!

fig = figure() #I make this so that I can put multiple different plots in the
            #same window

ax1 = fig.add_subplot(221) #This will be the first plot, it is the animation plot.
ax1.set_xlim(0, n+1) #I need to make sure my masses are in view. I will
                    #start each mass on integer values along the x-axis.
                    #So if I have 5 masses, they will start at x=1 through x=5
                    #and oscillate from there.
ax1.set_title("Oscillating Masses Animation")
ax1.set_xlabel("Distance(m)")
ax1.set_ylabel("Distance(m)")

ax2 = fig.add_subplot(222) #This will be for the plot of all 5 mass displacements
                        #over time on the same graph.
ax2.set_title("Mass Displacements over Time")
ax2.set_xlabel("Time(s)")
ax2.set_ylabel("Displacement (m)")

ax3 = fig.add_subplot(223) #This will be to show the Fourier Transform of one of the
                        #masses. I made the xlim to have a very small range
                        #to help make the frequencies more visible.
ax3.set_xlim(0,0.002)
ax3.set_title("Fourier Transform of one Mass")
ax3.set_xlabel("Frequency (Hz)")
ax3.set_ylabel("Amplitude")



"""
animation section
"""
xanimate = [[] for s in range(len(xlists[0]))] #this section looks simple but
yanimate = [[] for s in range(len(xlists[0]))] #took a while for me, need practice.

#So the first two lines above make two.... large.... lists of lists.
#Basically, I needed to be able to iterate my update function below by
#simply running through each by n. In order to do that, at each "n" point
#I need it to give me an entire list of all correct mass positions to plot.
#So I needed a large lists of lists here. This is at least nicer than my
#Orbital mechanics animation from Mechanics class.

point, = ax1.plot([s for s in nrange], [0 for s in nrange], "ko", ms=3)
#This creates our initial plot. Meaning points at (1,0) (2,0) (3,0) ... (n,0)
#The comma after "point" makes it an iterator.

for s in range(len(xlists[0])): #A large loop
    for i in nrange: #A smaller loop, unless you have thousands of masses...
        xanimate[s-1].append(i+xlists[i-1][s-1]) #This line looks at the certain
                #element of our xanimate list of lists. It will make that first
                #list have all of the i mass locations by taking its initial
                #location, i, and adjusting it by the corresponding displacement
                #value located in the xlists list of lists.
        
                #So, if you were to look at an early list in xanimate, you might
                #see something like [1.01, 2.002, 3.00005, 4, 5]
                #Meaning that the first mass has started moving but it hasn't
                #quite made the last mass move yet.
        
        yanimate[s-1].append(0) #This list of lists will be all 0 values since I am
                                #only looking at one dimension.

def update(n):
    
    point.set_data(xanimate[n], yanimate[n]) #All that crazy stuff above was to
            #make this function simple. I update the value of my point iterator
            #simply by iterating through my xanimate and yanimate lists, 1 element
            #at a time. In this case, each element is an entire list. The plot
            #then updates.
    return point
    
ani = FuncAnimation(fig, update, len(xlists[0]), interval = 0) 
#This tells it to animate in fig, use the update function to do so, go for a max
#frame count of the length of one of our xlists lists, and do so at a short
#interval.    
    

"""
End of animation section
"""  


#Next, we plot our N mass displacements over time as asked by the task.
for s in nrange:
    ax2.plot(trange, xlists[s-1])
  


"""
Fourier Transform section
"""
#Finally, we perform a simple FT of one of the xlists lists to show
#the corresponding frequencies of oscillation.
u = rfft(xlists[1]) #Takes the FT
freqspace = fftfreq(len(u))*h #Converts it to Frequency using the fftfreq function
ax3.plot(freqspace, abs(u)) #plots it.

"""
End of Fourier Transform section
"""    

#Whew

show()  
    