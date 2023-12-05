import sys
from math import *
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
a=ints()
ans=-1
for x in range(1, 10):
    for y in range(1, 10):
        s=cnt=0
        for i in a:
            if i==x or i==y:
                cnt+=1
            else:
                cnt=0
            s=max(s, cnt)
        ans=max(ans, s)
print(ans)
