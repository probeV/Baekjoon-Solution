X=[]
Y=[]
for i in range(0,3):
    X1, Y1=input().split()
    X.append(X1)
    Y.append(Y1)
X.sort()
Y.sort()
if X[0]==X[1]:
    print(X[2], end=' ')
elif X[1]==X[2]:
    print(X[0], end=' ')
if Y[0]==Y[1]:
    print(Y[2])
elif Y[1]==Y[2]:
    print(Y[0])
