#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;
int N, M;
vector<vector<pair<int, int>>> graph;
vector<int> site;
vector<long long> dist;

void dijkstra(int start) {
    priority_queue<pair<long long, int> > pq;
    pq.push({0, start});
    dist[start]=0;

    while(!pq.empty()){
        long long cost = pq.top().first * -1;
        int curr = pq.top().second;
        pq.pop();

        if(dist[curr] < cost) continue;

        for(auto &[next, w]:graph[curr]){
            if(site[next] && next!=N-1) continue;

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

    site.resize(N);
    graph.resize(N);
    dist.assign(N, INF);

    for(int i=0;i<N;i++){
        cin >> site[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c}); // 양방향
    }

    dijkstra(0);

    if(dist[N-1]==INF)
        cout << -1;
    else
        cout << dist[N-1];
    return 0;
}
