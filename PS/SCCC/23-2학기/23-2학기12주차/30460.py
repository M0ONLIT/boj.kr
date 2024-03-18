import sys
sys.setrecursionlimit(10**6)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
inf=float('inf')

n=Int()
a=ints()
dp=[[0]*4 for i in range(n)]
visit=[[0]*4 for i in range(n)]

def ww(idx, k):
    if idx==n:
        return 0
    if visit[idx][k]:
        return dp[idx][k]
    visit[idx][k]=1
    if k==0:
        ans=max(ww(idx+1, 0), ww(idx+1, 1))+a[idx]
    elif k<=2:
        ans=ww(idx+1, k+1)+a[idx]*2
    else:
        ans=max(ww(idx+1, 0), ww(idx+1, 1))+a[idx]*2
    dp[idx][k]=ans

    return dp[idx][k]

print(max(ww(0, 0), ww(0, 1)))
