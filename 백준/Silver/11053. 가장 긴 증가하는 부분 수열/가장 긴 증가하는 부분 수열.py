import sys
input=sys.stdin.readline

N=int(input())

arr=list(map(int, input().split()))
length=[1] * N
for i in range(N-2,-1,-1):
    for j in range(i,N):
        if arr[i] < arr[j] and length[i]-1 < length[j]:
            length[i]=length[j]+1
        
print(max(length))