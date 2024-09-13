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

s=0
for i in range(Int()):
    p, q=ints()
    if p==1: s+=q
    else: s-=q

    if s<0: print('Adios'); exit()
print('See you next month')
