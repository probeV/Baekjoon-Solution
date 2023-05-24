from collections import deque
import sys
input=sys.stdin.readline

L, W = map(int, input().split())
dx=[-1,1,0,0]
dy=[0,0,-1,1]
arr=[]
visited=[[0 for i in range(W)] for i in range(L)]
result=0

for _ in range(L):
    arr.append(list(input().strip()))

def BFS():
    global result
    while queue:
        i,j=queue.popleft()
        for k in range(4):
            x, y=i+dx[k], j+dy[k]
            if 0<=x<W and 0<=y<L and visited[y][x]==0 and arr[y][x]=='L':
                queue.append([x,y])
                visited[y][x]=visited[j][i]+1
                result=max(result,visited[y][x])

for i in range(W):
    for j in range(L):
        if arr[j][i]=='L':
            queue=deque([[i,j]])
            visited[j][i]=1
            BFS()
            visited=[[0 for i in range(W)] for i in range(L)]

print(result-1)
