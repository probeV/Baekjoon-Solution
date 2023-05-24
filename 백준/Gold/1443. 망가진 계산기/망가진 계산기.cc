#include <bits/stdc++.h>

using namespace std;

int D, P;

int result = 0;

void Backtracking(int count, int total, int pre) {
	if (count == P) {
		result = max(result, total);
		return;
	}

	for (int i = pre; i >= 2; i--) {
		//곱한 값의 자릿수가 기준 보다 작을 때
		if (total * i / (int)pow(10, D) == 0) {
			Backtracking(count + 1, total * i, i);
		}
	}
}

int main(void) {
	cin >> D >> P;

	Backtracking(0, 1, 9);

	if (P == 0)
		cout << 1;
	else if (result != 0)
		cout << result;
	else
		cout << -1;

	return 0;
}