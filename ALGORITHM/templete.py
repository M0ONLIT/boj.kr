import sys
input=io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
from fractions import Fraction
from queue import PriorityQueue
from collections import deque
from bisect import bisect
from math import *
sys.setrecursionlimit(10**8)

from decimal import *
getcontext().prec=28
d=Decimal

def POW(n, k, mod=mod):
    if k==0:
        return 1
    ans=n*POW(n, k-1) if k%2 else POW(n, k//2)**2
    return ans%mod

def coordinate_compression(lst): #좌표압축
    sorted_list=sorted(list(set(lst)))
    compression_dict={value: index+1 for index, value in enumerate(sorted_list)}
    compressed=[compression_dict[value] for value in lst]
    return compressed

def changetype(value, *types):
    for i in range(min(len(value), len(types))):
        value[i]=types[i](value[i])
    return value

def nearby4(y, x, n=n, m=m, dy=[0, 0, 1, -1], dx=[1, -1, 0, 0]):
    ans=[]
    for i in range(4):
        if 0<=y+dy[i]<n and 0<=x+dx[i]<m:
            ans.append((y+dy[i], x+dx[i]))
    return ans

def nearby8(y, x, n=n, m=m, dy=[-1, 0, 1], dx=[-1, 0, 1]):
    ans=[]
    for i in dy:
        for j in dx:
            if i==j==0:
                continue
            if 0<=y+dy[i]<n and 0<=x+dx[j]<m:
                ans.append((y+dy[i], x+dx[j]))
    return ans

def input_graph(n, m):
    graph=[[] for i in range(n+1)]
    for i in range(m):
        a, b=ints()
        graph[a].append(b)
        graph[b].append(a)
    return graph

def input_tree(n):
    tree=[[] for i in range(n+1)]
    for i in range(n-1):
        a, b=ints()
        tree[a].append(b)
        tree[b].append(a)
    return tree
