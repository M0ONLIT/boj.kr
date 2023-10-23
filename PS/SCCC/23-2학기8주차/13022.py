s=input()
w='wolf'
dic={w[i]:i for i in range(4)}
al=0
cur=0
stack=0
while 1:
    if not s:
        break
    stack=0
    for i in s:
        if i==w[al]:
            stack+=1
        else:
            break
    if al==0:
        cur=stack
    else:
        if stack!=cur:
            print(0)
            exit()
    s=s[stack:]
    al+=1
    al%=4
print(int(al==0))
