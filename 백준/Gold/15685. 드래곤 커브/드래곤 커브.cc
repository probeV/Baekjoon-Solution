#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 101

int N;
vector<pair<int, int>> mv = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // 우, 위, 왼, 아래

bool arr[MAXSIZE][MAXSIZE];
bool isVisited[MAXSIZE][MAXSIZE];
vector<int> vec;

int res = 0;

int main(){
    cin >> N;

    for (int i = 0; i < N; i++){
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        // 각 세대를 진행하며 자라는 벡터 인덱스 값 저장
        vec.push_back(d);
        for (int k = 1; k <= g; k++){

            // 다음 세대 구하기
            for (int h = vec.size() - 1; h >= 0; h--){
                int curr_d = (vec[h] + 1) % 4;

                vec.push_back(curr_d);
            }
        }

        // vec에 들어있는 벡터 인덱스 값을 기반으로 좌표 값 구하기
        arr[y][x] = true;
        int temp_x = x;
        int temp_y = y;
        for (int k = 0; k < vec.size(); k++){
            // cout << vec[k] << "\n";
            temp_x = temp_x + mv[vec[k]].first;
            temp_y = temp_y + mv[vec[k]].second;
            arr[temp_y][temp_x] = true;
        }

        // vec 초기화
        vec.clear();
    }

    // for(int y=0;y<=10;y++){
    //     for(int x=0;x<=10;x++){
    //         cout << arr[y][x] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n\n";

    // cout << x << y << "\n";

    // 각 좌표에서 정사각형 찾기
    for (int y = 0; y < MAXSIZE; y++){
        for (int x = 0; x < MAXSIZE; x++){
            if (isVisited[y][x] || !arr[y][x]) continue;

            queue<pair<int, int>> q;

            q.push({x, y});
            isVisited[y][x] = true;

            while (!q.empty()){
                int curr_x = q.front().first;
                int curr_y = q.front().second;
                q.pop();

                // 다음 좌표 큐에 저장
                for (int i = 0; i < 4; i++){
                    int next_x = curr_x + mv[i].first;
                    int next_y = curr_y + mv[i].second;

                    // 범위가 넘어가면
                    if (next_x < 0 || next_y < 0 || next_x >= MAXSIZE || next_y >= MAXSIZE)
                        continue;

                    // 이미 방문하지 않았고, 존재하는 좌표이면
                    if (!isVisited[next_y][next_x] && arr[next_y][next_x])
                    {
                        q.push({next_x, next_y});
                        isVisited[next_y][next_x] = true;
                    }
                }

                // 주변 정사각형 찾기
                bool right = false, up = false, left = false, down = false;

                for (int i = 0; i < 4; i++)
                {
                    int check_x = curr_x + mv[i].first;
                    int check_y = curr_y + mv[i].second;
                    int check_res = arr[check_y][check_x] == true;

                    if (check_x < 0 || check_y < 0 || check_x >= MAXSIZE || check_y >= MAXSIZE)
                        continue;

                    switch (i)
                    {
                    case 0:
                        right = check_res;
                        break;
                    case 1:
                        up = check_res;
                        break;
                    case 2:
                        left = check_res;
                        break;
                    case 3:
                        down = check_res;
                        break;
                    }
                }

                // 오른쪽 위 정사각형
                if (up && right)
                {
                    // 대각선 좌표에도 있다면 정사각형 완성
                    if (arr[curr_y - 1][curr_x + 1])
                    {
                        res++;
                    }
                }

                // 오른쪽 아래 정사각형
                if (right && down)
                {
                    if (arr[curr_y + 1][curr_x + 1])
                    {
                        res++;
                    }
                }

                // 왼쪽 아래 정사각형
                if (down && left)
                {
                    if (arr[curr_y + 1][curr_x - 1])
                    {
                        res++;
                    }
                }

                // 왼쪽 위 정사각형
                if (left && up)
                {
                    if (arr[curr_y - 1][curr_x - 1])
                    {
                        res++;
                    }
                }

                // 정사각형 찾았으면 존재하는 좌표에서 삭제
                arr[curr_y][curr_x] = false;
            }
        }
    }

    cout << res;
}