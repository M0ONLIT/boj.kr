import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

dic={'U':(0, 1), 'R':(1, 0), 'L':(-1, 0), 'D':(0, -1)}

n, m=ints()
s=input()
x=y=0
for _ in range(min(2000, m)):
    for i in s:
        dx, dy=dic[i]
        x+=dx; y+=dy
        if x==0 and y==0:
            print('YES')
            exit()
print('NO')
