s='abcdefghijklmnopqrstuvwxyz'.upper()
d={i:0 for i in s}
ans=1000
input()
for i in input():
    d[i]+=1
d['E']//=2
d['R']//=2
for i in 'BRONZESILVER':
    ans=min(d[i], ans)
print(ans)
