import sys
from collections import defaultdict
from math import *
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

while (n:=Int())!=-1:
    ans=1
    arr=[1]
    for i in range(2, int(sqrt(n))+1):
        if n%i==0:
            if i==n//i:
                ans+=i
                arr.append(i)
            else:
                ans+=i+n//i
                arr.extend([i, n//i])
            #print('!', i)
    if ans==n:
        arr.sort()
        print(f'{n} =', ' + '.join(map(str, arr)))
    else:
        print(f'{n} is NOT perfect.')
