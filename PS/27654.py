import sys
from fractions import Fraction
input=sys.stdin.readline
ints=lambda: list(map(int, input().split()))
n, k=ints()
arr=sorted([ints() for i in range(n)])

loss=1e-7
start, end=0, 1

def check(x):
    ans=0
    p=sorted(arr, key=lambda pii: pii[0]-x*pii[1], reverse=True)
    for i in range(k):
        ans+=p[i][0]-x*p[i][1]
    #print(ans)
    return ans>=0

while end-start>loss:
    mid=(start+end)/2
    if check(mid): ans=start=mid
    else: ans=end=mid
print("%.7f"%ans)
