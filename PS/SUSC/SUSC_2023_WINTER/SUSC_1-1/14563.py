import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
from fractions import Fraction
from queue import PriorityQueue
from collections import deque
from bisect import bisect
from math import *

Int()
for n in ints():
    ans=1
    i=2
    while i*i<=n:
        if n%i==0:
            if i*i==n:
                ans+=i
            else:
                ans+=i+n//i
        i+=1
    if ans<n or n==1: ans='Deficient'
    elif ans==n: ans='Perfect'
    else: ans='Abundant'
    print(ans)
