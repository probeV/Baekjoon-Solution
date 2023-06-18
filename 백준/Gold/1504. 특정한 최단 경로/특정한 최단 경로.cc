#include <bits/stdc++.h>

using namespace std;

#define SIZE 200010

int N, E;

vector<pair<int, int> > route[SIZE];

int dist[SIZE];

void Dijk(int startNode) {
	for (int i = 0; i <= N; i++) {
		dist[i]=INT_MAX;
	}

	priority_queue<pair<int, int> > pq;

	pq.push({ 0, startNode });
	dist[startNode] = 0;

	while (!pq.empty()) {
		int curr_node = pq.top().second;
		int curr_w = -pq.top().first;
		pq.pop();

		if (dist[curr_node] < curr_w) continue;

		for (int i = 0; i < route[curr_node].size(); i++) {
			int next_node = route[curr_node][i].first;
			int next_w = route[curr_node][i].second;

			if (dist[next_node] > curr_w + next_w) {
				dist[next_node] = curr_w + next_w;
				pq.push({ -(curr_w + next_w), next_node });
			}
		}
	}
}

int main(void) {
	//input
	cin >> N >> E;

	int firstNode, secondNode;
	long long res1 = 0, res2 = 0, res = 0;

	int u, v, w;
	for (int i = 1; i <= E; i++) {
		cin >> u >> v >> w;

		route[u].push_back({ v, w });
		route[v].push_back({ u, w });
	}

	cin >> firstNode >> secondNode;

	Dijk(1);
	res1 += dist[firstNode];
	res2 += dist[secondNode];

	Dijk(firstNode);
	res1 += dist[secondNode];
	Dijk(secondNode);
	res1 += dist[N];

	Dijk(secondNode);
	res2 += dist[firstNode];
	Dijk(firstNode);
	res2 += dist[N];

	res = min(res1, res2);

	//output
	if (res >= INT_MAX || res<=0)
		cout << -1;
	else
		cout << res;

	return 0;
}