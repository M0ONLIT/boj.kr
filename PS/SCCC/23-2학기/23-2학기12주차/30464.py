import sys
sys.setrecursionlimit(10**6)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
inf=float('inf')

n=Int()
a=ints()
dp=[[0]*3 for i in range(n)]
visit=[[0]*3 for i in range(n)]

def ww(idx, op): #0, 1, 2
    if idx==n-1:
        return 0
    if a[idx]==0:
        return -1
    if visit[idx][op]:
        return dp[idx][op]
    visit[idx][op]=1

    ans=-1
    if op==0:
        if idx+a[idx]<n:
            ans=max(ww(idx+a[idx], 0), ans)
        if idx-a[idx]>=0:
            ans=max(ww(idx-a[idx], 1), ans)
    elif op==1:
        if idx+a[idx]<n:
            ans=max(ww(idx+a[idx], 2), ans)
        if idx-a[idx]>=0:
            ans=max(ww(idx-a[idx], 1), ans)
    else:
        if idx+a[idx]<n:
            ans=max(ww(idx+a[idx], 2), ans)
    if ans!=-1:
        ans+=1
    dp[idx][op]=ans
    return ans
print(ww(0, 0))
