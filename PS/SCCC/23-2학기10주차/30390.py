import sys
from math import gcd
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

a, b, k=ints()
if min(a, b)<=k:
    print(a+b)
    exit()
ans=1
def solve(i):
    global ans
    p=a//i*i
    if -k<=a-p<=k:
        #print(1)
        if gcd(p, s-p)%i==0:
            ans=max(i, ans)
    p=(a//i+1)*i
    if -k<=a-p<=k:
        #print(2)
        if gcd(p, s-p)%i==0:
            ans=max(i, ans)
    p=b//i*i
    if -k<=b-p<=k:
        #print(3)
        if gcd(p, s-p)%i==0:
            ans=max(i, ans)
    p=(b//i+1)*i
    if -k<=b-p<=k:
        #print(4)
        if gcd(p, s-p)%i==0:
            ans=max(i, ans)
s=a+b
i=1
while i*i<=s:
    if s%i==0:
        solve(i)
        solve(s//i)
    i+=1
print(ans)
