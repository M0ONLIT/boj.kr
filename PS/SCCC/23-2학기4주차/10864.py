import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

arr=[0]*1005
n, m=ints()
for i in range(m):
    a, b=ints()
    arr[a]+=1
    arr[b]+=1
for i in range(n):
    print(arr[i+1])
