#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 101

deque<pair<int, int>> dummy;
map<int, char> rotation;

char board[MAXSIZE][MAXSIZE];

int cnt=0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, L;

    cin >> N >> K;
    //사과 위치
    for(int i=1;i<=K;i++){
        int x, y;
        cin >> x >> y;
        board[y][x]='A';
    }
    //뱀의 방향 변환 횟수
    cin >> L;
    //방향 변환
    for(int i=1;i<=L;i++){
        int time; char dir;
        cin >> time >> dir;
        rotation.insert({time, dir});
    }

    dummy.push_back({1,1});
    board[1][1]='*';

    int idx=0;
    bool isPlay=true;
    while(1){
            cnt++;
            int x = dummy[0].first;
            int y = dummy[0].second;

            int next_x=x+dx[idx];
            int next_y=y+dy[idx];
            
            //벽 일 때
            if(next_x > N || next_y > N || next_x <=0 || next_y <=0){
                break;
            }
            //몸 일 때
            else if(board[next_x][next_y]=='*'){
                break;
            }

            //사과 일 때
            if(board[next_x][next_y]=='A'){
                board[next_x][next_y]='*';
                dummy.push_front({next_x, next_y});
            }
            //사과 아닐 때
            else{
                board[next_x][next_y]='*';
                board[dummy.back().first][dummy.back().second]=' ';

                dummy.push_front({next_x, next_y});
                dummy.pop_back();
            }

            //방향 변경
            if(rotation.find(cnt) != rotation.end()){
                if(rotation[cnt]=='D'){
                    idx=(idx+1)%4;
                }
                else if(rotation[cnt]=='L'){
                    idx=(idx+3)%4;
                }
            }
        }
    cout << cnt;
}