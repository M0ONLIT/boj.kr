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
                    i_p=dp[i_p]
                else:
                    i_p+=1
                break
            if i_p==0:
                break
            i_p=dp[i_p-1]
    return ans
