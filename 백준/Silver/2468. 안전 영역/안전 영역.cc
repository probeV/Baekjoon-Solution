#include <bits/stdc++.h>
using namespace std;

int N, R = 1;
vector<vector<int>> arr;
vector<vector<bool>> isVisited;
set<int> s;
vector<pair<int, int>> mv = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void BFS(int x, int y, int w) {
    queue<pair<int, int>> q;
    q.push({x, y});
    isVisited[y][x] = true;

    while (!q.empty()) {
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + mv[i].first;
            int next_y = curr_y + mv[i].second;

            if (next_x < 1 || next_y < 1 || next_x > N || next_y > N) continue;

            if (!isVisited[next_y][next_x] && arr[next_y][next_x] > w) {
                q.push({next_x, next_y});
                isVisited[next_y][next_x] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr.resize(N + 1, vector<int>(N + 1));
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> arr[y][x];
            s.insert(arr[y][x]);
        }
    }

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        int tmp = 0;
        isVisited.assign(N + 1, vector<bool>(N + 1, false));

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (arr[y][x] > *iter && !isVisited[y][x]) {
                    BFS(x, y, *iter);
                    tmp++;
                }
            }
        }

        R = max(R, tmp);
    }

    cout << R << "\n";
    return 0;
}
