n, l=map(int, input().split())
a=set(filter(lambda x: x.count('4')+x.count('7')==len(x), input().split()))
dp={(i, j):0 for i in [4, 7] for j in [4, 7]}
dic={}
nanugi=1234567891
for i in a:
    dp[(int(i[0]), int(i[-1]))]+=1

def f(x, y, l): #x로 시작해서 y로 끝나는 길이 l의 수열
    if l==0: return x==y
    if l==1: return dp[(x, y)]
    if dic.get((x, y, l))==None:
        dic[(x, y, l)]=sum((f(x, i, (l-1)//2)*dp[(i, j)]*f(j, y, l//2) for i in [4, 7] for j in [4, 7]))%nanugi
    return dic[(x, y, l)]
    
print(sum((f(i, j, l) for i in [4, 7] for j in [4, 7]))%nanugi)
