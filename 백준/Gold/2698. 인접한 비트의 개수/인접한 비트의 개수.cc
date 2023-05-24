#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int tc; cin >> tc;
	
	int length[tc];
	int adjcent[tc];
	for (int i = 0; i < tc; i++) {
		cin >> length[i] >> adjcent[i];
	}
	
	int max_n = *max_element(length, length + tc);
	int max_k = *max_element(adjcent, adjcent + tc);
	
	int dp[max_k + 1][max_n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][1] = 2; dp[0][2] = 3;
	
	for (int i = 3; i <= max_n; i++) {
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
	}
	
	for (int i = 1; i <= max_k; i++) {
		for (int j = 2; j <= max_n; j++) {
			if (i + 1 > j) {
				continue;
			}
			else if (i + 1 == j) {
				dp[i][j] = 1;
				continue;
			}
			
			dp[i][j] = dp[i][j - 1];
			dp[i][j] += dp[i][j - 2];
			dp[i][j] += dp[i - 1][j - 1] - dp[i - 1][j - 2];
		}
	}
	
	for (int i = 0; i < tc; i++) {
		int n = length[i];
		int k = adjcent[i];
		
		cout << dp[k][n] << '\n';
	}
}