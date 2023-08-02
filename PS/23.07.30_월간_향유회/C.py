import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
from fractions import Fraction

sx, sy, mx, my=ints()
s=Fraction(sy, sx)
m=Fraction(my, mx)

if s>m:
    if m<=1:
        print('NO')
    else:
        print('YES')
else:
    if m>=1:
        print('NO')
    else:
        print('YES')
