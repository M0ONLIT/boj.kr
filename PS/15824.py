nanugi=1000000007

dp={}
def pow2(x):
    if x<=1:
        return 2**x
    if dp.get(x)==None:
        dp[x]=pow2(x//2)*pow2((x+1)//2)%nanugi
    return dp[x]

n=int(input())
l=sorted(map(int, input().split()))
ans=0
for i in range(n):
    s, b=i, n-i-1
    ans+=(-pow2(b)+pow2(s))*l[i]
    #print(pow2(b), pow2(s), l[i], ans)
    ans%=nanugi
print(ans)
