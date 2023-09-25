import sys
from collections import deque
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n, k=ints()
cat=sorted(ints())

ans, s, e=0, 0, n-1
while s<e:
    if cat[s]+cat[e]<=k:
        ans+=1
        s+=1
    e-=1
print(ans)
