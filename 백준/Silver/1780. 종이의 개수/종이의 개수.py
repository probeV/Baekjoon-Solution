import sys
input=sys.stdin.readline

def merge(x,y,N):
    temp=inputdata[y][x]

    for j in range(y,y+N):
        for i in range(x,x+N):

            if(temp!=inputdata[j][i]):   
                for tempj in range(3):
                    for tempi in range(3):
                        merge(x+tempi*(N//3),y+tempj*(N//3),N//3)   
                return

    if(temp==-1):   
        result[0]=result[0]+1
    elif(temp==0):
        result[1]=result[1]+1
    elif(temp==1):
        result[2]=result[2]+1


N=int(input())
inputdata=[list(map(int, input().split())) for i in range(N)]
result=[0,0,0]
merge(0,0,N)   
for i in range(3):
    print(result[i])