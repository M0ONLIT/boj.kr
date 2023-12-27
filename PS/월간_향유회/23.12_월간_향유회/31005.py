import sys
from math import *
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n, m=ints()
arr=ints()

while m>0 and arr:
    s=sum(arr)
    m%=s
    new=[]
    for i in arr:
        if i<=m:
            m-=i
            new.append(i)
    arr=new
print(m)
