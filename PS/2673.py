def check(ix, iy, jx, jy):
    return (ix<jx<iy)+(ix<jy<iy)==1

n=int(input())
l=[sorted(map(int, input().split())) for i in range(n)]
dic={i:[] for i in range(n)}

for i in range(n):
    for j in range(i+1, n):
        if check(*l[i], *l[j]): #겹칠때
            dic[i].append(j)

def ww(bit, index, ans):
    #print(ans)
    if index==n:
        return ans
    if bit&(1<<index):
        return ww(bit, index+1, ans)
    x=ww(bit, index+1, ans)
    for i in dic[index]:
        bit|=(1<<i)
    y=ww(bit, index+1, ans+1)
    return max(x, y)

print(ww(0, 0, 0))

#원래 정석은O(N^3) dp인데 O(2^n) 비트마스킹으로 해결했다
