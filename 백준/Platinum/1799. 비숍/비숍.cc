#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, maxBishops = 0;
vector<vector<int>> board;
vector<bool> leftDiag, rightDiag; // 대각선 방문 여부

// 특정 색상 그룹에 대해 백트래킹 탐색
void placeBishops(int row, int col, int count, bool isBlack) {
    // 행을 넘어갔으면 다음 열로 이동
    if (col >= N) {
        row++;
        col = (col % 2 == 0) ? 1 : 0; // 색상 교차
    }
    if (row >= N) {
        maxBishops = max(maxBishops, count); // 최대값 갱신
        return;
    }

    if (board[row][col] == 1 && !leftDiag[row + col] && !rightDiag[row - col + (N - 1)]) {
        // 비숍을 놓을 수 있으면 놓아본다
        leftDiag[row + col] = true;
        rightDiag[row - col + (N - 1)] = true;
        placeBishops(row, col + 2, count + 1, isBlack); // 다음 칸 탐색
        leftDiag[row + col] = false;
        rightDiag[row - col + (N - 1)] = false;
    }

    // 비숍을 놓지 않는 경우
    placeBishops(row, col + 2, count, isBlack);
}

int main() {
    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 대각선 방문 여부 초기화
    leftDiag.resize(2 * N - 1, false);
    rightDiag.resize(2 * N - 1, false);

    // 흑색 칸 탐색
    maxBishops = 0;
    placeBishops(0, 0, 0, true);
    int blackMax = maxBishops;

    // 백색 칸 탐색
    maxBishops = 0;
    placeBishops(0, 1, 0, false);
    int whiteMax = maxBishops;

    // 결과 출력
    cout << blackMax + whiteMax << endl;

    return 0;
}
