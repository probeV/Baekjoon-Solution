#include <bits/stdc++.h>

using namespace std;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string A;

	char c[10] = { 'a', 'e', 'i','o','u', 'A', 'E','I', 'O', 'U'};

	while (true) {
		getline(cin, A);

		if (A[0] == '#' && A.size() == 1)
			break;

		int res = 0;
		
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < 10; j++) {
				if (A[i] == c[j]) {
					res++;
					break;
				}
			}
		}

		cout << res << "\n";
	}
	return 0;
}