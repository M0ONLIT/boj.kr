import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
arr=[]
for i in range(n):
    s, e=input().split()
    arr.append((s, -1))
    arr.append((e, 1))
arr.sort()
cnt=ans=0
for string, i in arr:
    cnt-=i
    if ans<cnt:
        anss=string
        ans=cnt
print(anss)
