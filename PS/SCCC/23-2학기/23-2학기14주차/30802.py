import sys
from math import *
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
a=ints()
t, p=ints()
print(sum(ceil(i/t) for i in a))
print(*divmod(n, p))
