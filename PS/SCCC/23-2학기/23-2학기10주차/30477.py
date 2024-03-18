import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(float, input().split()))

dic={}
n=int(input())
a=ints()
for i in a:
    dic[i]=dic.get(i, 0)+1
for i in dic:
    if dic[i]%3!=0:
        print('Y')
        break
else:
    print('N')
