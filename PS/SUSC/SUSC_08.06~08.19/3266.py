import sys
sys.setrecursionlimit(10**5)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

a, b=input(), input()
k=int(input())
if len(a)<len(b): a, b=b, a
#a의 길이가 더 김
dp=[[-1]*2005 for i in range(2005)]

def f(ai, bi):
    if ai==len(a):
        return k*(len(b)-bi)
    elif bi==len(b):
        return k*(len(a)-ai)
    if dp[ai][bi]!=-1:
        return dp[ai][bi]

    ans=min(f(ai+1, bi)+k, f(ai, bi+1)+k, f(ai+1, bi+1)+abs(ord(a[ai])-ord(b[bi])))
    dp[ai][bi]=ans
    return ans;
print(f(0, 0))
