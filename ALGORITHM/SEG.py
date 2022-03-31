
class segment_tree:
    def __init__(self, x):
        self.m=len(x)
        self.v=[0]*2*m
        self.info=x.copy()
        self.make_tree(0, self.m-1, 1)
    def make_tree(self, start, end, i):
        mid=(start+end)//2
        if start==end:
            self.v[i]=self.info[mid] #
            return self.v[i]
        self.v[i]=self.make_tree(start, mid, i*2)+self.make_tree(mid+1, end, i*2+1)
        return self.v[i]
    def find(self, x, y, *args):
        if len(args)==0:
            return self.find(x, y, 0, self.m-1, 1)
        mid=(start+end)//2
        if y<start or end<x:
            return 0 #
        elif x<=start and end<=y:
            return self.v[i] #
        else:
            return self.find(x, y, start, mid, i*2)+self.find(x, y, mid+1, end, i*2+1) #
    def insert(self, index, value, *args):
        if len(args)==0:
            self.insert(index, value, self.m-1, 1)
            return
        mid=(start+end)//2
        if index<start or end<index:
            pass
        elif start==end and mid==index:
            self.v[i]+=value #
        else:
            self.insert(index, value, start, mid, i*2) 
            self.insert(index, value, mid+1, end, i*2+1) 
            self.v[i]=self.v[i*2]+self.v[i*2+1] #
             
