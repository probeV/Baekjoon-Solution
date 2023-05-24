import sys
import collections

def bfs(start):
    cnt = 1
    visited = [0 for _ in range(n+1)]
    visited[start] = 1
    queue = collections.deque([start])
    while queue:
        u = queue.popleft()
        for v in g[u]:
            if not visited[v]:
                queue.append(v)
                visited[v] = 1
                cnt += 1
    return cnt

n, m = map(int, sys.stdin.readline().split())
g = collections.defaultdict(list)
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    g[b].append(a)

results = []
max_cnt = 0
for i in range(1, n+1):
    cnt = bfs(i)
    if cnt > max_cnt:
        max_cnt = cnt
    results.append([i, cnt])

for i, cnt in results:
    if cnt == max_cnt:
        print(i, end = ' ')