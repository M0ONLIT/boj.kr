import sys
from fractions import Fraction
from math import *
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

class PrefixSum:
    def __init__(self, arr):
        self.s=[0]
        for num in arr:
            self.s.append(num+self.s[-1])

    def sum(self, x, y):
        if x==y: return self.s[-1]
        if x>y:
            return self.s[-1]-self.sum(y, x)
        return self.s[y+1]-self.s[x+1]

class point:
    def __init__(self, x, y):
        self.x, self.y=x, y
    def __repr__(self):
        return f'point({self.x}, {self.y})'

def dis(x, y, w, z):
    return (x-w)**2+(y-z)**2

def ccw(p1, p2, p3):
    return (p3.y-p1.y)*(p2.x-p1.x)+(p1.y-p2.y)*(p3.x-p1.x)

def compare(pivot, p):
    x=pivot.x-p.x
    y=pivot.y-p.y
    if x==0:
        return inf, y**2
    return Fraction(y, x), x**2+y**2

def calipus(p):
    global dist
    minp=min(p, key=lambda x: (x.x, x.y))
    stack=[minp]

    p.sort(key=lambda x: compare(minp, x))

    for i in p:
        if (i.x, i.y)==(minp.x, minp.y):
            continue

        while(len(stack)>=2 and ccw(stack[-2], stack[-1], i)<=0):
            stack.pop()
        stack.append(i)
    #여기까지 볼록 껍질

    ans=inf
    i=0
    j=stack.index(max(stack, key=lambda x: (x.x, x.y)))
    S=len(stack)
    dist=PrefixSum([sqrt(dis(stack[i-1].x, stack[i-1].y, stack[i].x, stack[i].y)) for i in range(S)])
    for _ in range(2*S):
        next_i=(i+1)%S
        next_j=(j+1)%S
        d=dist.sum(i, j)
        ans=min(ans, d)
        p1=point(stack[next_i].x-stack[i].x, stack[next_i].y-stack[i].y)
        p2=point(stack[next_j].x-stack[j].x, stack[next_j].y-stack[j].y)
        o=point(0, 0)
        if ccw(o, p1, p2)>=0:
            j=next_j
        else:
            i=next_i
    return ans

n=Int()
p=[point(*ints()) for i in range(n)]
print(calipus(p))
