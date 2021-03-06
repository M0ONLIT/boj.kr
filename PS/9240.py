import sys
input=sys.stdin.readline

def dis(x, y, w, z):
    return (x-w)**2+(y-z)**2
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

n=int(input())
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
for i in range(len(stack)):
    for j in range(i+1, len(stack)):
        ans=max(ans, dis(stack[i].x, stack[i].y, stack[j].x, stack[j].y))
    
print(sqrt(ans))
