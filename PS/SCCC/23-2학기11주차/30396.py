from collections import deque

def board_to_hash(board):
    bit=0
    for i in range(4):
        for j in range(4):
            bit<<=1
            bit|=board[i][j]
    return bit

def hash_to_board(bit):
    board=[[0]*4 for i in range(4)]
    for i in range(4)[::-1]:
        for j in range(4)[::-1]:
            board[i][j]=bit&1
            bit>>=1
    return board

def go_to_knight(bit):
    board=hash_to_board(bit)
    ans=[] #bit
    dx=[-2, -2, -1, -1, 1, 1, 2, 2]
    dy=[1, -1, 2, -2, 2, -2, 1, -1]
    for i in range(4):
        for j in range(4):
            if board[i][j]:
                for k in range(8):
                    if 0<=i+dx[k]<4 and 0<=j+dy[k]<4 and board[i+dx[k]][j+dy[k]]==0:
                        board[i][j], board[i+dx[k]][j+dy[k]]=board[i+dx[k]][j+dy[k]], board[i][j]
                        ans.append(board_to_hash(board))
                        board[i][j], board[i+dx[k]][j+dy[k]]=board[i+dx[k]][j+dy[k]], board[i][j]
    return ans

visit={}
Q=deque()

start=board_to_hash([list(map(int, input())) for i in range(4)])
end=board_to_hash([list(map(int, input())) for i in range(4)])

Q.append((start, 0))
while 1:
    bit, num=Q.popleft()
    if bit==end:
        print(num)
        break
    if visit.get(bit):
        continue
    visit[bit]=1

    for i in go_to_knight(bit):
        Q.append((i, num+1))
