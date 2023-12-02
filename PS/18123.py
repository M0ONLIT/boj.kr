import sys
sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

def dfs(tree, s, node, mom):
    ans=1
    for nxt in tree[node]:
        if nxt==mom: continue
        ans+=dfs(tree, s, nxt, node)
    s[node]=ans
    return ans

def find_centroid(tree, s, node, mom): #s는 자신을 루트로 하는 서브트리 노드 개수
    for nxt in tree[node]:
        if nxt==mom: continue
        if s[nxt]>n/2:
            return find_centroid(tree, s, nxt, node)
    return node

def check_centroid(tree, s, node):
    for nxt in tree[node]:
        if s[node]>s[nxt]:
            value=s[nxt]
        else:
            value=s[0]-s[node]
        if value>s[0]//2:
            return 0
    return 1

def find_second_centroid(tree, s, centroid):
    for nxt in tree[centroid]:
        if s[centroid]>s[nxt]:
            if check_centroid(tree, s, nxt):
                return nxt
    return -1 #존재하지 않음

def input_tree(n):
    tree=[[] for i in range(n)]
    for i in range(n-1):
        a, b=ints()
        tree[a].append(b)
        tree[b].append(a)
    return tree

def power(n, k, mod):
    if k==0: return 1
    if k%2:
        return n*power(n, k-1, mod)%mod
    else:
        return power(n, k//2, mod)**2%mod

def tree_to_hash(tree, node, mom=-1):
    sons=[]
    for nxt in tree[node]:
        if nxt!=mom:
            sons.append(tree_to_hash(tree, nxt, node))
    sons.sort()

    return '1'+''.join(sons)+'0'

ans=set()
testcase=Int()
for tc in range(testcase):
    n=Int()
    tree=input_tree(n)
    s=[0]*n
    dfs(tree, s, 0, -1)
    root=find_centroid(tree, s, 0, -1)
    second_root=find_second_centroid(tree, s, root)
    value=tree_to_hash(tree, root)
    if second_root!=-1:
        value=min(tree_to_hash(tree, second_root), value)
    ans.add(value)
print(len(ans))
