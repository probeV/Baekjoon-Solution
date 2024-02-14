#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int x;
	int y;
}Position;

bool cmp(const Position& p1, const Position& p2)
{
	if (p1.x == p2.x)			//좌표 x가 같다면
		return p1.y < p2.y;		//좌표 y기준으로 올림차순
	else
		return p1.x < p2.x;		//좌표 x기준으로 올림차순
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	Position* arr = new Position[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
		cout << arr[i].x << " " << arr[i].y << "\n";

	delete[] arr;
	return 0;
}