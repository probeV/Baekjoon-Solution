#include <bits/stdc++.h>

using namespace std;

#define SIZE 40010

int N;

int s_x, s_y;

vector<pair<int, int> > coorArr;

stack<int>	s;

bool ccw(int x1, int y1, int x2, int y2) {
	long long temp = 1LL * x1 * y2 - 1LL * x2 * y1;

	//좌회전
	if (temp > 0)
		return true;
	//우회전
	else if (temp <= 0)
		return false;
}

void convex_hull(int next) {
	//겉 껍질이 만들어 졌을 경우
	if (next == N + 1) {
		cout << s.size()-1;
		exit(0);
	}
		
	int pre = s.top(); s.pop();
	int curr = s.top(); s.pop();

	int v1_x = coorArr[pre].first - coorArr[curr].first;
	int v1_y = coorArr[pre].second - coorArr[curr].second;

	int v2_x = coorArr[next].first - coorArr[curr].first;
	int v2_y = coorArr[next].second - coorArr[curr].second;

	if (ccw(v1_x, v1_y, v2_x, v2_y)) {
		s.push(curr); s.push(pre); s.push(next);
	}
	else {
		s.push(curr); s.push(next);
		while(s.size()>2) {
			int next = s.top(); s.pop();
			int pre = s.top(); s.pop();
			int curr = s.top(); s.pop();

			int v1_x = coorArr[pre].first - coorArr[curr].first;
			int v1_y = coorArr[pre].second - coorArr[curr].second;

			int v2_x = coorArr[next].first - coorArr[curr].first;
			int v2_y = coorArr[next].second - coorArr[curr].second;

			//좌회전 할 때
			if (ccw(v1_x, v1_y, v2_x, v2_y)) {
				s.push(curr); s.push(pre); s.push(next);
				break;
			}

			s.push(curr); s.push(next);
		}
	}

	convex_hull(next + 1);
}

int compare(const void *a, const void *b) {
	pair<int, int>* A = ((pair<int, int> *)a);
	pair<int, int>* B = ((pair<int, int> *)b);


	double v1 = atan2(A->second - s_y, A->first - s_x);
	double v2 = atan2(B->second - s_y, B->first - s_x);

	if (v1 == v2) {
		if (A->first == B->first)
			return abs(A->second-s_y) < abs(B->second-s_y);
		return abs(A->first-s_x) > abs(B->first-s_x);
	}
	return v1 > v2;
}

int main(void) {
	//input
	cin >> N;
	s_x, s_y = SIZE, SIZE;
	for (int i = 1; i <= N; i++) {
		int x; int y;
		cin >> x >> y;
		coorArr.push_back({ x, y });

		//시작점 저장
		if (s_y > y) {
			s_y = y; s_x = x;
		}
		else if (s_y == y && s_x > x)
			s_x = x;
	}

	//오름차순으로 정렬
	qsort(&coorArr[0], coorArr.size(), sizeof(pair<int, int>), compare);
	//마지막 돌아오는 점
	coorArr.push_back(coorArr[0]);

	////처음 두 점 푸쉬
	s.push(0); s.push(1);
	convex_hull(2);

	return 0;
}