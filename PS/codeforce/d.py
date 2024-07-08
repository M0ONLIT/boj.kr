import sys
from collections import defaultdict, deque
from math import *
from bisect import *
from fractions import Fraction as F
sys.setrecursionlimit(10**5)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

f=open('input.txt', 'w')
f.write('1\n')

n=100000
f.write(f'{n}\n')
for i in range(1, n+1):
    f.write(f'{i} ')
f.write('\n')
for i in range(1, n+1)[::-1]:
    f.write(f'{i} ')
f.write('\n')
f.close()
