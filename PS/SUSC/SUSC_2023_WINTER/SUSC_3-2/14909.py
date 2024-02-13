import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

print(sum(map(lambda x: x>0, ints())))
