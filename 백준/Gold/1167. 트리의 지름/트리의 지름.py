import sys
input=sys.stdin.readline

def DFS(i, temp):
    for x,y in graph[i]:
        if visited[x]==-1:
            visited[x]=temp+y
            DFS(x, temp+y)

N=int(input())
result=0
graph=[[] for _ in range(N+1)]

for i in range(N):
    arr=list(map(int, input().split()))
    j=1
    while arr[1]!=-1 and arr[j]!=-1:
        graph[arr[0]].append([arr[j], arr[j+1]])
        j+=2

visited=[-1]*(N+1)
visited[1]=0
DFS(1, 0)

start=visited.index(max(visited))
visited=[-1]*(N+1)
visited[start]=0
DFS(start, 0)

print(max(visited))