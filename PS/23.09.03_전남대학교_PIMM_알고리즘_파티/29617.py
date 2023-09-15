a, b, k=map(int, input().split())
a, b=sorted((a, b))

if k>=0:
    print('First' if a!=b else 'Second')
else:
    if a==b==1:
        print('First')
    elif a==0 and b==1:
        print('Second')
    elif a!=b:
        print('First')
    else:
        if a+1+k>b-1:
            print('First')
        else:
            print('Second')
