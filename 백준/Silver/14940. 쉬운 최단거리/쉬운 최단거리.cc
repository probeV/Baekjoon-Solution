#include <bits/stdc++.h>

using namespace std;

#define SIZE 1010

int n, m;

int Arr[SIZE][SIZE];

int visited[SIZE][SIZE];

typedef struct{
	int x, y;
}LOC;

LOC start;

LOC Mv[4] = { {1,0}, {-1,0},{0,1},{0,-1} };

void BFS(LOC start) {
	int cnt = 0;

	queue<LOC> q;
	q.push(start);
	visited[start.y][start.x] = cnt;

	while (!q.empty()) {
		int temp = q.size();

		cnt++;

		for (int i = 0; i < temp; i++) {
			LOC curr;
			curr.x = q.front().x;
			curr.y = q.front().y;
			q.pop();

			for (int i = 0; i < 4; i++) {
				LOC next;
				next.x = curr.x + Mv[i].x;
				next.y = curr.y + Mv[i].y;

				if (next.x <= 0 || next.x > m || next.y <= 0 || next.y > n) continue;

				if (Arr[next.y][next.x] == 1 && visited[next.y][next.x] == 0) {
					q.push({ next.x, next.y });
					visited[next.y][next.x] = cnt;
				}
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			cin >> Arr[y][x];
			if (Arr[y][x] == 2) {
				start.x = x;
				start.y = y;
			}
		}
	}

	BFS(start);

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (Arr[y][x] == 1 && visited[y][x] == 0)
				cout << -1 << " ";
			else
				cout << visited[y][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}