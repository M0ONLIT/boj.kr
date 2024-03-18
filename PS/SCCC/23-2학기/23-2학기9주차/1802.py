import sys
sys.setrecursionlimit(10**8)
def solve(l):
    L=len(l)
    if L==1:
        return 1
    f, b=l[:L//2], l[-(L//2):][::-1]
    return all(map(lambda x: x[0]^x[1], zip(f, b))) and solve(f)


ans=['NO', 'YES']
for tc in range(int(input())):
    s=list(map(int, input()))
    print(ans[solve(s)])
