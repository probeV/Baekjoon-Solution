#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 125

int N, idx=1;

priority_queue<pair<int, pair<int, int>> > q;

int weight[MAXSIZE][MAXSIZE];
int dist[MAXSIZE][MAXSIZE];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        cin >> N;

        if(N==0) break;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> weight[i][j];
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dist[i][j] = INT_MAX;
            }
        }

        q.push({-weight[0][0], {0,0}});
        dist[0][0]=weight[0][0];

        while(!q.empty()){
            int curr_x = q.top().second.first;
            int curr_y = q.top().second.second;
            int curr_w = -q.top().first;
            q.pop();

            if(dist[curr_y][curr_x] < curr_w) continue;

            for(int i=0;i<4;i++){
                int next_x = curr_x + dx[i];
                int next_y = curr_y + dy[i];

                if(next_x >= N || next_y >= N || next_x < 0 || next_y < 0){
                    continue;
                }

                int next_w = curr_w + weight[next_y][next_x];

                if(next_w < dist[next_y][next_x]){
                    dist[next_y][next_x] = next_w;
                    q.push({-next_w,  {next_x, next_y}});
                }
            }
            //cout << res[N-1][N-1] << " ";
        }

        cout << "Problem " << idx << ": " << dist[N-1][N-1]  <<"\n";
        idx++;
    }
}