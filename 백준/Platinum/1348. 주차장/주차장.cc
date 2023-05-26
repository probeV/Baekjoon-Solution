#include <bits/stdc++.h>

using namespace std;

#define SIZE 60

int R, C;

//전체 정보 배열
char Arr[SIZE][SIZE];

//자동차 움직임
pair<int, int> Mv[4] = { {1,0},{-1,0},{0,1},{0,-1} };

//현재 자동차 좌표 정보
vector<pair<int, int> > car;

//현재 주차 공간 좌표 정보
vector<pair<int, int> > park;

//자동차가 갈 수 있는 후보군 정보
vector<vector<int> > route;

//BFS 이용
int visited[SIZE][SIZE];

//차 인덱스 -> 주차 공간 인덱스 // 거리 저장
int dis[101][101];

bool isParking[101]; int Pre[101];

void BFS(int idx) {
	queue<pair<int, int> > q;

	int pre_x = car[idx].first;
	int pre_y = car[idx].second;

	q.push({ pre_x, pre_y });
	visited[pre_y][pre_x] = 0;

	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + Mv[i].first;
			int next_y = curr_y + Mv[i].second;

			if (next_x <= 0 || next_x > C || next_y <= 0 || next_y > R) continue;

			if (Arr[next_y][next_x] != 'X' && visited[next_y][next_x] == -1) {
				q.push({ next_x, next_y });
				visited[next_y][next_x] = visited[curr_y][curr_x] + 1;
			}
		}
	}

	route.push_back(vector<int>());

	//자동차 인덱스 -> 주차 공간 인덱스 배열에 경로 값 저장
	for (int i = 0; i < park.size(); i++) {
		if (visited[park[i].second][park[i].first] == -1)
			dis[idx][i] = INT_MAX;
		else {
			route[idx].push_back(i);
			dis[idx][i] = visited[park[i].second][park[i].first];
		}
	}
}

bool DFS(int curr, int target) {
	for (int i = 0; i < route[curr].size(); i++) {
		//주차 공간 인덱스
		int next = route[curr][i];

		//target 보다 큰 경우 + 이미 방문 한 경우
		if (isParking[next] || dis[curr][next] > target) continue;
		
		isParking[next] = true;

		if (Pre[next] == -1 || DFS(Pre[next], target)) {
			Pre[next] = curr;
			return true;
		}
	}
	return false;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	//input
	cin >> R >> C; cin.ignore();
	for (int y = 1; y <= R; y++) {
		cin.getline(&Arr[y][1], C + 1);
	}

	//자동차, 주차 공간 좌표 저장
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (Arr[y][x] == 'C') 
				car.push_back({ x, y });
			else if(Arr[y][x] == 'P')
				park.push_back({ x, y });
		}
	}

	//BFS로 거리 구하기
	for (int i = 0; i < car.size(); i++) {
		memset(visited, -1, sizeof(visited));
		BFS(i);
	}

	//이분 탐색
	int start = 0, end = SIZE * SIZE; int ans = -1;
	while (start <= end) {
		int mid = (start + end) / 2; int check = 0;
		fill(Pre, Pre + 101, -1);

		for (int i = 0; i < car.size(); i++) {
			fill(isParking, isParking + 101, false);
			if (DFS(i, mid))
				check++;
		}

		if (check == car.size()) {
			ans = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	cout << ans;

	return 0;
}