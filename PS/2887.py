import sys
input=sys.stdin.readline
ints=lambda: map(int, input().split())

n=int(input())
union=list(range(n))
def merge(a, b):
    union[u(a)]=u(b)
    
def u(x):
    if x==union[x]:
        return x
    union[x]=u(union[x])
    return union[x]
    
l=[tuple(ints())+(i,) for i in range(n)]
diss=[]
for i in range(3):
    sort=sorted(l, key=lambda x: x[i])
    for j in range(n-1):
        diss.append((sort[j+1][i]-sort[j][i], sort[j][3], sort[j+1][3]))

diss.sort()
limit=ptr=ans=0
while limit<n-1:
    d, x, y=diss[ptr]
    if u(x)==u(y):
        pass
    else:
        merge(x, y)
        ans+=d
        limit+=1
    ptr+=1
print(ans)
