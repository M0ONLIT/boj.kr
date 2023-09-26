import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
from queue import PriorityQueue
from collections import deque
from bisect import bisect
from math import *

from decimal import *
getcontext().prec=28
d=Decimal

def changetype(value, *types):
    for i in range(min(len(value), len(types))):
        value[i]=types[i](value[i])
    return value

def nearby4(y, x, n=n, m=m, dy=[0, 0, 1, -1], dx=[1, -1, 0, 0]):
    ans=[]
    for i in range(4):
        if 0<=y+dy[i]<n and 0<=x+dx[i]<m:
            ans.append((y+dy[i], x+dx[i]))
    return ans
