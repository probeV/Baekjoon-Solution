#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < cost) continue;

        for (auto &[next, w] : graph[curr]) {
            if (dist[next] > dist[curr] + w) {
                dist[next] = dist[curr] + w;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    graph.resize(N + 1);
    dist.assign(N + 1, INF);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c}); // 양방향
    }

    dijkstra(1);

    cout << dist[N] << '\n';
    return 0;
}
