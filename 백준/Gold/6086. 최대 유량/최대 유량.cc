#include <bits/stdc++.h>

using namespace std;

#define SIZE 200

int N;

map<char, vector<char> > route;
vector<char>::iterator iter;

bool visited[SIZE][SIZE];

int capacity[SIZE][SIZE]; int flow[SIZE][SIZE];

char startNode = 'A'; char endNode = 'Z';

int result = 0;

void Edmonds_Karp() {
	while (true) {
		vector<int> parent(SIZE, -1);

		queue<char> q;

		q.push(startNode);
		parent[startNode] = startNode;

		while (!q.empty() && parent[endNode]==-1) {
			char curr = q.front();
			q.pop();

			for (iter = route[curr].begin(); iter != route[curr].end(); iter++) {
				char next = *iter;
				if (capacity[curr][next]-flow[curr][next] > 0 && parent[next] == -1) {
					q.push(next);
					parent[next] = curr;
				}
			}
		}
		//더 이상 증가 경로 없음 
		if (parent[endNode] == -1) break;

		int temp = INT_MAX;
		for (int i = endNode; i != startNode; i = parent[i]) {
			temp = min(temp, capacity[parent[i]][i] - flow[parent[i]][i]);
		}

		for (int i = endNode; i != startNode; i = parent[i]) {
			flow[parent[i]][i] += temp;
			flow[i][parent[i]] -= temp;
		}

		result += temp;
	}
}

int main(void) {
	//input
	cin >> N;
	for (int i = 1; i <= N; i++) {
		char u, v; int w;
		cin >> u >> v >> w;
		
		//최대 용량 저장
		capacity[u][v] += w;
		capacity[v][u] += w;
		if (!visited[u][v]) {
			route[u].push_back(v);
			route[v].push_back(u);
			visited[u][v] = true;
			visited[v][u] = true;
		}
	}

	Edmonds_Karp();

	cout << result;
}