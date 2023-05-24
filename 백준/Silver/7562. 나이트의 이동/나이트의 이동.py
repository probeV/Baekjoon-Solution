from collections import deque

dxy=[[-2,-1],[-2,1],[2,-1],[2,1],[-1,-2],[-1,2],[1,-2],[1,2]]

N=int(input())

def BFS():

    while queue:
        x,y=queue.popleft()
        if [x,y]==destination:
            return result[x][y]-1
        for i in range(8):
            dx,dy=dxy[i]
            dx,dy=x+dx,y+dy
            if [dx,dy]==destination:
                return result[x][y]
            elif dx>=0 and dy>=0 and dx<l and dy<l and result[dx][dy]==0:
                queue.append([dx,dy])
                result[dx][dy]=result[x][y]+1


for _ in range(N):
    # global destination, l
    l=int(input())
    startX, startY=map(int, input().split())
    destination=list(map(int, input().split()))

    result=[[0] * l for i in range(l)]
    result[startX][startY]=1
    queue=deque([[startX, startY]])

    print(BFS())
