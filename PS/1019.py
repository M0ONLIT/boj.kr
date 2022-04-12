from math import *
fac=factorial

dp=[0]*10
n=input()
f=lambda n: sum(fac(n)//fac(n-i)//fac(i)*9**(n-i)*i for i in range(1, n+1))
t=0
while n:
    lo=len(str(n))-1
    k=10**lo
    p, q=n[0], n[1:] #몫, 나머지
    for i in range(int(p)):
        if i or t:
            dp[i]+=k
        for j in range(10):
            if i or j or t:
                dp[j]+=f(lo)
            else:
                dp[j]+=9*sum(f(i) for i in range(lo))
    #print(*dp)
    dp[int(p)]+=int(q if q else 0)+1
    n=q
    #print(*dp, '\n')
    t=1

print(*dp)
