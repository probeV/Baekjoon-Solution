#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 21

int N,M,K;
int arr[MAXSIZE][MAXSIZE], score[MAXSIZE][MAXSIZE];
vector<pair<int,  int> > mv = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // 동, 남, 서, 북

int dice_y[4]={2,1,5,6}; // 앞쪽, 위쪽, 뒷쪽, 아래쪽
int dice_x[3]={4,1,3}; // 왼쪽, 위쪽, 오른쪽

int res = 0;

void BFS(){
    bool isVisited[MAXSIZE][MAXSIZE];
    memset(isVisited, false, sizeof(isVisited));

    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){

            //이미 방문 했다면 패스
            if(isVisited[y][x]) continue;

            queue<pair<int, int> > q;
            queue<pair<int, int> > score_q;
            int target = arr[y][x];
            int cnt = 1;

            q.push({x,y});
            isVisited[y][x]=true;

            while(!q.empty()){
                int curr_x = q.front().first;
                int curr_y = q.front().second;
                score_q.push(q.front());
                q.pop();

                // 주변 체크
                for(int i=0;i<4;i++){
                    int next_x = curr_x + mv[i].first;
                    int next_y = curr_y + mv[i].second;

                    // 범위 넘어가면 x 
                    if(next_x < 1 || next_y < 1 || next_x > M || next_y > N) continue;

                    // 이미 방문 했으면 x 
                    if(isVisited[next_y][next_x]) continue;

                    // target과 같은 수 일 때
                    if(target == arr[next_y][next_x]){
                        q.push({next_x, next_y});
                        isVisited[next_y][next_x]=true;
                        cnt++;
                    }
                }
            }

            // 점수판 초기화
            while(!score_q.empty()){
                int curr_x = score_q.front().first;
                int curr_y = score_q.front().second;
                score_q.pop();

                score[curr_y][curr_x] = target*cnt;
            }
        }
    }
}

void Dice(int dir){
    int temp;

    switch (dir) {
        case 0: // 동
            // 맨 밑 가져오기
            temp = dice_y[3];

            // 회전
            dice_y[3]=dice_x[2];
            dice_x[2]=dice_x[1];
            dice_x[1]=dice_x[0];
            dice_x[0]=temp;

            // 맨 위 동기화
            dice_y[1]=dice_x[1];

            break;
        case 1: // 남
            // 맨 밑 가져오기
            temp = dice_y[3];

            // 회전
            dice_y[3]=dice_y[2];
            dice_y[2]=dice_y[1];
            dice_y[1]=dice_y[0];
            dice_y[0]=temp;

            // 맨 위 동기화
            dice_x[1]=dice_y[1];

            break;
        case 2: // 서
            // 맨 밑 가져오기
            temp = dice_y[3];

            // 회전
            dice_y[3]=dice_x[0];
            dice_x[0]=dice_x[1];
            dice_x[1]=dice_x[2];
            dice_x[2]=temp;

            // 맨 위 동기화
            dice_y[1]=dice_x[1];

            break;
        case 3: // 북
            // 맨 밑 가져오기
            temp = dice_y[3];

            // 회전
            dice_y[3]=dice_y[0];
            dice_y[0]=dice_y[1];
            dice_y[1]=dice_y[2];
            dice_y[2]=temp;

            // 맨 위 동기화
            dice_x[1]=dice_y[1];

            break;
    }

}

int main(){
    cin >> N >> M >> K;

    // 배열 입력
    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            cin >> arr[y][x];
        }
    }

    // 배열 점수판 계산
    BFS();

    int x=1, y=1;
    int dir = 0;

    // 움직이기
    for(int i=1;i<=K;i++){
        

        // 현재 이동방향에 맞춰 이동하기
        int next_x = x + mv[dir].first;
        int next_y = y + mv[dir].second;

        // 범위 넘어갔으면 이동 방향 변경
        if(next_x < 1 || next_y < 1 || next_x > M || next_y > N){
            dir = (dir+2)%4;
            next_x = x + mv[dir].first;
            next_y = y + mv[dir].second;
        }

        x = next_x;
        y = next_y;

        // 현재 이동방향에 맞춰 주사위 회전
        Dice(dir);

        // cout << y << x << "\n";
        // cout << dice_y[0] << dice_y[1] << dice_y[2] << dice_y[3] <<"\n";
        // cout << dice_x[0] << dice_x[1] << dice_x[2] << "\n\n";

        // 점수 획득
        res += score[y][x];

        // 다음 이동 방향 결정
        if(dice_y[3] > arr[y][x]){
            dir = (dir+1)%4;
        }
        else if(dice_y[3] < arr[y][x]){
            dir = (dir+3)%4;
        }
        
    }

    cout << res;
}