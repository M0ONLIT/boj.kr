arr=list(range(1, int(input())+1))
while len(arr)!=1:
    arr=arr[1::2]
print(*arr)
