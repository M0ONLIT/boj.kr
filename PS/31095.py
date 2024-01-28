import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

nanugi=10**9+7
def POW(n, k, mod=nanugi):
    if k==0:
        return 1
    ans=n*POW(n, k-1) if k%2 else POW(n, k//2)**2
    return ans%mod

facto=[0]*5001
facto_inv=[0]*5001

facto[0]=1
for i in range(1, 5001):
    facto[i]=facto[i-1]*i%nanugi
facto_inv[5000]=POW(facto[5000], nanugi-2)
for i in range(5000)[::-1]:
    facto_inv[i]=facto_inv[i+1]*(i+1)%nanugi

def ncr(n, r):
    return facto[n]*facto_inv[n-r]*facto_inv[r]%nanugi

dp=[0]*5005
visit=[0]*5005

def f(x):
    if x==0:
        return 1
    if visit[x]: return dp[x]
    visit[x]=1

    ans=0
    for i in range(x):
        ans+=f(i)*ncr(x, i)
        ans%=nanugi
    dp[x]=ans
    return ans

dp2=[0]*5005
visit2=[0]*5005

def f2(x):
    if visit2[x]: return dp2[x]
    visit2[x]=1
    ans=0
    for i in range(x):
        ans+=f(i)*ncr(x-1, i)
        ans%=nanugi
    dp2[x]=ans
    return ans

for tc in range(Int()):
    n, k=ints()
    print(ncr(n-1, k-1)*f(k-1)*f2(n-k+1)%nanugi)
