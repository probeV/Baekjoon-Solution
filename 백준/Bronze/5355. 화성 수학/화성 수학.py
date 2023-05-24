N=int(input())
for k in range(0,N):
    A=tuple(input().split())
    result=float(A[0])
    for i in range(1,len(A)):
        if A[i]=='#':
            result=result-7
        elif A[i]=='%':
            result=result+5
        else:
            result=result*3
    print("%.2f" %result)