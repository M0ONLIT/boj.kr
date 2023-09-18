import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

input()
arr=set(input().split())
input()
arr|=set(input().split())
input()
arr-=set(input().split())
input()

s=input().split()
for i in arr:
    new=[]
    for j in s:
        new+=[k for k in j.split(i) if k]
    s=new
print(*s, sep='\n')
