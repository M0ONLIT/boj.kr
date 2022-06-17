t=input()
p=input()
T, P=len(t), len(p)
dp=[0]*P
ans=[]
for i in range(1, P):
    j=i-1
    while 1:
        if p[i]==p[dp[j]]:
            dp[i]=dp[j]+1
            break
        if j==0:
            break
        j=dp[j-1]
#print(dp)
i_p=0
for i_t in range(T):
    while 1:
        #print(i_t, i_p)
        if t[i_t]==p[i_p]:
            if i_p==P-1:
                ans.append(i_t-P+2)
                i_p=dp[P-1]
            else:
                i_p+=1
            break
        if i_p==0:
            break
        i_p=dp[i_p-1]

print(len(ans))
for i in ans: print(i)
