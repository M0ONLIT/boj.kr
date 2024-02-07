import sys
from math import inf
from collections import deque
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
arr=ints()
mini=inf
ans=0
for i in arr:
    if i<mini:
        mini=i
    ans=max(ans, i-mini)
    print(ans, end=' ')
