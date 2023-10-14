import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

for tc in range(int(input())):
    n=int(input())
    sets=[]
    u=set()
    for i in range(n):
        s=set(ints()[1:])
        sets.append(s)
        u|=s
    ans=0
    for i in u:
        ss=set()
        for j in sets:
            if i not in j:
                ss|=j
        ans=max(ans, len(ss))
    print(ans)
