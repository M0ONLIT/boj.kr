import sys
input=lambda: sys.stdin.readline().strip()
check1="abcdefghijklmnopqrstuvwxyz"
check2="|&^()"
check3="~"

dic={}
for i in range(1, 11):
    dic[i]=[0]*i
    for j in range(2**i):
        for k in range(i):
            dic[i][k] |= ((j>>(i-1-k))&1)<<(2**i-1-j)

for tc in range(int(input())):
    string=''
    chars={}
    for c in input():
        if c in check1:
            chars[c]=0

            string+=c
        elif c in check2+check3:
            string+=c

    for i in range(1, len(string)):
        if string[i-1] in check1+check2[-1] and string[i] in check1+check2[-2]:
            s1, s2=string[:i], string[i:]
            break
        elif string[i-1] in check1+check2[-1] and string[i] in check3:
            s1, s2=string[:i], string[i:]
            break
    else:
        raise

    for fst, snd in zip(chars.keys(), dic[len(chars)]):
        exec(f'{fst}={snd}')

    print(f'Data set {tc+1}: ', end='')
    if eval(s1)==eval(s2):
        print('Equivalent')
    else:
        print('Different')
