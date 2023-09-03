dic={'A':4, 'B':3, 'C':2, 'D':1, 'F':0}

def sc(s):
    ans=dic[s[0]]
    if s[-1]=='+'
    ans+=0.5
    return ans

ans=0
cnt=0
s=input()
ptr=0
while ptr<len(s):
    if ptr==n-1:
        ans+=sc(s[n-1])
        cnt+=1
        ptr+=1
    elif s[ptr+1]=='+':
        ans+=sc(s[ptr:ptr+2])
        cnt+=1
        ptr+=2
    else:
        ans+=sc(s[n-1])
        cnt+=1
        ptr+=1
print(ans/cnt)
