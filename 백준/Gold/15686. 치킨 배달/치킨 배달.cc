#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 51

int N, M;

int board[MAXSIZE][MAXSIZE];
vector<pair<int, int>> home;
vector<pair<pair<int, int>, bool>> chicken;

int result = INT_MAX;

void DFS(int count, int idx) {
    //치킨집 M개 선택완료
    if (count == M) {
        vector<int> res(home.size(), INT_MAX);
        
        //집에서 M개 중의 치킨집 중 가까운 곳 찾기
        for (int i = 0; i < home.size(); i++) {
            int home_r = home[i].first;
            int home_c = home[i].second;


            for (int j = 0; j < chicken.size(); j++) {
                int chi_r = chicken[j].first.first;
                int chi_c = chicken[j].first.second;

                //선택된 치킨집 일 때
                if (chicken[j].second) {
                    if (res[i] > abs(home_r - chi_r) + abs(home_c - chi_c)) {
                        res[i] = abs(home_r - chi_r) + abs(home_c - chi_c);
                    }
                }
            }
        }

        //M개 선택된 치킨집의 치킨 거리 구하기
        int temp = 0;
        for (int i = 0; i < res.size(); i++) {
            temp += res[i];
        }

        //최솟값이라면 저장 
        if (result > temp) {
            result = temp;
        }

    }

    for (int i = idx;i < chicken.size(); i++) {
        if (!chicken[i].second) {
            chicken[i].second = true;
            DFS(count + 1, i);
            chicken[i].second = false;
        }
    }
}

int main(void) {
    cin >> N >> M;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> board[r][c];

            if (board[r][c] == 1) {
                home.push_back({ r,c });
            }
            else if (board[r][c] == 2) {
                chicken.push_back({ {r,c}, false });
            }
        }
    }


    //치킨 집 M개 선택
    DFS(0, 0);

    cout << result;
}