#include <bits/stdc++.h>

using namespace std;

int R, C, T;
vector<pair<int, int>> mv = { {0,-1}, {0,1}, {-1,0}, {1,0} };

vector<vector<vector<int> > > arr(2);
int up=0, down=0;

int main() {
	cin >> R >> C >> T;

	for (int i = 0; i < 2; i++) {
		arr[i].resize(R, vector<int>(C, 0));
	}

	for (int y = 0;y < R;y++) {
		vector<int> a;
		for (int x = 0;x < C;x++) {
			int temp;
			cin >> temp;

			arr[0][y][x] = temp;

			// 공기 청정기 y 좌표 체크
			if (temp == -1) {
				if (up == 0) up = y;
				else down = y;
			}
		}
		arr[0].push_back(a);
	}

	for (int c = 1;c <= T;c++) {
		int curr = (c + 1) % 2;
		int next = c % 2;

		//arr 초기화
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				arr[next][y][x] = 0;
			}
		}

		//미세 먼지 확산
		for (int y = 0;y < R; y++) {
			for (int x = 0;x < C;x++) {
				// 미세 먼지가 있을 때
				if (arr[curr][y][x] > 0) {
					int plus = arr[curr][y][x]/5;
					int cnt = 0;

					//주변에 체크
					for (int i = 0;i < 4;i++) {
						int nextX = x + mv[i].first;
						int nextY = y + mv[i].second;

						//범위 밖에 있을 때
						if (nextY < 0 || nextX < 0 || nextX >= C || nextY >= R) continue;

						//공기청정기가 있을 때
						if (nextX == 0 && (nextY == up || nextY == down)) continue;

						//확산
						arr[next][nextY][nextX] += plus;
						cnt++;
					}
					
					//확산된 만큼 빼주기
					arr[next][y][x] += arr[curr][y][x] - plus * cnt;
				}
			}
		}

		//cout << "\n\n";
		//for (int y = 0; y < R; y++) {
		//	for (int x = 0; x < C; x++) {
		//		cout << arr[curr][y][x] << " ";
		//	}
		//	cout << "\n";
		//}
		//
		//cout << "\n확산 후\n";
		//for (int y = 0; y < R; y++) {
		//	for (int x = 0; x < C; x++) {
		//		cout << arr[next][y][x] << " ";
		//	}
		//	cout << "\n";
		//}
		

		// # 위쪽 공기 청정기 작동 (반시계방향)
		// 0열 y축 이동 (아래쪽으로)
		for (int y = up;y > 0;y--) {
			arr[next][y][0] = arr[next][y - 1][0];
		}
		arr[next][up][0] = 0;

		// 0행 x축 이동 (왼쪽으로)
		for (int x = 0;x < C-1;x++) {
			arr[next][0][x] = arr[next][0][x + 1];
		}

		// C-1열 y축 이동 (위쪽으로)
		for (int y = 0;y < up; y++) {
			arr[next][y][C - 1] = arr[next][y + 1][C - 1];
		}
		
		// UP행 x축 이동 (오른쪽으로)
		for (int x = C - 1;x > 0;x--) {
			arr[next][up][x] = arr[next][up][x - 1];
		}

		// # 아래쪽 공기 청정기 작동 (시계방향)
		// 0열 y축 이동 (위쪽으로)
		for (int y = down;y < R - 1; y++) {
			arr[next][y][0] = arr[next][y + 1][0];
		}
		arr[next][down][0] = 0;

		// R-1행 x축 이동 (왼쪽으로)
		for (int x = 0;x < C - 1;x++) {
			arr[next][R - 1][x] = arr[next][R - 1][x + 1];
		}

		// C-1열 y축 이동 (아래쪽으로)
		for (int y = R - 1;y > down;y--) {
			arr[next][y][C - 1] = arr[next][y - 1][C - 1];
		}

		// DOWN행 x축 이동 (오른쪽으로)
		for (int x = C - 1;x > 0;x--) {
			arr[next][down][x] = arr[next][down][x-1];
		}

		// 공기청정기 있는 곳 -1로 값 덮어씌우기
		arr[next][up][0] = -1;
		arr[next][down][0] = -1;


		//cout << "\n공기청정기 작동 후\n";
		//for (int y = 0; y < R; y++) {
		//	for (int x = 0; x < C; x++) {
		//		cout << arr[next][y][x] << " ";
		//	}
		//	cout << "\n";
		//}
	}

	//총 합산
	int res = 0;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			res += arr[T%2][y][x];
		}
	}

	cout << res+2;
}