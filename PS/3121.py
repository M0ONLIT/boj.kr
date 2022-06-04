import sys
sys.setrecursionlimit(10**8)
input=sys.stdin.readline

v, e=map(int, input().split())
graph={i+1:[]  for i in range(v)}
re={i+1:[]  for i in range(v)}

for i in range(e):
    x, y=map(int, input().split())
    graph[x].append(y)
    re[y].append(x)

visit=[0]*(v+1)
a=[]
def ww(node):
    if visit[node]:
        return
    visit[node]=1
    for i in graph[node]:
        ww(i)
    a.append(node)
for i in range(1, v+1):
    ww(i)
#print(a)


ans, p=[], []
visit=[0]*(v+1)
def w(node):
    if visit[node]:
        return
    visit[node]=1
    p.append(node)
    for i in re[node]:
        w(i)
for i in a[::-1]:
    w(i)
    if p:
        ans.append(sorted(p))
        p.clear()
ans.sort()

print(len(ans))
for i in ans:
    print(*i, -1)
'''
코사라주 알고리즘
원리가 이해안됨..
'''
