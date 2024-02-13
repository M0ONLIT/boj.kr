import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
inf=float('inf')
rng=range

n=Int()
s=[ints() for i in rng(n)]
ans=inf

A=[0]*n

def f(i, a): #a는 A의 인원수
    global ans
    if a==n//2:
        teama, teamb=[], []
        for idx in rng(n):
            if A[idx]: teama.append(idx)
            else: teamb.append(idx)
        temp=0
        #print(teama, teamb)
        for i in range(a):
            for j in range(i+1, a):
                temp+=s[teama[i]][teama[j]]+s[teama[j]][teama[i]]
                temp-=s[teamb[i]][teamb[j]]+s[teamb[j]][teamb[i]]
        ans=min(ans, abs(temp))
        return
    if i==n:
        return
    f(i+1, a)
    A[i]=1
    f(i+1, a+1)
    A[i]=0


f(0, 0)
print(ans)
