result=0
for i in range(1,6):
    N=int(input())
    if N<40:
        N=40
    result=result+N
print((int)(result/5))