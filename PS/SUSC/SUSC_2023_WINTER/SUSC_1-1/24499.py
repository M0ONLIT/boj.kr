import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
from fractions import Fraction
from queue import PriorityQueue
from collections import deque
from bisect import bisect
from math import *

n, k=ints()
a=ints()

ans=cur=sum(a[:k])
for i in range(n):
    cur+=a[(k+i)%n]
    cur-=a[i]
    ans=max(ans, cur)
print(ans)
