s='NESW'
idx=0
for i in range(10):
    idx+=int(input())
print(s[idx%4])
