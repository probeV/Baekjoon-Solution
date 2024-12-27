#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 123456 * 2;

vector<bool> isPrime(MAX_N + 1, true);
vector<int> res(MAX_N + 1);

void initializePrimes() {
    isPrime[0] = isPrime[1] = false;

    // 에라토스테네스의 체로 소수 판별
    for (int i = 2; i * i <= MAX_N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 소수 누적합 계산
    for (int i = 2; i <= MAX_N; i++) {
        res[i] = res[i - 1] + (isPrime[i] ? 1 : 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    initializePrimes();

    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        cout << res[2 * n] - res[n] << "\n";
    }

    return 0;
}
