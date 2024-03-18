import sys
from bisect import bisect_left, bisect_right
from math import inf
sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

class SegmentTree:
    def __init__(self, x):
        self.m = len(x)
        self.v = [0] * (self.m * 4)
        self.info = x
        self.make_tree(0, self.m - 1, 1)

    def make_tree(self, start, end, i):
        if start == end:
            self.v[i] = start
        else:
            mid = (start + end) // 2
            left = self.make_tree(start, mid, i * 2)
            right = self.make_tree(mid + 1, end, i * 2 + 1)
            if self.info[left] <= self.info[right]: #minimum
                self.v[i] = left
            else:
                self.v[i] = right
        return self.v[i]

    def find(self, x, y):
        if x<0: #범위에 맞게 수정
            return 0
        return self._find(x, y, 0, self.m - 1, 1)

    def _find(self, x, y, start, end, i):
        if y < start or x > end:
            return -1
        if x <= start and end <= y:
            return self.v[i]
        mid = (start + end) // 2
        left = self._find(x, y, start, mid, i * 2)
        right = self._find(x, y, mid + 1, end, i * 2 + 1)
        if left == -1:
            return right
        elif right == -1:
            return left
        else:
            return left if self.info[left] <= self.info[right] else right #minimum

    def get(self, x, y):
        if x<0: #범위에 맞게 수정
            return 0
        min_index = self.find(x, y)
        return self.info[min_index]

    def insert(self, index, value):
        self._insert(index, value, 0, self.m - 1, 1)

    def _insert(self, index, value, start, end, i):
        if index < start or index > end:
            return
        if start == end == index:
            self.info[index] = min(self.info[index], value)
            self.v[i] = index
            return
        mid = (start + end) // 2
        self._insert(index, value, start, mid, i * 2)
        self._insert(index, value, mid + 1, end, i * 2 + 1)
        if self.info[self.v[i * 2]] <= self.info[self.v[i * 2 + 1]]:
            self.v[i] = self.v[i * 2]
        else:
            self.v[i] = self.v[i * 2 + 1]

    def init(self, x):
        self.v = [x] * (self.m * 4)

n, k=ints()
dp=[inf]*(k+5); dp[-1]=0
tree=SegmentTree(dp)
arr=[]
arr2=[]
sec=[0]*k

for i in range(k):
    x, r, c=ints()
    arr.append(x)
    arr2.append((x-r, x+r, c))
arr.sort()
for i in range(k):
    l, r, c=arr2[i]
    l=bisect_left(arr, l)
    r=bisect_right(arr, r)-1
    sec[i]=l, r, c
sec.sort(key=lambda x: (x[1], x[0]))

for i in range(k):
    l, r, c=sec[i]
    ans=tree.get(l-1, r)+c
    tree.insert(r, ans)
print(tree.info[k-1])
