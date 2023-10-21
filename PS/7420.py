from fractions import Fraction
from math import *

class point:
    def __init__(self, x, y):
        self.x=x
        self.y=y

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

    #return (atanC-atanA)%(2*pi) 0~2*pi  로 나타내고 싶을 때.
    #return (atanC-atanA) #호도법, 우회전이면 +, 좌회전이면 -
    #return degrees(atanC-atanA) #각도로 표기
    return abs(atanC-atanA)

def dis(A, B):
    return sqrt((A.x-B.x)**2+(A.y-B.y)**2)

n, l=map(int,input().split())
p=[point(*map(int,input().split())) for i in range(n)]

minp=min(p, key=lambda x: (x.x, x.y))
stack=[minp]
def compare(pivot, p):
    x=pivot.x-p.x
    y=pivot.y-p.y

    if x==0:
        return inf, y**2
    return Fraction(y, x), x**2+y**2

p.sort(key=lambda x: compare(minp, x))

for i in p:
    if (i.x, i.y)==(minp.x, minp.y):
        continue

    while(len(stack)>=2 and ccw(stack[-2], stack[-1], i)<=0):
        stack.pop()
    stack.append(i)

ans=0
s=len(stack)
for i in range(s):
    ans+=dis(stack[i], stack[(i+1)%s])
ans+=l*2*pi
print("%.0f"%ans)
