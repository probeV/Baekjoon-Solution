#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define SIZE 1010

int N, M;

vector<string> Arr;

int visited[SIZE][SIZE];

pair<int, int> Mv[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void BFS() {
	queue<pair<int, int>> cand;
	queue<pair<int, int> > q;

	if (Arr[1][1] == '0')
		q.push({ 1,1 });
	else
		cand.push({ 1,1 });
	visited[1][1] = 1;

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + Mv[i].first;
			int next_y = curr_y + Mv[i].second;

			if (next_x <= 0 || next_x > M || next_y <= 0 || next_y > N) continue;
				
			if (visited[next_y][next_x] == 0 || visited[next_y][next_x] > visited[curr_y][curr_x] + 1) {
				if (Arr[next_y][next_x] == '0') {
					q.push({ next_x, next_y });
					visited[next_y][next_x] = visited[curr_y][curr_x] + 1;
				}
				else if (Arr[next_y][next_x] == '1') {
					cand.push({ next_x, next_y });
					visited[next_y][next_x] = visited[curr_y][curr_x] + 1;
				}
			}
		}
	}

	//벽이 부서진 후보들
	while (!cand.empty()) {
		int curr_x = cand.front().first;
		int curr_y = cand.front().second;
		cand.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + Mv[i].first;
			int next_y = curr_y + Mv[i].second;

			if (next_x <= 0 || next_x > M || next_y <= 0 || next_y > N) continue;

			//방문하지 않았을 때 or 벽을 무수지 않은 경로보다 작을 때
			if ((visited[next_y][next_x] == 0 || visited[next_y][next_x] > visited[curr_y][curr_x]+1) && Arr[next_y][next_x] == '0') {
				cand.push({ next_x, next_y });
				visited[next_y][next_x] = visited[curr_y][curr_x] + 1;
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	Arr.push_back(" ");
	for (int y = 1; y <= N; y++) {
		Arr.push_back(" ");
		string temp;
		cin >> temp; cin.ignore();
		Arr[y] = Arr[y] + temp;
	}

	BFS();

	if (visited[N][M] == 0)
		cout << -1;
	else
		cout << visited[N][M];

	return 0;
}