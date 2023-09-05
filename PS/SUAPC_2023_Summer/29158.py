def prime_factors(n):
    factors=[]
    while n%2==0:
        factors.append(2)
        n//=2
    i=3
    while i*i<=n:
        while n%i==0:
            factors.append(i)
            n//=i
        i+=2
    if n>1:
        factors.append(n)
    return sorted(factors, reverse=True, key=lambda x: str(x)*20)


n=eval(input())
ans=int(''.join(map(str, prime_factors(n))))

p=q=0
while 2**p<n:
    p+=1
p-=1

while 2**p*3**q<n:
    p-=1
    q+=1
p+=1
q-=1
assert q>=0

ans2=int('3'*q+'2'*p)
#print(ans, ans2)
if n==2:
    print(3)
else:
    print(ans+ans2)
