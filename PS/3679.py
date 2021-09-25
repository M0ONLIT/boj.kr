from fractions import Fraction
from math import *
import sys
sys.setrecursionlimit(10**8)

class point:
    def __init__(self, x, y, index=None):
        self.index=index
        self.x=x
        self.y=y

    def __repr__(self):
        return f'point({self.x}, {self.y})'

def compare(pivot, p, maxacc):
    if pivot.index==p.index:
        return -inf, -inf
    x=pivot.x-p.x
    y=pivot.y-p.y

    a=acc(pivot, p)

    if a==maxacc:
        return a, -(x**2+y**2)
    return a, x**2+y**2

def acc(pivot, p):
    if pivot.index==p.index:
        return -inf
    x=pivot.x-p.x
    y=pivot.y-p.y

    if x==0:
        return inf
    return Fraction(y, x)


for i in range(int(input())):
    a=list(map(int, input().split()))
    p=[point(a[2*i+1], a[2*i+2], i) for i in range(a[0])]
    minp=min(p, key=lambda x: (x.x, x.y))
    maxacc=acc(minp, max(p, key=lambda x: acc(minp, x)))

    p.sort(key=lambda x: compare(minp, x, maxacc))
    print(*map(lambda x:x.index, p))
