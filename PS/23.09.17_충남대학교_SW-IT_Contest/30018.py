import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n=int(input())
a=ints()
b=ints()
ans=0
for i in range(n):
    ans+=abs(a[i]-b[i])
print(ans//2)
