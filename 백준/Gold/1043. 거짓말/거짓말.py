import sys

N, M=map(int, sys.stdin.readline().split())

A=list(map(int, sys.stdin.readline().split()))

true=set()
visited=[[]for i in range(M+1)]
connected={}

def insert(A, B):
    if A in connected:
        connected[A].append(B)
    else:
        connected[A]=[B]

def update_true(x):
    true.add(x)
    temp=connected.get(x)
    if not temp: return
    for i in temp:
        if i not in true:
            update_true(i)

if len(A)!=1:
    true=true | set(A[1:])
    
for i in range(1,M+1):
    A=list(map(int, sys.stdin.readline().split()))
    visited[i]=visited[i] + A[1:]
    if len(visited[i])!=1:
        for _ in range(len(visited[i])-1):
            n1=visited[i][_]
            n2=visited[i][_+1]
            insert(n1, n2)
            insert(n2, n1)
 
temp=list(true)

for i in temp: 
    update_true(i)

result=0

for i in range(1,M+1):
    if not set(visited[i]) & true:
        result+=1

print(result)