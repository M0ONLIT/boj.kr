import random, sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

def is_prime(x):
    if x==1: return 0
    i=2
    while i*i<=x:
        if x%i==0:
            return 0
        i+=1
    return 1

n=int(input())

for i in range(100):
    l=set(range(1, n+1))
    p=[]
    check=0
    for j in range(n):
        for k in range(10):
            c=random.choice(list(l))
            if not is_prime(check+c):
                check+=c
                l.remove(c)
                p.append(c)
                break
        else:
            check=-1
            break
    if check!=-1:
        print('YES')
        print(*p)
        break
else:
    print('NO')
