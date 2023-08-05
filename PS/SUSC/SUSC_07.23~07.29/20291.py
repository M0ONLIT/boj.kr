import sys

input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

dic={}
for _ in range(int(input())):
    a, b=input().split('.')
    dic[b]=dic.get(b, 0)+1
for i in sorted(dic.items()): print(*i)
