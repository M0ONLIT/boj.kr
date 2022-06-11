import sys
sys.setrecursionlimit(10**8)
input=sys.stdin.readline
n,m=map(int, input().split())
union=list(range(n+1))
visit=[0]*(n+1)
graph=[[] for i in range(n+1)]
graphr=[[] for i in range(n+1)]
stack=[]
equal=[]
equalx=[]
ans='consistent'

def u(x):
    if x==union[x]:
        return x
    union[x]=u(union[x])
    return union[x]
def merge(a, b):
    a, b=sorted((a, b))
    union[u(a)]=u(b)
    
def w(node):
    if visit[node]:
        return
    visit[node]=1
    for i in graph[node]:
        w(i)
    stack.append(node)
    
for i in range(m):
    a, b, c=input().split()
    a, c=int(a), int(c)
    if b=='=':
        equal.append((a, c))
    else:
        equalx.append((a, b, c))
 
for a, b in equal:
    merge(a, b)
for a, b, c in equalx:
    a, c=u(a), u(c)
    if b=='<':
        a, c=c, a
    graph[a].append(c)
    graphr[c].append(a)

for i in range(n):
    w(i)

visit=[0]*(n+1)
while stack:
    node=stack.pop()
    visit[node]=1
    for i in graphr[node]:
        if visit[i]==0 or u(node)==u(i):
            ans='inconsistent'
print(ans)

'''
union find로 합친후 사이클의 존재성을 확인한다.
그런데 난이도 기여에 위상정렬에 대한 언급이 나옴.
난 코사라주 알고리즘으로 SCC쌍이 있는지 확인하는 방법으로 풀었는데
너무 어렵게 풀었나 보다.
'''
