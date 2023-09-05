import sys
input=sys.stdin.readline
ints=lambda: list(map(int, input().split()))

n, k=ints()
l=[[]for i in range(11)]
for i in range(n):
    x, y=ints()
    l[x-1].append(y)

def yee(x):
    arr=l[x]
    if not arr:
        return 0
    start=0
    cpy=end=max(arr)

    while start<end:
        mid=(start+end)//2+1
        ans=sum([max(0, mid-cpy+i) for i in arr])
        if ans>k:
            end=mid-1
        else:
            start=mid

    return cpy-start

ans=0
for i in range(11):
    ans+=yee(i)
    #print(y(l[i]))
print(ans)
