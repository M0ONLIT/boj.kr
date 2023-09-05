import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
from math import gcd

def gcds(x):
    for i in range(len(x)-1):
        x.append(gcd(x.pop(), x.pop()))
    return x[0]

n, p=ints()

a=ints()
GCD1=gcds(a[:])
t1=list(map(lambda x: x//GCD1, a))
ans1=sum(t1)

b=ints()
GCD2=gcds(b[:])
t2=list(map(lambda x: x//GCD2, b))
ans2=sum(t2)

v1=v2=0
for i in range(n):
    if t2[i]==0:
        continue
    if v1<t1[i]/t2[i]:
        v2=i
        v1=t1[i]/t2[i]
if v1==int(v1):
    ans2*=int(v1)
else:
    ans2*=int(v1)+1
print(ans1, ans2)
