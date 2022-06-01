import sys
input=sys.stdin.readline

def dis(x, y, w, z):
    return (x-w)**2+(y-z)**2
    
def ts(x, l):
    start, end=0, len(l)-1
    while start<end:
        mid1=(2*start+end)//3
        mid2=(start+2*end)//3+1
        if abs(l[mid1]-x)<abs(l[mid2]-x):
            end=mid2-1
        else:
            start=mid1+1
    return start
dic={}
ans=float("inf")
n=int(input())
for i in range(n):
    x, y=map(int, input().split())
    if dic.get(x)==None:
        dic[x]=[]
    dic[x].append(y)
for i in dic:
    dic[i].sort()

l=sorted(dic.items())
for i in range(len(l)):
    x, ys=l[i]
    for j in range(len(ys)):
        y=ys[j]
        if j!=len(ys)-1:
            ans=min(ans, dis(x, y, x, ys[j+1]))
        for k in range(i+1, len(l)):
            xb, ybs=l[k]
            if (xb-x)**2<ans:
                yb=ybs[ts(y, ybs)] #삼진탐색
                ans=min(ans, dis(x, y, xb, yb))
            else:
                break
print(ans)
