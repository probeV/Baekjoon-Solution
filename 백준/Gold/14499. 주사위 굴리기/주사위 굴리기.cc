#include <bits/stdc++.h>

using namespace std;

vector<int> movement;

int dice[4][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

int N, M, x, y, K;

int main(){
    cin >> N >> M >> y >> x >> K;

    vector<vector<int>> board(N);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int tmp;
            cin >> tmp;
            board[i].push_back(tmp);
        }
    }

    for(int i=0;i<K;i++){
        int tmp;
        cin >> tmp;
        movement.push_back(tmp);
    }

    for(int i=0;i<K;i++){
        int next=movement[i]-1;
        int next_x = x + dx[next];
        int next_y = y + dy[next];

        //지도 바깥으로 나갔을 때 
        if(next_x >= M || next_y >= N || next_x < 0 || next_y < 0){
            continue;
        }

        //cout << next_x << " " << next_y << "->" << board[next_y][next_x] << "\n";

        //주사위 움직이기
        int first;
        switch (next){
            case 0: //동
                first = dice[3][1];
                dice[3][1]=dice[1][0];
                dice[1][0]=dice[1][1];
                dice[1][1]=dice[1][2];
                dice[1][2]=first;
                break;
            case 1: //서
                first = dice[3][1];
                dice[3][1]=dice[1][2];
                dice[1][2]=dice[1][1];
                dice[1][1]=dice[1][0];
                dice[1][0]=first;
                break;
            case 2: //북
                first = dice[0][1];
                dice[0][1]=dice[1][1];
                dice[1][1]=dice[2][1];
                dice[2][1]=dice[3][1];
                dice[3][1]=first;
                break;
            case 3: //남
                first = dice[3][1];
                dice[3][1]=dice[2][1];
                dice[2][1]=dice[1][1];
                dice[1][1]=dice[0][1];
                dice[0][1]=first;
                break;
        }

        //변경 사항 저장
        if(board[next_y][next_x]==0){
            board[next_y][next_x]=dice[3][1];
        }
        else if(board[next_y][next_x]!=0){
            dice[3][1]=board[next_y][next_x];
            board[next_y][next_x]=0;
        }

        x=next_x;
        y=next_y;

        cout << dice[1][1] << "\n";

    }
}