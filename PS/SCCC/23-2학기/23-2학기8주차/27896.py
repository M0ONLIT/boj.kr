import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
from queue import PriorityQueue

n, m=ints()
arr=ints()
Q=PriorityQueue()
s=ans=0
for i in arr:
    s+=i
    Q.put(-i)
    if s>=m:
        ans+=1
        s+=2*Q.get()
print(ans)
