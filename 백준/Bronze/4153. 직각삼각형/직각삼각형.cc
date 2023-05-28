#include <bits/stdc++.h>

using namespace std;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	int a, b, c;

	while(true) {
		cin >> a >> b >> c;
		
		int max, A, B;

		if (a > b) {
			if (a > c) {
				max = a; A = b; B = c;
			}
			else {
				max = c; A = b; B = a;
			}
		}
		else {
			if (b > c) {
				max = b; A = a; B = c;
			}
			else {
				max = c; A = b; B = a;
			}
		}

		if (a == 0 && b == 0 && c == 0) break;

		if (pow(max, 2) == pow(A, 2) + pow(B, 2)) cout << "right" << endl;
		else cout << "wrong" << endl;

	}

	return 0;
}