#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int, bool> a;
vector<int> b;

int main() {
    // N 입력 받기
    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        a[temp] = true;
    }

    // M 입력 받기
    cin >> M;
    for(int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    // 'a' 맵과 'b' 벡터를 이용한 추가적인 처리 로직을 여기에 추가
    // 예: 'b' 벡터의 각 요소가 'a' 맵에 존재하는지 확인

    for(int i = 0; i < M; i++) {
        if(a.find(b[i]) != a.end()) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }

    return 0;
}
