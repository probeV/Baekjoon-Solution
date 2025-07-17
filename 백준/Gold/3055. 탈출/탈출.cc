#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > mv= {{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int R,C;
    cin >> R >> C;

    vector<vector<char> > arr(R+1, vector<char>(C+1));
    for(int y=1;y<=R;y++){
        for(int x=1;x<=C;x++){
            cin >> arr[y][x];
        }
    }   // . 비어있음, * 물이 차 있음, X 돌, D 비버의 굴, S 고슴도치 

    // BFS
    queue<pair<int, int> > q, water_q;
    vector<vector<bool> > isVisited(R+1, vector<bool>(C+1, false));
    for(int y=1;y<=R;y++){
        for(int x=1;x<=C;x++){
            if(arr[y][x]=='S'){ // 고슴도치 위치
                q.push({x,y});
                isVisited[y][x]=true;
            }
            else if(arr[y][x]=='*'){ // 물 위치 
                water_q.push({x,y});
            }
        }
    } 

    int ans=0;
    while(!q.empty()){
        int water_size = water_q.size();
        for(int i=1;i<=water_size;i++){ // 물 이동 예정인 곳은 고슴도치가 못감, 즉, 물 먼저 이동
            int curr_water_x = water_q.front().first; int curr_water_y = water_q.front().second;
            water_q.pop();

            for(int i=0;i<4;i++){   
                int next_water_x = curr_water_x + mv[i].first;
                int next_water_y = curr_water_y + mv[i].second;

                if(next_water_x > C || next_water_y > R || next_water_x < 1 || next_water_y < 1) // 범위를 넘어가면
                    continue;

                if(arr[next_water_y][next_water_x]=='X' || arr[next_water_y][next_water_x]=='D' || arr[next_water_y][next_water_x]=='*') // 돌이 있거나, 비버 소골이 있으면 
                    continue;

                water_q.push({next_water_x, next_water_y});
                arr[next_water_y][next_water_x]='*';
            }
        }

        int s_size = q.size();
        for(int i=1;i<=s_size;i++){
            int curr_x = q.front().first; 
            int curr_y = q.front().second;
            q.pop();
            if(arr[curr_y][curr_x]=='D'){
                cout << ans;
                return 0;
            }
            for(int i=0;i<4;i++){   // 고슴도치 이동
                int next_x = curr_x + mv[i].first;
                int next_y = curr_y + mv[i].second;

                if(next_x > C || next_y > R || next_x < 1 || next_y < 1) // 범위를 넘어가면
                    continue;

                if(arr[next_y][next_x]=='X' || arr[next_y][next_x]=='*') // 돌이 있거나, 물이 차있으면
                    continue;

                if(!isVisited[next_y][next_x]){ // 아직 고슴도치가 방문하지 않았으면
                    q.push({next_x, next_y});
                    isVisited[next_y][next_x]=true;
                }
            }
        }

        ans++;
    }

    cout <<  "KAKTUS";
    return 0;
}   