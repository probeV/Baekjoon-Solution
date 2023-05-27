#include <bits/stdc++.h>

using namespace std;

#define SIZE 60

int T;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;
	
	int a, b;
	for (int i = 1; i <= T; i++) {
		cin >> a >> b;

		int t = a;

		a = a % 10;
		for (int j = 1; j < b; j++) {
			a = (a * t) % 10;
		}

		if (a == 0)
			cout << 10 << endl;
		else
			cout << a << endl;
	}

	return 0;
}