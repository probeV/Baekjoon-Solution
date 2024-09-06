#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, M, K, X, Y;
    cin >> N >> M >> K >> X >> Y;

    vector<pair<long long, long long>> changes(N);  // 변화량 저장 (ΔT)
    
    for (int i = 0; i < N; i++) {
        long long A, B;
        cin >> A >> B;
        // ΔT_i = X * A_i - Y * B_i
        long long deltaT = X * A - Y * B;
        changes[i] = {deltaT, i};  // 변화량과 해당 역 번호 저장
    }

    // 변화량을 기준으로 오름차순 정렬
    sort(changes.begin(), changes.end());

    // 기본 운행 시간 (대피선 설치 전)
    long long total_time = (X + Y) * K;

    // 변화량이 작은 M개의 역에 대피선을 설치
    for (int i = 0; i < M; i++) {
        total_time += changes[i].first;  // ΔT 값을 합산
    }

    // 최종 최소 운행 시간 출력
    cout << total_time << endl;

    return 0;
}
