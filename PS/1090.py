n=int(input())
l=[tuple(map(int, input().split())) for i in range(n)]
inf=float('inf')
ans=[inf]*(n)
def dis(x1, y1, x2, y2):
    return abs(x1-x2)+abs(y1-y2)
for i in range(n):
    for j in range(n):
        x, y=l[i][0], l[j][1]
        a=sorted([dis(x, y, *l[k]) for k in range(n)])
        s=0
        for k in range(n):
            s+=a[k]
            ans[k]=min(ans[k], s)
print(*ans)
