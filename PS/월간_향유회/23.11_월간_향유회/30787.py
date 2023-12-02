import sys
sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

mod=10**9+7
def POW(n, k, mod=mod):
    if k==0:
        return 1
    ans=n*POW(n, k-1) if k%2 else POW(n, k//2)**2
    return ans%mod

def t(n):
    if n<0: return 0
    return POW(2, n+1)-1

n, k=ints()
ans1=t(n-k)
ans2=2*(t(n-k)-t(k-1)) if n-k>=k-1 else 0
print((ans1+ans2)%mod)
