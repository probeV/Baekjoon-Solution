#include  <bits/stdc++.h>

using namespace std;

#define MAXSIZE 1003

int R, C;
char board[MAXSIZE][MAXSIZE];

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

queue<pair<int,int>> qF;
queue<pair<int,int>> qJ;

int res=0;

bool BFS(int x, int y){

    while(!qJ.empty() || !qF.empty()){

        int Jnum = qJ.size();
        int Fnum = qF.size();
        
        res++;

        int curr_x, curr_y;
        int next_x, next_y;

        for(int i=1;i<=Jnum;i++){
            curr_x = qJ.front().first;
            curr_y = qJ.front().second;

            qJ.pop();

            //원래 못가는 곳
            if(board[curr_y][curr_x] == 'F'){
                continue;
            }

            //탈출 성공
            if(curr_x==C || curr_y==R || curr_x==1 || curr_y==1){
                return true;
            }

            
            //이동
            for(int j=0;j<4;j++){
                next_x= curr_x + dx[j];
                next_y= curr_y + dy[j];

                if(next_x <= 0 || next_y<=0 || next_x > C || next_y > R){
                    continue;
                }

                if(board[next_y][next_x]=='.'){
                    qJ.push({next_x, next_y});
                    board[next_y][next_x]='J';
                }
            }
        }

        for(int i=1;i<=Fnum;i++){
            curr_x = qF.front().first;
            curr_y = qF.front().second;

            qF.pop();

            //이동
            for(int j=0;j<4;j++){
                next_x= curr_x + dx[j];
                next_y= curr_y + dy[j];

                if(next_x <= 0 || next_y<=0 || next_x > C || next_y > R){
                    continue;
                }

                if(board[next_y][next_x]!='#' && board[next_y][next_x]!='F'){
                    qF.push({next_x, next_y});
                    board[next_y][next_x]='F';
                }
            }
        }

    }
    return false;
}

int main(){
    cin >> R >> C;

    int x, y;

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> board[i][j];
            
            if(board[i][j]=='F'){
                qF.push({j,i});
            }
            else if(board[i][j]=='J'){
                qJ.push({j,i});
            }
        }
    }

    if(BFS(x,y)){
        cout << res;
    }
    else{
        cout <<"IMPOSSIBLE";
    }

}