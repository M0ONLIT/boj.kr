import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

a, b=ints()
k, x=ints()

ans=0
for i in range(a, b+1):
    if k-x<=i<=x+k:
        ans+=1

print(ans if ans else 'IMPOSSIBLE')
