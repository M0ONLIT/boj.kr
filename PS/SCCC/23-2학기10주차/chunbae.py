import sys
from math import inf
sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

dp={}
n, k=ints()
arr=[]
sec=[]

def ww(idx, distance):
    if idx==k:
        return 0
    if dp.get((idx, distance))!=None:
        return dp[(idx, distance)]
    ans=inf
    if arr[idx]<=distance:
        if distance<sec[idx][1]:
            ans=min(ww(idx+1, sec[idx][1])+sec[idx][2], ans)
        ans=min(ww(idx+1, distance), ans)
    else:
        ans=min(ww(idx+1, sec[idx][1])+sec[idx][2], ans)
    dp[(idx, distance)]=ans
    return ans

for i in range(k):
    x, r, c=ints()
    arr.append(x)
    sec.append((x-r, x+r, c))
arr.sort()
sec.sort()

print(ww(0, 0))
