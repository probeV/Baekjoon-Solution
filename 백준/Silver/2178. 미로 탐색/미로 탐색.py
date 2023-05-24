from collections import deque

N, M= map(int, input().split())
dx=[1,-1,0,0]
dy=[0,0,-1,1]
maze=[]
count=[[0]*M for _ in range(N)]

for i in range (N):
    maze.append(list(input()))

def BFS():
    while queue:
        x,y=queue.popleft()
        if x == N-1 and y== M-1:
            return count[x][y]
        for i in range(4):
            if 0<=x+dx[i]<N and 0<=y+dy[i]<M and count[x+dx[i]][y+dy[i]]==0 and maze[x+dx[i]][y+dy[i]]=='1':
                queue.append([x+dx[i], y+dy[i]])
                count[x+dx[i]][y+dy[i]]=count[x][y]+1





queue=deque([[0,0]])
count[0][0]=1
print(BFS())