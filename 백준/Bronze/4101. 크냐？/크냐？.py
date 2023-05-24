N1, N2=1,1
while N1!=0 and N2!=0:
    N1, N2=map(int, input().split())
    if N1>N2:
        print("Yes")
    elif N1==0 and N2==0:
        pass
    elif N1<=N2:
        print("No")