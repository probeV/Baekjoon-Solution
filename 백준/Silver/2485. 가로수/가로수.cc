#include <bits/stdc++.h>
#include <numeric> // gcd 함수 사용을 위한 헤더 추가
using namespace std;

int N, res;
vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 간격 계산 및 GCD 구하기
    int g = abs(arr[1] - arr[0]); // 첫 번째 간격
    for (int i = 2; i < N; i++) {
        g = gcd(g, abs(arr[i] - arr[i - 1])); // std::gcd로 변경
    }

    // 새로 심어야 하는 가로수 계산
    for (int i = 1; i < N; i++) {
        res += (abs(arr[i] - arr[i - 1]) / g) - 1;
    }

    cout << res << "\n";
    return 0;
}
