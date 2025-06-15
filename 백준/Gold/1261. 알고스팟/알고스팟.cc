#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[101][101];
int dist[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;

    for (int y = 0; y < N; y++) {
        string s;
        cin >> s;
        for (int x = 0; x < M; x++) {
            arr[y][x] = s[x] - '0';
            dist[y][x] = 1e9; // 큰 값으로 초기화
        }
    }

    deque<pair<int, int>> dq;
    dq.push_front({0, 0});
    dist[0][0] = 0;

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

            int cost = dist[y][x] + arr[ny][nx];
            if (cost < dist[ny][nx]) {
                dist[ny][nx] = cost;
                if (arr[ny][nx] == 1)
                    dq.push_back({nx, ny});   // 벽: 비용 1 → 뒤로
                else
                    dq.push_front({nx, ny});  // 빈 방: 비용 0 → 앞으로
            }
        }
    }

    cout << dist[N - 1][M - 1] << "\n";
    return 0;
}
