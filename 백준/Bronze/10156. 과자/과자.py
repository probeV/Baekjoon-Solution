K, N, M=map(int, input().split())
if K*N<=M:
    print(0)
else:
    print(K*N-M)