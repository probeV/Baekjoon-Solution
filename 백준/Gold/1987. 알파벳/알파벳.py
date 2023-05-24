R, C = map(int, input().split())
arr = []
for _ in range(R):
    arr.append(list(input()))
ans = 0
used = set()
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(x, y, count):
    global ans
    ans = max(ans, count)
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < R and 0 <= ny < C and not arr[nx][ny] in used:
            used.add(arr[nx][ny])
            dfs(nx, ny, count+1)
            used.remove(arr[nx][ny])
            
used.add(arr[0][0])
dfs(0, 0, 1)
print(ans)