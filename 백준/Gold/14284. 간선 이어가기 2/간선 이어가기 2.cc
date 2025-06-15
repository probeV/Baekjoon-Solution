#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int N, M, S, T;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    pq.push({0,start});
    dist[start]=0;

    while(!pq.empty()){
        int cost = pq.top().first * -1;
        int curr = pq.top().second;
        pq.pop();

        if(dist[curr] < cost) continue;

        for(auto &[next, w]:graph[curr]){
            if(dist[next] > dist[curr] + w){
                dist[next] = dist[curr] + w;
                pq.push({dist[next]*-1, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    graph.resize(N+1);
    dist.assign(N+1, INF);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c}); // 양방향
    }

    cin >> S >> T;

    dijkstra(S);

    cout << dist[T];
    return 0;
}
