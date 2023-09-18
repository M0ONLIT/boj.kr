import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n, m=ints()
ans=0
y=[0]*200005
for i in range(m):
    k, s, e=ints()
    if y[k]<=s:
        ans+=1
        y[k]=e
        print('YES')
    else:
        print('NO')
