import sys
input=sys.stdin.readline

N=int(input())
arr=[]
for i in range(N):
    arr.append(list(map(int, input().split())))

for i in range(N-1):
    for j in range(len(arr[i+1])):
        if j==0:
            arr[i+1][j]=arr[i+1][j]+arr[i][j]
        elif j==len(arr[i+1])-1:
            arr[i+1][j]=arr[i+1][j]+arr[i][j-1]
        else:
            arr[i+1][j]=arr[i+1][j]+max(arr[i][j-1], arr[i][j])

print(max(arr[N-1]))