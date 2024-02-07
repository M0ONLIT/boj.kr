import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
from fractions import Fraction
from queue import PriorityQueue
from collections import deque
from bisect import bisect
from math import *

def nearby4(y, x, n=5, m=5, dy=[0, 0, 1, -1], dx=[1, -1, 0, 0]):
    ans=[]
    for i in range(4):
        if 0<=y+dy[i]<n and 0<=x+dx[i]<m:
            ans.append((y+dy[i], x+dx[i]))
    return ans

s=set()
arr=[ints() for i in range(5)]

stack=[]
def f(i, j, cnt):
    stack.append(arr[i][j])
    if cnt==5:
        s.add(''.join(map(str, stack)))
    else:
        for nxt in nearby4(i, j):
            f(*nxt, cnt+1)
    stack.pop()
for i in range(5):
    for j in range(5):
        f(i, j, 0)
print(len(s))
