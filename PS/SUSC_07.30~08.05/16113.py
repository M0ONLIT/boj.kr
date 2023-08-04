import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

queue=[0]*3
num=[
    [31, 17, 31],
    [0, 31, 0],
    [29, 21, 23],
    [21, 21, 31],
    [7, 4, 31],
    [23, 21, 29],
    [31, 21, 29],
    [1, 1, 31],
    [31, 21, 31],
    [23, 21, 31]
]
'''
for i in num:
    array=[['.']*3 for i in range(5)]
    for idx in range(3):
        for j in range(5):
            if i[idx] & (1<<j):
                array[j][idx]='#'
    for i in array:
        print(''.join(i))
    print()
'''
n=int(input())//5
s=input()
l=[s[i*n:(i+1)*n] for i in range(5)]
for i in range(n):
    bit=0
    for j in range(5)[::-1]:
        bit<<=1
        bit+=l[j][i]=='#'
    queue.pop(0)
    queue.append(bit)
    for idx in range(10):
        if num[idx]==queue:
            print(idx, end='')
if queue[1:]==[0, 31]:
    print(1)
