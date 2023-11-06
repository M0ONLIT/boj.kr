import sys
from math import *
sec=lambda x: 1/cos(x)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

w, h=ints()
(x1, y1), (x2, y2)=sorted((ints(), ints()))

setting=0
if x1==0 and y2==0:
    x1=w; y1=h-y1
    x2=w-x2; y2=h
elif x1==0 and y2==h:
    x1=w; x2=w-x2
elif y1==0 and x2==w:
    y1=h; y2=h-y2
elif y1==h and x2==w:
    pass
elif sorted((y1, y2))==[0, h]:
    x1, y1=y1, x1
    x2, y2=y2, x2
    w, h=h, w
    setting=1
elif sorted((x1, x2))==[0, w]:
    setting=1

(x1, y1), (x2, y2)=sorted(((x1, y1), (x2, y2)))

if setting==0:
    a=h-y2
    b=w-x1
    th=atan(b/a)
    c=a-y2*sec(pi-2*th)
    area=c*c*tan(2*th-pi/2)/2
    if a*cos(pi-2*th)<=y2:
        area=0
    ans=w*h-a*b/2+area
else:
    if y1==y2:
        ans=w*max(h-y1, y1)
    else:
        if y1<=h/2 and y2<=h/2:
            y1=h-y1
            y2=h-y2
        y1, y2=sorted([y1, y2])[::-1]
        a=h-y2
        b=h-y1
        c=sqrt((y1-y2)**2+w**2)
        th=asin(w/c)
        d=y2*sec(pi-2*th)
        area1=(a-d)**2*tan(2*th-pi/2)/2
        if a*cos(pi-2*th)<=y2:
            area1=0
        area2=b*b*tan(pi-2*th)/2
        ans=w*h-(a+b)*w/2+area1+area2

print(int(ans+1e-8))
