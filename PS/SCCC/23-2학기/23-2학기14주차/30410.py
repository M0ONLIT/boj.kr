import sys
from math import *
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
a=ints()
stack=[[1, 0]]

def mxb(x):
    if x<1:
        return 0

    ans=1
    while (ans<<1)<=x:
        ans<<=1
    return ans

def g(L):
    s=L[-1]
    cnt=0
    while L and L[-1]==s:
        L.pop()
        cnt+=1
    return s, cnt

while a:
    s, cnt=g(a)
    if s==1:
        if cnt%2==0:
            s, cnt=2, cnt//2
    if stack==[] or stack[-1][0]!=s:
        stack.append([s, cnt])
    else:
        stack[-1][1]+=cnt
stack.append([1, 0])
ans=0
for i in range(len(stack)):
    s, cnt=stack[i]
    if s==1:
        ans=max(ans, mxb(cnt))
    else:
        t=0
        if i!=0: t+=stack[i-1][1]//2*2
        t+=s*cnt
        if i!=n-1: t+=stack[i+1][1]//2*2
        ans=max(ans, mxb(t))
print(ans)
