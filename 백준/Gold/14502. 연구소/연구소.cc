#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define SIZE 10

int N, M;

int Arr[SIZE][SIZE];

struct coor {
	int x, y;
};

vector<struct coor> null;

vector<struct coor> two;

pair<int, int> Mv[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int BFS() {
	bool visited[SIZE][SIZE];
	memset(visited, false, sizeof(visited));

	for (auto c : two) {
		queue<pair<int, int> > q;

		q.push({ c.x, c.y });

		while (!q.empty()) {
			int curr_x = q.front().first;
			int curr_y = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int next_x = curr_x + Mv[i].first;
				int next_y = curr_y + Mv[i].second;

				if (next_x <= 0 || next_x > M || next_y <= 0 || next_y > N) continue;

				if (!visited[next_y][next_x] && Arr[next_y][next_x] == 0) {
					q.push({ next_x, next_y });
					visited[next_y][next_x] = true;
				}
			}
		}
	}

	int count = 0;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			if (Arr[i][j] == 0 && !visited[i][j]) 
				count++;

	return count;
}

int main(void) {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Arr[i][j];
			if (Arr[i][j] == 0)
				null.push_back({ j,i });
			if (Arr[i][j] == 2)
				two.push_back({ j,i });
		}
	}

	int res = 0;

	for (int i = 0; i < null.size()-2; i++) {
		Arr[null[i].y][null[i].x] = 1;
		for (int j = i+1; j < null.size()-1; j++) {
			Arr[null[j].y][null[j].x] = 1;
			for (int k = j+1; k < null.size(); k++) {
				Arr[null[k].y][null[k].x] = 1;
				res = max(res, BFS());
				Arr[null[k].y][null[k].x] = 0;
			}
			Arr[null[j].y][null[j].x] = 0;
		}
		Arr[null[i].y][null[i].x] = 0;
	}

	cout << res;

	return 0;
}