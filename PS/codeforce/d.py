#22938
ints=lambda: list(map(int, input().split()))

x1, y1, d1=ints()
x2, y2, d2=ints()
print("YES" if (x1-x2)**2+(y1-y2)**2<(d1+d2)**2 else "NO")

#14593
import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
arr=[]
for i in range(n):
    a, b, c=ints()
    arr.append((-a, b, c, i+1))
arr.sort()
print(arr[0][-1])

#25373
n=int(input())
i=s=0
while s<n:
    i+=1
    s+=i
print(i)

#16200
import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
arr=sorted(ints(), reverse=1)

ans=0
while arr:
    v=arr.pop()
    for _ in range(v-1):
        if not arr:
            break
        arr.pop()
    ans+=1
print(ans)

#10897
import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

nanugi=10**9+7
facto=[1]+[0]*100
for i in range(1, 101): facto[i]=facto[i-1]*i%nanugi

d=Int()
arr=ints()
pvc=0
cur=0
for i in range(d):
    pvc=pvc*(i+1)+arr[i]-1
    cur=sum(facto[:i+1])+pvc
    print(cur)

#25418
import sys
from math import *
sys.setrecursionlimit(10**8)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

a, b=ints()
dp=[0]*(10**6+5)
visit=[0]*(10**6+5)
def f(x):
    if x>b: return inf
    elif x==b: return 0

    if visit[x]: return dp[x]
    visit[x]=1

    dp[x]=1+min(f(x+1), f(x<<1))
    return dp[x]
print(f(a))

#8983
import sys
from bisect import bisect_left
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

def taxi(x1, y1, x2, y2):
    return abs(x1-x2)+abs(y1-y2)

m, n, l=ints()
arr=sorted(ints())
ans=0
for i in range(m):
    x, y=ints()
    idx=bisect_left(arr, x)

    if (idx!=0 and taxi(x, y, arr[idx-1], 0)<=l) or (idx!=n and taxi(x, y, arr[idx], 0)<=l):
        ans+=1
print(ans)

#20927(cpp)
