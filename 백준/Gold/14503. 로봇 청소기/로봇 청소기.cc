#include <bits/stdc++.h>

using namespace std;

int N, M, res=1, curr_x, curr_y, D;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

bool fun1(vector<vector<int> > &board){
    for (int i = 0; i < 4; i++)
    {
        D = (D + 3) % 4;
        int next_x = curr_x + dx[D];
        int next_y = curr_y + dy[D];

        if (board[next_y][next_x] == 0)
        {
            board[next_y][next_x] = -1;
            curr_x = next_x;
            curr_y = next_y;

            //cout << "청소중" << curr_x << curr_y << "\n\n";

            res++;
            return true;
        }
    }

    // 후진 불가 -> 종료
    if(board[curr_y - dy[D]][curr_x - dx[D]] == 1){
        //cout << curr_y << curr_x;
        return false;
    }
    // 후진 가능
    else
    {
        curr_x = curr_x - dx[D];
        curr_y = curr_y - dy[D];
    }

    //cout << curr_x << curr_y << "\n\n";
    return true;
}

int main(){
    cin >> N >> M >> curr_y >> curr_x >> D;

    curr_y; curr_x;

    vector<vector<int> > board(N);

    int tmp;
    for(int y=0;y<N;y++){
        for(int x=0;x<M;x++){
            cin >> tmp;
            board[y].push_back(tmp);
        }
    }

    board[curr_y][curr_x]=-1;

    while(fun1(board)){}

    cout << res;
}