mod=10**9+7
def POW(x, k):
    if k==0:
        return 1
    if k%2:
        ans=x*POW(x, k-1)
    else:
        ans=POW(x, k//2)**2
    return ans%mod
mod2=POW(2, mod-2)

n, k=map(int, input().split())

x=[0]*(k+1)
y=[0]*(k+1)
x[0], y[0]=n, n-1
for i in range(k):
    x[i+1]=x[i]*y[i]*mod2%mod
    y[i+1]=2*(y[i]-1)%mod
print(x[k])
