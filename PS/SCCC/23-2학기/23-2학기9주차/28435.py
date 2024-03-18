import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
nanugi=10**9+7
def POW2(k):
    if k==0: return 1
    return POW2(k//2)**2*(1+k%2)%nanugi

dp=[0]*100005

n, k=ints()
a=ints()
for i in a:
    dp[i%k]+=1
ans=1

ans*=dp[0]+1
if k%2==0:
    ans*=dp[k//2]+1
for i in range(1, (k+1)//2):
    ans*=POW2(dp[i])+POW2(dp[k-i])-1
    ans%=nanugi
ans=(ans-(n+1)+nanugi)%nanugi
print(ans)
