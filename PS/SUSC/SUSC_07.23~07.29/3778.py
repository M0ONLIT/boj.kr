import sys

input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

s='abcdefghijklmnopqrstuvwxyz'
dic1, dic2={}, {}
for _ in range(int(input())):
    dic1, dic2={}, {}
    x, y=input(), input()
    for i in x:
        dic1[i]=dic1.get(i, 0)+1
    for i in y:
        dic2[i]=dic2.get(i, 0)+1
    ans=0
    for i in s:
        ans+=abs(dic1.get(i, 0)-dic2.get(i, 0))
    print(f"Case #{_+1}: {ans}")
