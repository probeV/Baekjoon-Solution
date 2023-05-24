from collections import deque

M,N,k=map(int, input().split())
Box=[[True for i in range(0,N)] for j in range(0,M)]
root=[]
dx = [0,0,-1,1]
dy = [-1,1,0,0]
queue = deque()
w=[]

for i in range(0,k):
    x1,y1,x2,y2=map(int, input().split())
    for j in range(x1,x2):
        for k in range(M-y2,M-y1):
            Box[k][j]=False
  

for x in range(0,N):
    for y in range(0,M):
        if Box[y][x]==True:
            queue.append([y,x])
            Box[y][x]=False
            width=1
            while queue:
                y,x=queue.popleft()
                for k in range(4):
                    x1, y1 = x+dx[k], y+dy[k]
                    if 0<=x1<N and 0<=y1<M and Box[y1][x1] == True:
                        Box[y1][x1]=False
                        width+=1
                        queue.append([y1,x1])

            w.append(width)  
 
print(len(w))
w.sort()
for i in range(len(w)):
    print(w[i], end=" ")
