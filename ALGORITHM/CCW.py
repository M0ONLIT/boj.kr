from math import *

class point:
    def __init__(self, x, y):
        self.x=x
        self.y=y

    def __add__(self, other):
        return point(self.x+other.x, self.y+other.y)

    def __iadd__(self, other):
        self.x+=other.x
        self.y+=other.y
        return self

    def __sub__(self, other):
        return point(self.x-other.x, self.y-other.y)

    def __isub__(self, other):
        self.x-=other.x
        self.y-=other.y
        return self

    def __repr__(self):
        return f'point({self.x}, {self.y})'

def ccw(p1, p2, p3):
    return (p3.y-p1.y)*(p2.x-p1.x)+(p1.y-p2.y)*(p3.x-p1.x)

def angle(A, B, C):
    new_A=point(A.x-B.x, A.y-B.y)
    new_C=point(C.x-B.x, C.y-B.y)
    if new_C.x==0:
        atanC=pi/2*(1 if new_C.y>0 else -1)
    else:
        atanC=atan(new_C.y/new_C.x)
    if new_A.x==0:
        atanA=pi/2*(1 if new_A.y>0 else -1)
    else:
        atanA=atan(new_A.y/new_A.x)

    check=ccw(A, B, C)
    value=degrees((atanC-atanA))+(180 if check>0 else 0) #우회전 각도기준 0~360으로 나타내기.
    return 360. if value==0 else value
    #return (atanC-atanA) #호도법, 우회전이면 +, 좌회전이면 -
    #return degrees(atanC-atanA) #각도로 표기
    #return abs(atanC-atanA)
