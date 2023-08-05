ints=lambda: list(map(int, input().split()))
l, r, k=ints()
if k>=4:
    if l%2==0:
        print(0)
        print(4)
        print(*list(range(l, l+4)))
    else:
        if l+5<=r:
            print(0)
            print(4)
            print(*list(range(l+1, l+5)))
        else:
            k-=1
if k==3:
    lb=bin(l)[2:]
    m='1'
    t=0
    for i in lb:
        if i=='1' and t==0:
            m+='1'
            t=1
        else:
            m+='0'
    m=int(m, 2)
    if m<=r:
        print(0)
        print(3)
        print(l, m , l^m)
    else:
        k-=1
if k==2:
    if l%2==0:
        print(1)
        print(2)
        print(l, l+1)
    elif l+2<=r:
        print(1)
        print(2)
        print(l+1, l+2)
    elif len(bin(l))<len(bin(r)):
        k-=1
    else:
        print(l^r)
        print(2)
        print(l, r)
if k==1:
    print(l)
    print(1)
    print(l)
