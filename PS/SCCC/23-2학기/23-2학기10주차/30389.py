from collections import defaultdict

dic=defaultdict(int)
for i in range(int(input())):
    x=input()
    for i in range(len(x)):
        dic[x[i:]]+=1
        dic[x[i:]]%=2
print(sum(dic.values()))
