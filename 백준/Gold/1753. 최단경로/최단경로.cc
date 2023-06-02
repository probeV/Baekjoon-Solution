#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define SIZE 20010

int V, E;

int startNode;

vector<pair<int, int> > route[SIZE];

vector<int> dist;

void Dijk() {
	for (int i = 0; i <= V; i++) {
		dist.push_back(INT_MAX);
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
	scanf("%d %d", &V, &E);
	scanf("%d", &startNode);

	int u, v, w;
	for (int i = 1; i <= E; i++) {
		scanf("%d %d %d", &u, &v, &w);

		route[u].push_back({ v, w });
	}

	Dijk();

	//output
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}