import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

for tc in range(int(input())):
    n=int(input())
    l=ints()
    a=[]
    for i in l:
        if a==[]:
            a.append(i)
        elif i>0:
            if a[-1]<0 and a[-1]+i>0:
                a[-1]+=i
            else:
                a.append(i)

        elif i==0:
            pass
        else:
            if a[-1]+i>0 or a[-1]<0:
                a[-1]+=i
            else:
                a.append(i)
    plus=minus=0
    for i in a:
        plus+=i>0
        minus+=i<0
    if plus>minus: print('YES')
    else: print('NO')
