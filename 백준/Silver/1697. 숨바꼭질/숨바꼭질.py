from collections import deque
import sys
input=sys.stdin.readline

N, K=map(int, input().split())
max=100001
visited=[0]*(100001)
queue=deque([N])
visited[N]=0


def BFS():
    while queue:
        start=queue.popleft()
        if start == K:
            print(visited[start])
            return   
        if start+1 < max and visited[start+1]==0:
            queue.append(start+1)
            visited[start+1]=visited[start]+1
        if start*2 < max and visited[start*2]==0:
            queue.append(start*2)
            visited[start*2]=visited[start]+1
        if start-1 >= 0 and visited[start-1]==0:
            queue.append(start-1)
            visited[start-1]=visited[start]+1

BFS()