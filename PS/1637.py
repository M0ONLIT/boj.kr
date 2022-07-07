import sys
input=sys.stdin.readline
n=int(input())
a=[tuple(map(int, input().split())) for i in range(n)]

def counting(g, x):
    a, c, b=x
    k=(c-a)//b
    start, mid, end=0, 0, k
    while start<end:
        mid=(start+end)//2
        if a+mid*b<g[0]:
            start=mid+1
        else:
            end=mid
    ans0=start
    start, mid, end=0, 0, k
    while start<end:
        mid=(start+end)//2+1
        if a+mid*b>g[1]:
            end=mid-1
        else:
            start=mid
    ans1=start
    if ans1-ans0==0:
        return g[0]<=a+ans1*b<=g[1]
    else:
        return ans1-ans0+1
t=0
start, end=1, 2147483647
while start<end:
    mid=(start+end)//2
    g1=start, mid
    g2=mid+1, end
    p0=p1=0
    for i in a:
        p0+=counting(g1, i)
        p1+=counting(g2, i)
    #print(start, mid, end, p0, p1)
    if p0%2:
        ans=p0, mid
        end=mid
    elif p1%2:
        ans=p1, mid+1
        start=mid+1
    else:
        t=1
        break
if t: print('NOTHING')
else: print(*ans[::-1])
