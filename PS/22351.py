a=input()

def LOG(x):
    return len(str(x))
t=0
def f(first, k, index):
    global t
    if t: return
    if index==len(a):
        print(first, k)
        t=1
        return
    #print(k+1, a[index: index+LOG(k+1)])
    if k+1==int(a[index: index+LOG(k+1)]):
        f(first, k+1, index+LOG(k+1))


for i in range(len(a)):
    f(int(a[:i+1]), int(a[:i+1]), i+1)
