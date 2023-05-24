N, new, P = map(int, input().split())

if N==0:
    print(1)
else:
    score = list(map(int, input().split()))
    if N==P and score[-1] >=new:
        print(-1)
    else:
        res = N+1
        for i in range(N):
            if score[i] <= new:
                res=i+1
                break
        print(res)