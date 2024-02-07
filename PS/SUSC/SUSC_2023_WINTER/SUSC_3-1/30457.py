import sys
from math import inf
from collections import deque
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
arr=ints()
fst=set()
snd=set()
for i in arr:
    if i in fst: snd.add(i)
    else: fst.add(i)
print(len(fst)+len(snd))
