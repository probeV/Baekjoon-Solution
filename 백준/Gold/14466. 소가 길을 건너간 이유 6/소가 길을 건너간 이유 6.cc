#include<bits/stdc++.h>

using namespace std;

int N,K,R,res;
vector<vector<vector<pair<int,int> > > > ban;
vector<pair<int, int> > arr;
vector<pair<int, int> > mv = {{1,0}, {0,-1}, {-1,0}, {0,1}};

void BFS(int start_x, int start_y, int end_x, int end_y){
    queue<pair<int, int> > q;
    vector<vector<bool> > isVisited(N+1, vector<bool>(N+1, false));

    q.push({start_x, start_y});
    isVisited[start_x][start_y]=true;

    while (!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int next_x = curr_x + mv[i].first;
            int next_y = curr_y + mv[i].second;

            // 범위 넘어가면 건너뛰기
            if(next_x < 1 || next_x > N || next_y < 1 || next_y > N) continue;

            // 이미 방문 했다면 건너 뛰기
            if(isVisited[next_x][next_y]) continue;

            // 길이 있으면 건너뛰기
            bool isRoad = false;
            for(int j=0;j<ban[curr_x][curr_y].size();j++){
                // 길이 있으면
                if(ban[curr_x][curr_y][j].first == next_x && ban[curr_x][curr_y][j].second == next_y){
                    isRoad=true; break;
                }
            }
            if(isRoad) continue;
            
            q.push({next_x, next_y});
            isVisited[next_x][next_y] = true;
        }

    }

    // 목표에 길을 사용하지 않고 도달하지못했는가?
    if(!isVisited[end_x][end_y]) res++;
    
}

int main(){
    cin >> N >> K >> R;

    // vector 크기 초기화
    ban.resize(N+1, vector<vector<pair<int, int> > >(N+1, vector<pair<int, int> >()));

    // 길 정보
    for(int i=1;i<=R;i++){
        int r,c,rr,cc;
        cin >> r >> c >> rr >> cc;

        ban[r][c].push_back({rr,cc});
        ban[rr][cc].push_back({r,c});
    }

    // 소 정보
    for(int i=1;i<=K;i++){
        int x,y;
        cin >> x >> y;

        arr.push_back({x,y});
    }

    // for(int y=1;y<=K;y++){
    //     for(int x=1;x<=K;x++){
    //         for(int z=0;z<ban[x][y].size();z++){
    //             cout << x << "," << y << " : " <<ban[x][y][z].first << "," << ban[x][y][z].second << "\n";
    //         }
    //     }
    // }

    for(int i=0;i<K;i++){
        for(int j=i+1;j<K;j++){
            BFS(arr[i].first, arr[i].second, arr[j].first, arr[j].second);
        }
    }

    cout << res;
}