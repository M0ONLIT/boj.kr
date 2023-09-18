import random, sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n=int(input())
s=input()
l=[]
dic={'R':0, 'G':1, 'B':2}
for i in s:
    l.append(dic[i])

ans=10**9

L=l.copy()
cans=0
for i in range(2, n):
    if L[i-2]%3==0:
        continue
    elif L[i-2]%3==1:
        L[i-2]+=2
        L[i-1]+=2
        L[i]+=2
        cans+=2
    else:
        L[i-2]+=1
        L[i-1]+=1
        L[i]+=1
        cans+=1
if sum(map(lambda x: x%3, L))==0:
    ans=min(cans, ans)

L=l.copy()
cans=0
for i in range(2, n):
    if L[i-2]%3==0:
        L[i-2]+=1
        L[i-1]+=1
        L[i]+=1
        cans+=1
    elif L[i-2]%3==1:
        continue
    else:
        L[i-2]+=2
        L[i-1]+=2
        L[i]+=2
        cans+=2
if all(map(lambda x: x%3==1, L)):
    ans=min(cans, ans)

L=l.copy()
cans=0
for i in range(2, n):
    if L[i-2]%3==0:
        L[i-2]+=2
        L[i-1]+=2
        L[i]+=2
        cans+=2
    elif L[i-2]%3==1:
        L[i-2]+=1
        L[i-1]+=1
        L[i]+=1
        cans+=1
    else:
        continue
if all(map(lambda x: x%3==2, L)):
    ans=min(cans, ans)

if ans==10**9:
    print(-1)
else:
    print(ans)
