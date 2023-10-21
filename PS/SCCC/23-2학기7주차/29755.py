import sys
input=lambda: sys.stdin.readline().strip()
from bisect import bisect
from math import inf
ints=lambda: list(map(int, input().split()))

n, m=ints()
b=[-inf]+sorted(ints())+[inf]
ans=[]
for i in range(m):
    a, w=ints()
    idx=bisect(b, a)
    ans.append(w*min(b[idx]-a, a-b[idx-1]))
print(max(ans))
