from collections import deque
import sys

N, M=map(int, sys.stdin.readline().split())

queue=deque([i for i in range(1,N+1)])

rear=0

result=[]

while queue:
    rear=(rear+(M-1))%N
    result.append(queue[rear])
    queue.remove(queue[rear])
    N-=1

print('<', end='')
print(*result, sep=', ', end='')
print('>')