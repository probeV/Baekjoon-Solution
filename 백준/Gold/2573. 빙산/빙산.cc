#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int> > arr;
vector<pair<int, int> > mv={{1,0}, {0,-1}, {-1,0}, {0,1}};

bool check(){
    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            if(arr[y][x]!=0){
                return true;
            }
            else if(y==N && x==M){
                return false;
            }
        }
    }
}

void BFS(int x, int y, vector<vector<bool> > &isVisited){
    queue<pair<int,int>> q;
    q.push({x,y});
    isVisited[y][x] = true;

    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int next_x = curr_x + mv[i].first;
            int next_y = curr_y + mv[i].second;

            if(next_x <= 0 || next_y <=0 || next_x > M || next_y > N) continue;

            if(!isVisited[next_y][next_x] && arr[next_y][next_x] != 0){
                q.push({next_x, next_y});
                isVisited[next_y][next_x]=true;
            }
        }

    }
}

int main(){
    cin >> N >> M;

    arr.resize(N+1, vector<int>(M+1));

    for(int y=1;y<=N;y++){
        for(int x=1;x<=M;x++){
            cin >> arr[y][x];
        }
    }

    int cnt=0;
    bool isIce=true;
    while(isIce){
        cnt++;

        vector<vector<int> > melt(N+1, vector<int>(M+1));

        // 빙하 녹이기
        for(int y=1;y<=N;y++){
            for(int x=1;x<=M;x++){

                if(arr[y][x] != 0){
                    int water=0;
                    for(int i=0;i<4;i++){
                        int next_x = x + mv[i].first;
                        int next_y = y + mv[i].second;

                        if(next_x <= 0 || next_y <=0 || next_x > M || next_y > N) continue;

                        if(arr[next_y][next_x] == 0) water++;
                    }

                    melt[y][x]=water;
                }
                
            }
        }

        for(int y=1;y<=N;y++){
            for(int x=1;x<=M;x++){
                arr[y][x] = arr[y][x] - melt[y][x];
                if(arr[y][x] < 0) arr[y][x]=0;
            }
        }

        // BFS 진행하여 덩어리 체크
        vector<vector<bool> > isVisited(N+1, vector<bool>(M+1, false));

        int ice=0;
        for(int y=1;y<=N;y++){
            for(int x=1;x<=M;x++){
                if(arr[y][x]!=0 && !isVisited[y][x]){
                    BFS(x,y,isVisited);
                    ice++;
                } 
            }
        }

        if(ice>=2) break;

        isIce=check();

        if(!isIce) cnt=0;

    }

    cout << cnt;
}
