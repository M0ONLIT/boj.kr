import sys
from bisect import bisect
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

for tc in range(Int()):
    n, k=ints()
    ans=[0]*n
    fr=[0]*n
    bk=[0]*n
    arr=sorted(enumerate(ints()), key=lambda x: x[1])
    a=[i[1] for i in arr]
    for i in range(n): #fr
        idx=bisect(a, a[i]-k)-1
        fr[i]=(0 if idx==-1 else fr[idx])+1
    for i in range(n)[::-1]: #bk
        idx=bisect(a, a[i]+k-1)
        bk[i]=(0 if idx==n else bk[idx])+1
    for i in range(n):
        ans[arr[i][0]]=fr[i]+bk[i]-1
    print(f"Case #{tc+1}:", *ans)
