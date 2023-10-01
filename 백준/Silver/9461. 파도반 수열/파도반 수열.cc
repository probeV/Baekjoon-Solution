#include <bits/stdc++.h>

using namespace std;

#define SIZE 101

int T;
long long arr[SIZE];
int N;

int main(void) {
	cin >> T;
	arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2; arr[5] = 2;
	for (int i = 1; i <= T; i++) {
		cin >> N;

		for (int j = 6; j <= N; j++) {
			arr[j] = arr[j - 1] + arr[j - 5];
		}

		cout << arr[N] << "\n";
	}
	return 0;
}