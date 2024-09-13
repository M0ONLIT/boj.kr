from collections import defaultdict, deque, Counter
from math import *
from bisect import *
from fractions import Fraction as F
from heapq import *
from random import *
from itertools import permutations, combinations
import sys
#sys.setrecursionlimit(10**5)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
for i in range(n):
    x, y, z=ints()
    if (x+y+z)%2: print('NO')
    else: print('YES')
