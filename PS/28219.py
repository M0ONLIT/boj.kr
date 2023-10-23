import sys
sys.setrecursionlimit(10**8)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

def input_tree(n):
    tree=[[] for i in range(n+1)]
    for i in range(n-1):
        a, b=ints()
        tree[a].append(b)
        tree[b].append(a)
    return tree

ans=0
#visit=[0]*(n+1)
def dfs(node, mom):
    global ans
    arr=[]
    for i in tree[node]:
        if i!=mom:
            arr.append(dfs(i, node))
    arr.sort(reverse=1)

    if len(arr)==0:
        return 1
    elif len(arr)==1:
        if arr[0]>=k:
            ans+=1
            return 0
        return arr[0]+1
    else:
        if arr[0]+arr[1]>=k:
            ans+=1
            return 0
        return arr[0]+1

n, k=ints()
tree=input_tree(n)

dfs(1, None)
print(ans)
