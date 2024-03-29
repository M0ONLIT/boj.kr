import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

def make_pi(s):
    pi=[0]*len(s)
    idx=0
    for i in range(1, len(s)):
        while 1:
            if s[idx]==s[i]:
                pi[i]=idx+1
                idx+=1
                break
            elif idx==0:
                break
            idx=pi[idx-1]
    return pi

def match(t, p):
    dp=make_pi(p)
    T, P=len(t), len(p)
    ans=[]
    i_p=0
    for i_t in range(T):
        while 1:
            if t[i_t]==p[i_p]:
                if i_p==P-1:
                    ans.append(i_t-P+2)
                else:
                    i_p+=1
                break
            if i_p==0:
                break
            i_p=dp[i_p-1]
    return ans

n=Int()
m=Int()
s=input()
print(len(match(s, 'IO'*n+'I')))
