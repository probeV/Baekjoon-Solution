#include <bits/stdc++.h>

using namespace std;

#define SIZE 1510

int R, C;

vector<string> Arr;

bool visited[SIZE][SIZE];
bool swan_visited[SIZE][SIZE];

pair<int, int> Mv[4] = { {1,0}, {-1,0},{0,1},{0,-1} };

queue<pair<int, int> > swan_q;
queue<pair<int, int> > water_q;
queue<pair<int, int> > temp_swan_q;
queue<pair<int, int> > temp_water_q;

void q_clear(queue<pair<int, int> >& q) {
	queue<pair<int, int> > empty;
	swap(q, empty);
}

//그룹화
bool find_swan() {
	while (!swan_q.empty()) {
		int curr_x = swan_q.front().first;
		int curr_y = swan_q.front().second;
		swan_q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + Mv[i].first;
			int next_y = curr_y + Mv[i].second;

			if (next_x <= 0 || next_x > C || next_y <= 0 || next_y > R) continue;

			if (swan_visited[next_y][next_x]) continue;

			//그룹과 연결된 물들
			if (Arr[next_y][next_x] == 'X') {
				temp_swan_q.push({ next_x, next_y });
				swan_visited[next_y][next_x] = true;
				continue;
			}
			else if (Arr[next_y][next_x] == 'L') {
				return true;
			}

			swan_q.push({ next_x, next_y });
			swan_visited[next_y][next_x] = true;
		}
	}
	return false;
}

//얼음 녹이기
void melting_ice() {
	while (!water_q.empty()) {
		int curr_x = water_q.front().first;
		int curr_y = water_q.front().second;
		water_q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + Mv[i].first;
			int next_y = curr_y + Mv[i].second;

			if (next_x <= 0 || next_x > C || next_y <= 0 || next_y > R) continue;

			if (visited[next_y][next_x]) continue;

			if (Arr[next_y][next_x] == 'X') {
				Arr[next_y][next_x] = '.';
				temp_water_q.push({ next_x, next_y });
				visited[next_y][next_x] = true;
			}
		}
	}

}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	//input
	cin >> R >> C;

	Arr.push_back(" ");
	for (int i = 1; i <= R; i++) {
		string temp; cin >> temp;
		Arr.push_back(" ");
		Arr[i] += temp;
	}

	int swan_x, swan_y;
	//백조가 있는 그룹 찾기
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			//백조가 나타나면 그룹화
			if (Arr[y][x] == 'L') {
				water_q.push({ x,y });
				swan_x = x; swan_y = y;
			}
			else if (Arr[y][x] == '.') {
				water_q.push({ x,y });
				visited[y][x] = true;
			}
		}
	}

	swan_q.push({ swan_x, swan_y });
	swan_visited[swan_y][swan_x] = true;

	int res = 0;

	while (true) {
		if (find_swan()) break;

		melting_ice();

		water_q = temp_water_q;
		swan_q = temp_swan_q;
		q_clear(temp_water_q);
		q_clear(temp_swan_q);
		res++;
	}

	cout << res;

	return 0;
}