#include <bits/stdc++.h>
using namespace std;

struct info {
    int cnt;  // 절연 횟수
    int S;    // 현재 역
    int T;    // 현재 선로의 급전 방식

    // 비교 연산자 정의 (cnt 기준 오름차순 정렬)
    bool operator<(const info& other) const {
        return cnt > other.cnt;  // 최소 힙을 만들기 위해 cnt가 작은 것이 먼저 나오도록 함
    }
};

int N, M, A, B;
map<int, vector<pair<int, int>>> arr;
vector<int> isVisited;

void Dijk() {
    priority_queue<info> pq;
    pq.push({0, A, -1});  // 시작 역에서의 절연 횟수는 0, 급전 방식은 -1 (아직 없음)
    isVisited[A] = 0;

    while (!pq.empty()) {
        int curr_cnt = pq.top().cnt;
        int curr_S = pq.top().S;
        int curr_T = pq.top().T;
        pq.pop();

        // 현재 저장된 절연 횟수가 이미 더 작은 경우 스킵
        if (isVisited[curr_S] < curr_cnt) {
            continue;
        }

        for (const auto& next : arr[curr_S]) {
            int next_S = next.first;
            int next_T = next.second;
            int new_cnt = curr_cnt;

            // 시작점이 아닌 경우 급전 방식이 바뀌는지 체크
            if (curr_T != -1 && curr_T != next_T)
                new_cnt++;

            // 더 적은 절연 횟수로 방문할 수 있다면 업데이트
            if (isVisited[next_S] > new_cnt) {
                isVisited[next_S] = new_cnt;
                pq.push({new_cnt, next_S, next_T});
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        arr[i] = vector<pair<int, int>>();
    }

    for (int i = 0; i < M; i++) {
        int S, E, T;
        cin >> S >> E >> T;
        arr[S].push_back({E, T});
        arr[E].push_back({S, T});
    }

    cin >> A >> B;

    isVisited.resize(N + 1, INT_MAX);  // 방문 체크 배열을 큰 값으로 초기화

    Dijk();  // 다익스트라 알고리즘 실행

    cout << isVisited[B] << endl;  // B번 역까지의 최소 절연 횟수 출력
}
