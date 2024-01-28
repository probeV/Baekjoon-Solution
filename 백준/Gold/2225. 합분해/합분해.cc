#include <bits/stdc++.h>

using namespace std;

#define MAX 200000

int DP(int R, int C) {
    long long dp[MAX][2];

    int row = 2, col;

    dp[1][1] = 1;
    dp[2][1] = 1;


    for (int i = 2; i <= R; i++) {
        int cur_row = row % 2;
        int pre_row = (row - 1) % 2;
        col = 1;
        dp[col++][cur_row] = 1;

        for (int j = 1; j < i; j++) {
            dp[col++][cur_row] = (dp[j][pre_row] + dp[j + 1][pre_row])%1000000000;
        }
        dp[col][cur_row] = 1;

        row++;
    }

    return dp[C][R % 2];
}

int main() {
    int N, K;

    cin >> N >> K;

    cout << DP(K + N - 1, K) % 1000000000;
}