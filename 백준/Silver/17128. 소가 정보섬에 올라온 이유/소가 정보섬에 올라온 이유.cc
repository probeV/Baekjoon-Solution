#include <bits/stdc++.h>

#define SIZE 200010

using namespace std;

int N, Q;

int numArr[SIZE];

int changeArr[SIZE];

long long resArr[SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
		cin >> numArr[i];
	numArr[N + 1] = numArr[1];
	numArr[N + 2] = numArr[2];
	numArr[N + 3] = numArr[3];
	for (int i = 1; i <= Q; i++)
		cin >> changeArr[i];

	long long res = 0;
	for (int i = 1; i <= N; i++) {
		resArr[i] = numArr[i] * numArr[i + 1] * numArr[i + 2] * numArr[i + 3];
		res += resArr[i];
	}

	for (int i = 1; i <= Q; i++) {
		int curr = changeArr[i];

		for (int j = 1; j <= 4; j++) {
			if (curr == 0) curr = N;
			res = res - resArr[curr];
			resArr[curr] = resArr[curr] * -1;
			res = res + resArr[curr];
			curr--;
		}

		cout << res << "\n";
	}
	return 0;

}