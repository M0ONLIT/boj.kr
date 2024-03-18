import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

a, b=ints()
ans_l=[]
while 1:
    if a<=0 or b<=0:
        break
    if a==b+1:
        ans_l.append((a, b))
        a=b=0
        break
    else:
        ans_l.append((2, 1))
        a-=2
        b-=1

if a!=0 or b!=0:
    print('NO')
else:
    print('YES')
    print(len(ans_l))
    for i, j in ans_l:
          print('ab'*j+'a')
