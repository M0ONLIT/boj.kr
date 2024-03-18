### templete
import sys
from collections import deque
from bisect import bisect
sys.setrecursionlimit(10**8)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
###


n=int(input())
arr=sorted(ints(), reverse=1)

s=0
for i in range(n):
    if arr[i]-i<0:
        break
    s+=arr[i]-i
print(s)
