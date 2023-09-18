import sys
import queue
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

P=10**9+7
n, m, k=ints()
dp=[[-1]*1000 for i in range(m)]
nums=[0]*10
tenth=[0]*m
tenth[0]=1
for i in range(1, m):
    tenth[i]=tenth[i-1]*10%k

arr=ints()
for i in arr:
    nums[i]=1

def f(x, per):
    if x==0:
        return per==0
    if dp[x][per]!=-1:
        return dp[x][per]
    ans=0
    for i in arr:
        ans+=f(x-1, (per+tenth[x-1]*i)%k)
        ans%=P
    dp[x][per]=ans
    return ans

ans=0
for i in arr:
    if i==0: continue
    ans+=f(m-1, tenth[m-1]*i%k)
    ans%=P
print(ans)
