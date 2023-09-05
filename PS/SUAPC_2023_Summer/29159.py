import sys
input=sys.stdin.readline
ints=lambda: list(map(int, input().split()))
from fractions import Fraction

x1=y1=0
for i in range(4):
    x, y=ints()
    x1+=Fraction(x, 1)
    y1+=Fraction(y, 1)
x1/=4
y1/=4

x2=y2=0
for i in range(4):
    x, y=ints()
    x2+=Fraction(x, 1)
    y2+=Fraction(y, 1)
x2/=4
y2/=4

acc=(y1-y2)/(x1-x2)
print(acc, -x1*acc+y1)
