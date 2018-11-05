from __future__ import division
from pylab import plot, show, xlim, ylim
from numpy import sin, arcsin, cos, pi, sqrt

xi = [0]
yi = [0]
xr = [0]
yr = [0]
xg = [0]
yg = [0]
xb = [0]
yb = [0]
linex = []
liney = []

r = 1
i = 52*pi/180
order = 1
wlg = 0.00055
wlr = 0.00075
wlb = 0.00035
spacing = 1/600

def diffract(m, w, d, a):
    b = arcsin((m*w/d)-sin(a))
    if b*180/pi > 90:
        b = 0
    return b
    
xi.append(r*cos(i))
yi.append(r*sin(i))
xg.append(r*cos(diffract(order,wlg,spacing,i)))
yg.append(r*sin(diffract(order,wlg,spacing,i)))
xr.append(r*cos(diffract(order,wlr,spacing,i)))
yr.append(r*sin(diffract(order,wlr,spacing,i)))
xb.append(r*cos(diffract(order,wlb,spacing,i)))
yb.append(r*sin(diffract(order,wlb,spacing,i)))
linex.append(xr[1])
linex.append(xb[1])
liney.append(yr[1])
liney.append(yb[1])

distance = sqrt((linex[1]-linex[0])**2+(liney[1]-liney[0])**2)
f = (diffract(order,wlg,spacing,i)*180/pi)

i = i*180/pi

print f
print i-f
print distance

xlim(-1.2, 1)
ylim(-1, 1)
plot(xi,yi, "black")
plot(xg,yg, "g")
plot(xr,yr, "r")
plot(xb,yb, "b")
plot(linex, liney, "black")
show()
    