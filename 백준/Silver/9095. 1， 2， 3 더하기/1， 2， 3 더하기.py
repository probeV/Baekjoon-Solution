N=int(input())
for i in range(0,N):
    NUM=int(input())
    N1,N2,N3, temp=1,2,4,0
    if(NUM!=1 and NUM!=2 and NUM!=3):
        for i in range(3,NUM):
            temp=N1
            N1=N2
            N2=N3
            N3=temp+N1+N2
        print(N3)
    elif(NUM==1):
         print(1)
    elif(NUM==2):
         print(2)
    elif(NUM==3):
        print(4)
