import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

a, b=ints()
print(min(2*a-1, 2*b+1))
