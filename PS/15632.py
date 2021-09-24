O1, O2, O3=[list(map(float, input().split())) for i in range(3)]
O1[2]**=2; O2[2]**=2; O3[2]**=2
def check(x, y, O): #안 겹치면1, 겹치면0
    return (O[0]-x)**2+(O[1]-y)**2 > O[2]

count=21000
total=count**2
ratio=0
c=50/count
for i in range(count):
    i=i*100/count+c
    for j in range(count):
        j=j*100/count+c
        ratio+=1^(check(i, j, O1) & check(i, j, O2) & check(i, j, O3))
print(ratio*10000/total)
#pypy3
