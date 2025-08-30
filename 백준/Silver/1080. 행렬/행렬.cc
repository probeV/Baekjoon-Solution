#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> A(N), B(N);
    
    // 행렬 A 입력
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // 행렬 B 입력
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    int operations = 0;
    
    // 좌상단부터 (N-2, M-2)까지 스캔
    for(int i = 0; i <= N-3; i++) {
        for(int j = 0; j <= M-3; j++) {
            // 현재 위치가 다르면 3x3 연산 수행
            if(A[i][j] != B[i][j]) {
                operations++;
                
                // 3x3 영역 뒤집기
                for(int di = 0; di < 3; di++) {
                    for(int dj = 0; dj < 3; dj++) {
                        if(A[i+di][j+dj] == '0') {
                            A[i+di][j+dj] = '1';
                        } else {
                            A[i+di][j+dj] = '0';
                        }
                    }
                }
            }
        }
    }
    
    // 최종 확인: A와 B가 같은지 검사
    bool possible = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] != B[i][j]) {
                possible = false;
                break;
            }
        }
        if(!possible) break;
    }
    
    if(possible) {
        cout << operations << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}