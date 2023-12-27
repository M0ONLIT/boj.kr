import sys
from math import *
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
a=ints()
ans=[]
for i in range(n):
    value=a[i]
    idx=start=len(ans)
    while start>0 and gcd(value, ans[start-1])==1:
        if ans[start-1]>value:
            idx=start-1
        start-=1
    ans.insert(idx, value)
print(*ans)
