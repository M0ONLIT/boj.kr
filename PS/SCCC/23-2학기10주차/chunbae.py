import sys
from math import inf
sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

dp={}
n, k=ints()
sec=[]

def ww(idx, distance):
    if idx==k:
        return 0
    if dp.get((idx, distance))!=None:
        return dp[(idx, distance)]
    ans=inf
    if sec[idx][2]<=distance:
        if distance<sec[idx][1]:
            ans=min(ww(idx+1, sec[idx][1])+sec[idx][3], ans)
        ans=min(ww(idx+1, distance), ans)
    else:
        ans=min(ww(idx+1, sec[idx][1])+sec[idx][3], ans)
    dp[(idx, distance)]=ans
    return ans

for i in range(k):
    x, r, c=ints()
    sec.append((x-r, x+r, x, c))
sec.sort()

print(ww(0, 0))
