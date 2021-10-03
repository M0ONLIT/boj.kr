import sys
input=sys.stdin.readline

n=int(input())
s=input().rstrip()
L=list(map(int, input().split()))
v=[]
c=s[0]
for i in range(n):
    x=L[i]
    if c==s[i]:
        if len(v)>0:
            v[-1]=max(v[-1], x)
    else:
        c=s[i]
        v.append(x)

if len(v)>0:
    v.pop()
print(sum(sorted(v)[len(v)//2:]))
