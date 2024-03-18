from fractions import Fraction
from math import *
import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

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

def convex_hull(p):
    n=len(p)

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
    return stack

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

accs=[]
g=Int()
s=point(0, 0)
for i in range(g):
    input()
    n=Int()
    p=convex_hull([point(*ints()) for i in range(n)])
    len_p=len(p)
    q=[0]*len_p
    s+=p[0]
    for i in range(len_p):
        q[i]=p[i]-p[(i-1)%len_p]
    accs.extend(q)
accs.sort(key=lambda x: angle(point(0, -1), point(0, 0), x))

ans=0
for i in accs:
    ans=max(s.x**2+s.y**2, ans)
    s+=i
print(ans)
