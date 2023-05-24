import sys
input=sys.stdin.readline

Co=input()
Target=input()

result=[[0]*(len(Target)) for _ in range(len(Co))]

for i in range(1,len(Co)):
    for j in range(1, len(Target)):
        if Co[i-1]==Target[j-1]:
            result[i][j]=1+result[i-1][j-1]
        else:
            result[i][j]=max(result[i-1][j],result[i][j-1])

print(result[-1][-1])
        