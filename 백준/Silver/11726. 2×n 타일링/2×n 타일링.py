import sys

N=int(sys.stdin.readline())
N1=1
N2=2

if(N==1):
    print(N1)
elif(N==2):
    print(N2)
else:
    for i in range(2,N):
        temp=N1
        N1=N2
        N2=temp+N1
    print(N2%10007)