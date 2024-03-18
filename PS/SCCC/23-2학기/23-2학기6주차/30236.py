import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

for i in range(int(input())):
    n=int(input())
    a=ints()
    ans=0

    for i in range(n):
        if a[i]==i+1+ans:
            ans+=1
    print(n+ans)
