height=[]

for i in range(9):
    temp=int(input())
    height.append(temp)

total=sum(height)

for i in range(9):
    for j in range(i+1,9):
        if total-height[i]-height[j]==100:
            x,y=height[i], height[j]
            height.remove(x)
            height.remove(y)
            height=sorted(height)
            for i in range(7):
                print(height[i])
            exit()
