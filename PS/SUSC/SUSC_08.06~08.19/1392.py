import sys
from bisect import bisect
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n, q=ints()
a=[int(input()) for i in range(n)]
s=[0]*n
for i in range(1, n):
    s[i]=s[i-1]+a[i-1]

for i in range(q):
    print(bisect(s, int(input())))
