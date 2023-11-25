import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

mx=10**6+1
mod1, mod2=2, 10**9+7
dp1=[0]*(mx+1)
dp2=[0]*(mx+1)
dp1[1]=dp2[1]=1
for i in range(2, mx+1):
    dp1[i]=dp1[i-1]
    dp2[i]=dp2[i-1]
    if i%2:
        dp1[i]=dp1[i]*26%mod1
        dp2[i]=dp2[i]*26%mod2

l, u=ints()
ans1=ans2=0
for i in range(l, u+1):
    ans1+=dp1[i]
    ans2+=dp2[i]
    ans1%=mod1
    ans2%=mod2
print('AH'[ans1])
print(ans2)
