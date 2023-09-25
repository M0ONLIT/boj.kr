import sys
from collections import deque
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n, m=ints()
t=ints()
arr=[0]*1000005
for i in t:
    arr[i]=2

def solve():
    ptr=10**8
    for i in range(n-1, -1, -1):
        ptr=min(t[i]-1, ptr)
        while arr[ptr]!=0:
            ptr-=1
            if ptr+m<t[i]:
                return 'fail'
        arr[ptr]=1

    cnt0=cnt1=0
    for i in range(t[-1]+1):
        if arr[i]==0:
            cnt0+=1
        elif arr[i]==1:
            cnt1+=1
        if cnt0<cnt1:
            return 'fail'
    return 'success'

print(solve())
