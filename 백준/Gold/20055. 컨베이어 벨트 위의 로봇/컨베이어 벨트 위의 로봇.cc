#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 1001

int N, K;
deque<int> board;
deque<bool> isRobot;

bool isPlay(){
    int cnt=0;
    for(int i=0;i<2*N;i++){
        if(board[i]==0) cnt++;
    }

    if(cnt >= K) return false;
    else return true;
}

int main(){
    cin >> N >> K;
    
    int tmp;
    for(int i=0;i<2*N;i++){
        cin >> tmp;
        board.push_back(tmp);
        isRobot.push_back(false);
    }

    int res=0;

    while(isPlay()){
        //컨베이어 벨트 회전
        int temp1; bool temp2;
        temp1=board[2*N-1];
        temp2=isRobot[2*N-1];

        board.pop_back();
        board.push_front(temp1);
        isRobot.pop_back();
        isRobot.push_front(temp2);

        //로봇 내리는 위치에 있다면 내리기
        if(isRobot[N-1]){
            isRobot[N-1]=false;
        }

        //로봇 한 칸 이동하기
        for(int i=N-1;i>0;i--){
            if(!isRobot[i] && isRobot[i-1] && board[i] >= 1){
                isRobot[i]=true;
                isRobot[i-1]=false;

                board[i]--;
            }
        }


        //올리는게 가능하면 로봇 올리기
        if(board[0] != 0){
            board[0]--;
            isRobot[0]=true;
        }

        //로봇 내리는 위치에 있다면 내리기
        if(isRobot[N-1]){
            isRobot[N-1]=false;
        }
        
        res++;
    }

    cout << res;
}