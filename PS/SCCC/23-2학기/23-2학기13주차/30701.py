import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
from queue import PriorityQueue

n, d=ints()
pqs=en, eq=PriorityQueue(), PriorityQueue()
for i in range(n):
    a, b=ints()
    pqs[a-1].put(b)

cnt=0
while en.qsize():
    e=en.get()
    while d<=e:
        if eq.qsize()==0:
            break
        d*=eq.get()
        cnt+=1
    if d<=e:
        break
    d+=e
    cnt+=1
print(cnt+eq.qsize())
