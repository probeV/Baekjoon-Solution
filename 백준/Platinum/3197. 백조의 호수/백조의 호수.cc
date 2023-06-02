#include <bits/stdc++.h>

using namespace std;

#define SIZE 1510

int R, C;

//백조, 물, 얼음 정보
vector<string> Arr;

//각 그룹의 얼음 정보 저장
queue<pair<int, int> > waterArr;

//그룹 코드 저장
int visited[SIZE][SIZE];

//그룹 부모 배열
int parent[SIZE*SIZE];

//그룹 코드
int code = 1;

//결과값
int result = 0;

//움직임
pair<int, int> Mv[4] = { {1,0}, {-1,0},{0,1},{0,-1} };

//그룹화
void BFS(int x, int y) {
	queue<pair<int, int>> q;

	q.push({ x, y });
	visited[y][x] = code;

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + Mv[i].first;
			int next_y = curr_y + Mv[i].second;

			if (next_x <= 0 || next_x > C || next_y <= 0 || next_y > R) continue;

			//그룹과 연결된 물들
			if (Arr[next_y][next_x] == '.' && visited[next_y][next_x] == 0) {
				q.push({ next_x, next_y });
				visited[next_y][next_x] = code;
			}
			//그룹의 외곽 물
			else if (Arr[next_y][next_x] == 'X' && visited[next_y][next_x]==0) {
				waterArr.push({ curr_x,curr_y });
				visited[next_y][next_x] = code;
			}
		}
	}
}

//부모 찾기
int find(int x) {
	while (x != parent[x]) {
		x = parent[x];
	}
	return x;
}

//연결
void uni(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);

	if (rootA < rootB) {
		parent[rootB] = rootA;
	}
	else if (rootA > rootB) {
		parent[rootA] = rootB;
	}
}

void p() {
	cout << "\n\n";
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (Arr[y][x] == '.')
				cout << visited[y][x];
			else
				cout << Arr[y][x];
		}
		cout << "\n";
	}
}

//얼음 녹이기
void melting_ice() {
	queue<pair<int, int> > curr;

	//백조 연결 될 때 까지 녹이기
	while (parent[1] != parent[2]) {
		result++;

		//한 바퀴 
		int s = waterArr.size();

		for (int i = 0; i < s; i++) {
			int curr_x = waterArr.front().first;
			int curr_y = waterArr.front().second;

			waterArr.pop();

			//얼음 녹이고 난 후 다음 차례 얼음 찾기
			for (int i = 0; i < 4; i++) {
				int next_x = curr_x + Mv[i].first;
				int next_y = curr_y + Mv[i].second;

				//범위 넘어갈 때
				if (next_x <= 0 || next_x > C || next_y <= 0 || next_y > R) continue;

				//얼음 녹이고, 얼음이 녹아서 물이 된 좌표 저장
				if (Arr[next_y][next_x] == 'X') {
					curr.push({ next_x, next_y });
					waterArr.push({ next_x, next_y });
					Arr[next_y][next_x] = 'c';
					visited[next_y][next_x] = visited[curr_y][curr_x];
				}
				//주변 물 탐색하고 다른 그룹의 물이 존재하면
				else if (visited[next_y][next_x] != visited[curr_y][curr_x]) {
					int a = visited[next_y][next_x];
					int b = visited[curr_y][curr_x];
					if (find(a) != find(b)) {
						uni(a, b);
						if (parent[1] == parent[2]){
							if (Arr[next_y][next_x] == 'c')
								result++;
							return;
						}
					}
				}
			}
		}

		while (!curr.empty()) {
			Arr[curr.front().second][curr.front().first] = '.';
			curr.pop();
		}
	}
}

void init() {
	for (int i = 1; i < code; i++) {
		parent[i] = i;
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

	//백조가 있는 그룹 찾기
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			//백조가 나타나면 그룹화
			if (Arr[y][x] == 'L') {
				BFS(x, y);
				code++;
			}
			//백조 사이에 빙판이 없는 경우를 고려해야 함
		}
	}

	//나머지 그룹 찾기
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (Arr[y][x] == '.' && visited[y][x] == 0) {
				BFS(x, y);
				code++;
			}
		}
	}

	//부모 초기화
	init();

	//물의 그룹화 이후 저장된 외곽 빙판 녹이기 진행
	melting_ice();

	cout << result-1;

	return 0;
}