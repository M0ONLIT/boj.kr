import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
from fractions import Fraction

sx, sy, mx, my=ints()
s=Fraction(sy, sx)
m=Fraction(my, mx)

if s>1:
    if m>1:
        print('YES')
    else:
        print('NO')
elif s==1:
    if s==m:
        print('YES')
    else:
        print('NO')
else:
    if m<1:
        print('YES')
    else:
        print('NO')
