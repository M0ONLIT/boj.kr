import sys
from math import inf
sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
def solve(s):
    n=len(s)
    p=[0]*n
    idx=0
    for i in range(1, n):
        while 1:
            if s[idx]==s[i]:
                p[i]=idx+1
                idx+=1
                break
            elif idx==0:
                break
            idx=p[idx-1]
    if n%(n-p[n-1])!=0:
        print(1)
    else:
        print(n//(n-p[n-1]))

while 1:
    s=input()
    if s=='.': break
    solve(s)
