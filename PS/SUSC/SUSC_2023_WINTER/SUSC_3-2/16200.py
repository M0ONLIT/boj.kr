import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
arr=sorted(ints(), reverse=1)
cnt=0
while arr:
    val=arr.pop()
    cnt+=1
    for i in range(val-1):
        if not arr: break
        arr.pop()
print(cnt)
