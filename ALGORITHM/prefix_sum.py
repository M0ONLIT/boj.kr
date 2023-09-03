class PrefixSum:
    def __init__(self, arr):
        self.s=[0]
        for num in arr:
            self.s.append(num+self.s[-1])

    def sum(self, x, y):
        return self.s[y+1]-self.s[x]
