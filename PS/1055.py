import sys
sys.setrecursionlimit(10**8)

a=input()
string=input()
r=string.count('$')
c=len(string)-r
n=int(input())
p, q=map(int,input().split())
dp=[len(a)]
def ww(start, end, count):
    #print(p, q, start, end, count)
    if q<start or end<p:
        return
    last=start
    if count==0:
        for i in range(len(a)):
            i=a[i]
            if p<=last<=q:
                print(i,end='')
            last+=1
        return

    for i in range(len(string)):
        i=string[i]
        if i=='$':
            if not(q<last or last+dp[count-1]<p):
                ww(last, last+dp[count-1], count-1)
            last+=dp[count-1]
        else:
            if p<=last<=q:
                print(i,end='')
            last+=1
    return

x=len(a)
count=0
if r>1:
    for i in range(n):
        if x>=q:
            break
        x=x*r+c
        dp.append(x)
        count+=1
    ww(1, x, count)
else:
    x+=n*c
    string=string[1:]
    for i in range(p, min(x+1, q+1)):
        if i<=len(a):
            print(a[i-1], end='')
        else:
            print(string[(i-len(a)-1)%len(string)], end='')
for i in range(q+1-max(x+1, p)):
    print('-', end='')
