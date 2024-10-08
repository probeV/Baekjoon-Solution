#include <bits/stdc++.h>
using namespace std;

int K, V, E;
string res;
vector<vector<int>> arr;

// next_v가 들어가야 할 위치에 들어갈 수 있는지 체크
bool checkNextV(int next_v, unordered_set<int> &n) {
    return n.find(next_v) == n.end();
}

void DFS(int curr_v, vector<bool> &isVisited, unordered_set<int> &u, unordered_set<int> &d) {
    if (isVisited[curr_v] || res == "NO") return;

    isVisited[curr_v] = true;

    for (int i = 0; i < arr[curr_v].size(); i++) {
        int next_v = arr[curr_v][i];

        if (u.find(curr_v) != u.end()) {
            // curr_v가 u에 속할 때, next_v는 d에 속해야 한다
            if (checkNextV(next_v, u)) {
                d.insert(next_v);
            } else {
                res = "NO";
                return;
            }
        } else {
            // curr_v가 d에 속할 때, next_v는 u에 속해야 한다
            if (checkNextV(next_v, d)) {
                u.insert(next_v);
            } else {
                res = "NO";
                return;
            }
        }

        DFS(next_v, isVisited, u, d);
    }
}

int main() {
    cin >> K;

    for (int i = 1; i <= K; i++) {
        cin >> V >> E;

        res = "YES";
        arr.clear();  // 이전 테스트 케이스 데이터 초기화
        arr.resize(V + 1);

        for (int j = 1; j <= E; j++) {
            int a, b;
            cin >> a >> b;

            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        unordered_set<int> u, d;
        vector<bool> isVisited(V + 1, false);

        for (int i = 1; i <= V; i++) {
            if (!isVisited[i]) {
                u.insert(i);
                DFS(i, isVisited, u, d);
            }
            if (res == "NO") break;
        }

        cout << res << "\n";
    }

    return 0;
}
