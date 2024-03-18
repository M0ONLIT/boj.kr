from math import sqrt
n=int(input())
if n<4:
    print(0)
    exit()
sq=int(sqrt(n))
z=(n-sq**2)
if z>sq:
    one, two=z-sq, sq
else:
    one, two=0, z

def k(x):
    return x*(x-1)//2

ans=0
for i in range(1, sq):
    ans+=i**2
print(ans+k(one)+k(two))
