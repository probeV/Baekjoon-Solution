#include <bits/stdc++.h>    

using namespace std;

typedef struct idx{
    int top;
    int right;
    int left;
}idx;


vector<string> w(5);
vector<idx> info(5);

int K;

int main(){
    for(int i=1;i<=4;i++){
        cin >> w[i];
        info[i].top=0; info[i].right=2; info[i].left=6;
    }
    cin >> K;

    int N, D, curr_D;
    for(int i=1;i<=K;i++){
        cin >> N >> D;

        vector<int> rotation(5);

        //왼쪽
        curr_D = D;
        for(int curr=N;curr>1;curr--){
            int next=curr-1;
            rotation[curr]=curr_D;

            //다음 바퀴 생각
            if(w[curr][info[curr].left] != w[next][info[next].right]){
                curr_D=curr_D*-1;
            }
            else{
                curr_D=0;
            }
        }
        rotation[1]=curr_D;

        //오른쪽
        curr_D = D;
        for(int curr=N;curr<4;curr++){
            int next=curr+1;
            rotation[curr]=curr_D;

            if(w[curr][info[curr].right] != w[next][info[next].left]){
                curr_D=curr_D*-1;
            }
            else{
                curr_D=0;
            }
        }
        rotation[4]=curr_D;

        // 회전
        for (int curr = 1; curr <= 4; curr++)
        {
            // 시계 방향
            if (rotation[curr] == 1)
            {
                info[curr].top = (info[curr].top + 7) % 8;
                info[curr].right = (info[curr].right + 7) % 8;
                info[curr].left = (info[curr].left + 7) % 8;
            }
            // 반시계 방향
            else if (rotation[curr] == -1)
            {
                info[curr].top = (info[curr].top + 1) % 8;
                info[curr].right = (info[curr].right + 1) % 8;
                info[curr].left = (info[curr].left + 1) % 8;
            }
        }
    }

    int res=0;
    for(int i=1;i<=4;i++){
        if(w[i][info[i].top]=='1'){ //S극 일때
            res+=(int)pow(2,i-1);
        }
    }

    cout << res;
}