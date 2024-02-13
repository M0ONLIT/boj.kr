import sys
from math import inf
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
arr=sorted(enumerate(ints()), key=lambda x: -x[1])
mini=maxi=arr[0][0]
ans=0
for idx, val in arr[1:]:
    ans=max((ans, val*(abs(idx-mini)-1), val*(abs(idx-maxi)-1)))
    mini=min(idx, mini)
    maxi=max(idx, maxi)
print(ans)
