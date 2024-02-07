import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
s=list(map(lambda x: x=='P', input().split()))
m, k=ints()
ans=[]
for _ in range(m):
    ans.append(any([s[i-1] for i in ints()]))
print('WP'[all(ans)])
