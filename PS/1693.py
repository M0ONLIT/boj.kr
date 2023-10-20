import sys
sys.setrecursionlimit(10**6)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

dp=[[0]*20 for i in range(100005)]
dps=[0]*100005

def dfs(node, color, mom): #mom은 부모노드
    if dp[node][color]:
        return dp[node][color]
    ans=color+1
    for nxt in graph[node]:
        if nxt==mom:
            continue
        m=float('inf')
        if dps[nxt]!=0:
            m=dps[nxt][1][0] if dps[nxt][0][1]==color else dps[nxt][0][0]
        else:
            fs=[(float('inf'), 0), (float('inf'), 0)] #value, color
            for i in range(20):
                fs=sorted(fs+[(dfs(nxt, i, node), i)])
                if i==color:
                    continue
                m=min(dfs(nxt, i, node), m)
            dps[nxt]=fs
        ans+=m
    dp[node][color]=ans
    return ans

n=Int()
graph={i+1:[] for i in range(n)}
for i in range(n-1):
    a, b=ints()
    graph[a].append(b)
    graph[b].append(a)

m=float('inf')
for i in range(20):
    m=min(dfs(1, i, 0), m)
print(m)
