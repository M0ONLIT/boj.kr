import sys
from bisect import bisect
from math import inf
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

pow2=lambda x: int(x)**2

def NEXT(n):
    return sum(list(map(pow2, str(n))))

while 1:
    a, b=ints()
    if not a+b:
        break
    print(a, b, end=' ')
    dica={}
    dicb={}
    A=B=0
    cnt=1
    ans=inf
    for i in range(1, 1000):
        dica[a]=min(dica.get(a, inf), i)
        dicb[b]=min(dicb.get(b, inf), i)

        if dica.get(b):
            ans=min(ans, i+dica[b])
        if dicb.get(a):
            ans=min(ans, i+dicb[a])
        a=NEXT(a)
        b=NEXT(b)
    if ans==inf: print(0)
    else: print(ans)
