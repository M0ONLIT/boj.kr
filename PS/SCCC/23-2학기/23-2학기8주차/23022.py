import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
from queue import PriorityQueue

def solve():
    Q=PriorityQueue()
    n, s=ints()
    arr=sorted(zip(ints(), ints())) #arr[i][0] - t, [1] - v
    ptr=ans=0
    while ptr<n or Q.qsize()>0:
        if Q.qsize()==0 and ptr<n:
            s=max(arr[ptr][0], s)
        while ptr<n and arr[ptr][0]<=s:
            Q.put((-arr[ptr][1], arr[ptr][0]))
            ptr+=1
        if Q.qsize()==0:
            break

        v, t=Q.get()
        ans+=(t-s)*v
        s+=1
    print(ans)

T=Int()
for tc in range(T):
    solve()
