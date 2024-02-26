#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 100001

int N, K;
int res[MAXSIZE];
queue<int> q;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    fill_n(res, MAXSIZE, INT_MAX);
    q.push(N);
    res[N]=0;

    while(!q.empty()){
        int cur_pos = q.front();
        int cur_time = res[cur_pos];
        q.pop();

        // // 도착 했을 때
        // if(cur_pos == K && res[cur_pos] >= cur_time){
        //     res[cur_pos]=cur_time;
        //     continue;
        // }

        //cout << cur_pos << cur_time << "\n";

        // 이동  
        if(cur_pos*2 < MAXSIZE && res[cur_pos*2] > cur_time && cur_pos != 0){
            res[cur_pos*2]=cur_time;
            q.push(cur_pos*2);
        } 
        if(cur_pos+1 < MAXSIZE && res[cur_pos+1] > cur_time+1){
            res[cur_pos+1]=cur_time+1;
            q.push(cur_pos+1);
        }
        if(cur_pos-1 >= 0 && res[cur_pos-1] > cur_time+1){
            res[cur_pos-1]=cur_time+1;
            q.push(cur_pos-1);
        }
    }
    
    cout << res[K];
}

