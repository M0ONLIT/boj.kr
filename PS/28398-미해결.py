import sys
input=sys.stdin.readline
ints=lambda: list(map(int, input().split()))

n, m=ints()
arr=ints()
visit=[0]*(n+1)
ad=[[] for i in range(n+1)]

ans=0
r=0
prev=None
for i in range(2*n):
    if r==0:
        if visit[arr[i]]:
            ans+=2
        else:
            visit[arr[i]]=1
            ans+=1
            r=not r
    else:
        if visit[arr[i]]:
            if prev==arr[i]:


    prev=arr[i]


for _ in range(m):
