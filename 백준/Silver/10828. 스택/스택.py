import sys
input=sys.stdin.readline

N=int(input())
stack=[]
for _ in range(N):
    order= input().strip()
    if len(order) > 5 and order[4]==" ":
        stack.append(int(order[5:]))
    elif order=="top":
        print(stack[-1] if len(stack)!=0 else -1) 
    elif order=="pop":
        print(stack.pop() if len(stack)!=0 else -1) 
    elif order=="empty":
        print(0 if len(stack)!=0 else 1) 
    elif order=="size":
        print(len(stack))