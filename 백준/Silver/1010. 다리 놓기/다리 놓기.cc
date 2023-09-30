#include <bits/stdc++.h>

using namespace std;

#define SIZE 100001

int T;
int N, M;

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		long long result = 1;
		cin >> N >> M;

		int r = 1;
		for (int j = M; j > M-N; j--) {
			result *= j;
			result /= r;
			r++;

		}
		cout << result << "\n";
	}
	return 0;
}