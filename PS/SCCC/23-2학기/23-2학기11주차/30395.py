from math import inf
import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n=int(input())
a=ints()
stack=[0]

for i in a:
    if i:
        if stack[-1]>=0:
            stack[-1]+=1
        else:
            stack.append(1)
    else:
        if stack[-1]<=0:
            stack[-1]-=1
        else:
            stack.append(-1)

ans=t=0
for i in stack:
    if i>=0:
        t+=i
        ans=max(t, ans)
    elif i==-1:
        pass
    else:
        t=0
print(ans)
