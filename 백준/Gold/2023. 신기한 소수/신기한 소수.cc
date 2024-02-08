#include <bits/stdc++.h>

using namespace std;

int N;
int e[4] = { 1,3,7,9 };

bool isDec(int x) {
    for (int i = 2; i < x; i++) {
        //나누어 떨어지면 소수가 아님
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void recur(int x, int n) {

    if (n == N) {
        cout << x << "\n";
    }

    x = x * 10;
    for (int i = 0; i < 4; i++) {
        if (isDec(x + e[i])) {
            recur(x + e[i], n + 1);
        }
    }
}

int main() {
    cin >> N;

    int start[4] = { 2,3,5,7 };

    for (int i = 0; i < 4; i++) {
        recur(start[i], 1);
    }
}