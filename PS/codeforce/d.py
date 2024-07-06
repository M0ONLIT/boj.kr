import sys
from collections import defaultdict, deque
from math import *
from bisect import *
from fractions import Fraction as F
sys.setrecursionlimit(10**5)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
arr=[ints() for i in range(n+1)]
s, e=ints()

def p(x):
    for i in range(n):
        (a1, b1), (a2, b2)=arr[i], arr[i+1]
        if a1<=x<=a2: break
    y=F(b1-b2, a1-a2)*(x-a1)+b1
    return x, y
s, e=p(s), p(e)
print(abs(F(s[1]-e[1], s[0]-e[0])))
