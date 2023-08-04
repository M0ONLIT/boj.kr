import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

class turtle:
    def __init__(self):
        self.x=self.y=0
        self.minx=self.maxx=0
        self.miny=self.maxy=0
        self.angle=(1, 0)
    def update(self):
        self.minx=min(self.minx, self.x)
        self.maxx=max(self.maxx, self.x)
        self.miny=min(self.miny, self.y)
        self.maxy=max(self.maxy, self.y)
    def move(self, c):
        if c=='F':
            self.x+=self.angle[0]
            self.y+=self.angle[1]
            self.update()
        elif c=='B':
            self.x-=self.angle[0]
            self.y-=self.angle[1]
            self.update()
        elif c=='L':
            p, q=self.angle
            self.angle=(-q, p)
        elif c=='R':
            p, q=self.angle
            self.angle=(q, -p)
    def answer(self):
        return (self.maxx-self.minx)*(self.maxy-self.miny)

for testcase in range(int(input())):
    s=input()
    T=turtle()
    for i in s:
        T.move(i)
    print(T.answer())
