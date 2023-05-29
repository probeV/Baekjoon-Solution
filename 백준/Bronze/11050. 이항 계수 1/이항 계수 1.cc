#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(void) {
	cin >> N >> M;


	int result = 1;
	for (int i = 1; i <= M; i++) {
		result *= N;
		N--;
	}

	for (int i = M; i >= 1 ; i--) {
		result /= M;
		M--;
	}

	cout << result;

	return 0;
}