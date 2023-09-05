dic={'A':4, 'B':3, 'C':2, 'D':1, 'F':0}

def sc(s):
    ans=dic[s[0]]
    if s[-1]=='+':
        ans+=0.5
    return ans

ans=0.
cnt=0
s=input()
for i in s:
    if i=='+':
        ans+=.5
    else:
        ans+=dic[i]
        cnt+=1
print(ans/cnt)
