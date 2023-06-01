#include <bits/stdc++.h>

using namespace std;

#define SIZE 100010

//행성 개수
int N;

//좌표 정보
vector<pair<int, int> > Arr[3];

//경로 정보
struct info {
	int w, start, end;
};
vector<struct info> route;

//MST parent 배열
int parent[SIZE];

//MST find
int find(int x) {
	while (x != parent[x])
		x = parent[x];
	return x;
}

//MST union
void uni(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);

	if (rootA < rootB)
		parent[rootB] = rootA;
	else if (rootA > rootB)
		parent[rootA] = rootB;
}

//MST
int MST() {
	int result = 0;

	//행성 탐색
	for (int j = 0; j < route.size(); j++) {
		if (find(route[j].start)!=find(route[j].end)) {
			uni(route[j].start, route[j].end);
			result += route[j].w;
		}
	}

	return result;
}

//parent 배열 초기화
void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

//sort
int cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

int cmp2(struct info& a, struct info& b) {
	return a.w < b.w;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	//input
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		Arr[0].push_back({ x, i });
		Arr[1].push_back({ y, i });
		Arr[2].push_back({ z, i });
	}

	sort(Arr[0].begin(), Arr[0].end(), cmp);
	sort(Arr[1].begin(), Arr[1].end(), cmp);
	sort(Arr[2].begin(), Arr[2].end(), cmp);

	//route find
	for (int i = 0; i < N-1; i++) {
		route.push_back({ abs(Arr[0][i].first - Arr[0][i + 1].first), Arr[0][i].second, Arr[0][i+1].second });
		route.push_back({ abs(Arr[1][i].first - Arr[1][i + 1].first), Arr[1][i].second, Arr[1][i+1].second });
		route.push_back({ abs(Arr[2][i].first - Arr[2][i + 1].first), Arr[2][i].second, Arr[2][i+1].second });
	}

	sort(route.begin(), route.end(), cmp2);

	//parent init
	init();

	//MST
	cout << MST();

	return 0;
}