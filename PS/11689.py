ans=n=N=int(input())

i=2
while i**2<=n:
    if n%i==0:
        ans=ans*(i-1)//i
        while n%i==0:
            n//=i
    i+=1
if n!=1:
    ans=ans*(n-1)//n
print(ans)

#pypy3
