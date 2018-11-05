"""
Author: Matthew Place
Date: October 27, 2017
Exercise 6.2
This program is designed to demonstrate a partial pivoting of rows of a matrix to
solve systems of equations.
"""
from __future__ import division
from numpy import array, empty


A = array([[0, 1, 4, 1], [3, 4, -1, -1], [1, -4, 1, 5], [2, -2, 1, 3]], float)
v = array([-4, 3, 9, 7], float)
N = len(v)

for m in range(N):
    checklist = [] #defines an empty list which will be used to check if pivoting
    #is needed
    
    for s in range(m+1, N): #starting at m+1, element under current element
        checklist.append(A[s, m]) #appends the column of elements under current
        #element [m,m] in matrix.
        
    if checklist != []: #if the checklist is empty, problems occur here, so we make
    #sure it is not empty.
    
        if A[m,m] < max(map(abs, checklist)): #Now, we check if our current selected
        #element is less than any of the absolute values of the elements in the
        #checklist.
        
            checklist = map(abs, checklist) #if it is, we first turn our checklist
            #into those absolute valued versions, so that we can find the index
            #of the max correctly.
            
            b = checklist.index(max(checklist))+m+1 #Now we find the index that
            #this max is at and add m+1 to it, since if it is at index 0 it
            #actually corresponds to the index of just 1 below m in that column.
            
            A[m,:], A[b,:], v[m], v[b] = A[b,:].copy(), A[m,:].copy(), v[b], v[m]
            #This exchanges the rows of our matrices.
            
    #The rest of the code is lifted from the book, which is used for Gaussian
            #elimination.
        #Divide diagonal element
    div = A[m,m]
    A[m,:] /= div
    v[m] /= div
    
        #Now subtract from the lower rows
    for i in range(m+1, N):
        mult = A[i,m]
        A[i,:] -= mult*A[m,:]
        v[i] -= mult*v[m]  
#Backsubstitution
x = empty(N, float)
for m in range(N-1, -1, -1):
    x[m] = v[m]
    for i in range(m+1, N):
        x[m] -= A[m,i]*x[i]
        
        
print x