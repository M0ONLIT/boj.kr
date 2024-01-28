import sys
from math import sqrt
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

for tc in range(Int()):
    s=input()
    n=int(sqrt(len(s))+1e-6)
    arr=[[0]*n for i in range(n)]

    for r in range(n):
        for c in range(n):
            arr[r][c]=s[n*r+c]

    for c in range(n)[::-1]:
        for r in range(n):
            print(arr[r][c], end='')
    print()
