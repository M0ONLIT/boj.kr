### templete
from bisect import bisect
###

def lis(l):
    ans=[]
    for i in l:
        if not ans:
            ans.append(i)
        elif i>ans[-1]:
            ans.append(i)
        else:
            idx=bisect(ans, i-1)
            ans[idx]=i
    return len(ans)
print(lis(l))
