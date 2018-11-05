"""
Author: Matthew Place
Date: September 21, 2017
Exercise 4.3
This program is designed to approximate the derivative of a function using the
forward approximation. The distance between points, dx, is then varied.
"""

from __future__ import division #Always import division from the future, for better dividing


#first, I define a function f(x) that simply returns x(x-1)
#This is simply allowing the user to input x and return f(x) where f(x)=x(x-1)

def function(x):
    return x*(x-1)
    
    
    
"""
Now, if I were to manually take the derivative of f(x) at x=1, the result would simply
be f'(x)=2x-1, and with x = 1, that would give f'(1)=1
However, we cannot really take limits here, so we will approximate the derivative
by allowing the user to set a small dx value, which we will then test to see which
dx value gives us an answer closest to 1 for our f(x) when x is equal to 1.
"""



def derivatate(x,dx):
    f = (function(x+dx)-function(x))/dx
    return f
    
    
    
"""
One thing of note, in the user defined function above, I actually call my previous
function from before, because I need to evaluate that original function twice inside this
derivatate function. Once at f(x+dx) and once at f(x).

Now I will print out each of the calculations with varying values for dx.
"""



print "dx = 10^-2:  ", derivatate(1, 1e-2)



"""
This first calculation lets dx be a pretty large number at 0.01.
If I were to do this manually, I get (f(1.01)-f(1))/0.01
This is equal to (0.0101-0)/0.01, which is equal to 1.01
The true value should simply be equal to 1, so because my dx is 10^-2,
My value is correct to 2 decimal places here. By making dx smaller, the value should
get closer and closer to correct, until the rounding error starts to make more of
an impact and then the value will get worse again.
"""


print "dx = 10^-4:  ", derivatate(1, 1e-4)
print "dx = 10^-6:  ", derivatate(1, 1e-6)
print "dx = 10^-8:  ", derivatate(1, 1e-8)
print "dx = 10^-10: ",derivatate(1, 1e-10)
print "dx = 10^-12: ",derivatate(1, 1e-12)
print "dx = 10^-14: ",derivatate(1, 1e-14)



"""
The reason that the result gets closer to correct towards a dx of 10^-8 and then
starts to get less correct once you keep making dx smaller has to do with what we
discussed in class on 9/20/17.

In class, we discussed how because when you take the derivative computationally, it
involves subtraction, the rounding error plays an important role here. In Python,
any number with more than 16 significant figures gets rounded off. So C = 10^-16 is a 
constant that we typically use when trying to look at how much our error will be.

In section 4.2, we learned that subtraction gives rise to significant rounding
errors compared to other types of arithmetic when coding.

So we have rounding error as we make dx smaller and smaller, closer to C. But we also
have error because we cannot take the limit as dx goes to 0. By expanding f(x) about x
in a Taylor series we were able to see that the approximation error is about 
1/2*dx*abs(f''(x))

The worst case error scenario due to the rounding will be equal to
(2*C*abs(f(x)))/dx

If you then try to find a value for dx that minimizes the sum of these two errors,
you find that dx has to be roughly on the order of the square root of C, for the 
forward and backward approximations to differentiation.

This explains why we see above that our value gets closest to the true value at
dx = 10^-8
"""