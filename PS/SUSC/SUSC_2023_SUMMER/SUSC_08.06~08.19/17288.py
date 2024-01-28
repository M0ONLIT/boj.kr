import sys
from bisect import bisect
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

s=list(map(int, input()))
ans=0

for i in range(len(s)-2):
    if s[i]+2==s[i+1]+1==s[i+2]:
        if i==0 or s[i-1]+1!=s[i]:
            if i+3==len(s) or s[i+2]+1!=s[i+3]:
                ans+=1
    if s[i]-2==s[i+1]-1==s[i+2]:
        if i==0 or s[i-1]-1!=s[i]:
            if i+3==len(s) or s[i+2]-1!=s[i+3]:
                ans+=1
print(ans)
