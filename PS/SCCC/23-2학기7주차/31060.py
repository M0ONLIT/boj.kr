import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n=int(input())
arr=ints()
a=[0]*n
for i in range(n):
    if i==0: a[i]=arr[i]
    else: a[i]=arr[i]+arr[i-1]
for _ in range(3):
    for i in range(1, n):
        a[i]+=a[i-1]
print(*a)
