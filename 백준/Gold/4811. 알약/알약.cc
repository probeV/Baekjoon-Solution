#include <bits/stdc++.h>

using namespace std;

#define MAX 32

long long dp[MAX][MAX];

int main()
{
    int N;

    for (int w = 1; w <= 30; w++)
    {
        dp[w][0] = 1;
    }

    for (int w = 1; w <= 30; w++)
    {
        for (int h = 1; h <= w; h++)
        {
            if (h == w)
            {
                dp[w][h] = dp[w][h - 1];
            }
            else
            {
                dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
            }
        }
    }

    while (1)
    {
        cin >> N;

        if (N == 0)
        {
            break;
        }

        cout << dp[N][N] << "\n";
    }
}