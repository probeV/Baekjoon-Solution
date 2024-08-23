#include<bits/stdc++.h>

using namespace std;

int N, Q;
vector<int> L;
vector<vector<int> > ice;
vector<pair<int, int> > mv = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int main(){
    cin >> N >> Q;

    // ice 입력
    int ice_size = (int)pow(2, N);
    ice.resize(ice_size+1, vector<int>(ice_size+1));
    for(int y=1;y<=ice_size;y++){
        for(int x=1;x<=ice_size;x++){
            cin >> ice[y][x];
        }
    }

    // L 입력
    L.resize(Q+1);
    for(int i=1;i<=Q;i++){
        cin >> L[i];
    }

    // Q번 진행
    for(int i=1;i<=Q;i++){
        int sub_ice_size = (int)pow(2, L[i]);

        // 2^L x 2^L 시계방향 90도 회전
        for(int y=1;y<ice_size;y=y+sub_ice_size){
            for(int x=1;x<ice_size;x=x+sub_ice_size){

                vector<vector<int> > sub_ice(sub_ice_size+1, vector<int>(sub_ice_size+1));
                for(int dx=0;dx<sub_ice_size;dx++){
                    for(int dy=0;dy<sub_ice_size;dy++){
                        int sub_next_x = 1 + dx;
                        int sub_next_y = 1 + dy;

                        int next_x = x + dy;
                        int next_y = (y + sub_ice_size - 1) - dx;

                        sub_ice[sub_next_y][sub_next_x]=ice[next_y][next_x];
                    }
                }

                for(int dx=0;dx<sub_ice_size;dx++){
                    for(int dy=0;dy<sub_ice_size;dy++){
                        int sub_next_x = 1 + dx;
                        int sub_next_y = 1 + dy;

                        int next_x = x + dx;
                        int next_y = y + dy;

                        ice[next_y][next_x]=sub_ice[sub_next_y][sub_next_x];
                    }
                }
            }
        }

        // 얼음 녹기
        vector<vector<bool> > isMelted(ice_size+1, vector<bool>(ice_size+1, false));
        for(int curr_y=1;curr_y<=ice_size;curr_y++){
            for(int curr_x=1;curr_x<=ice_size;curr_x++){
                
                // 인접 얼음 확인
                int empty=0;
                for(int i=0;i<4;i++){
                    int next_x = curr_x + mv[i].first;
                    int next_y = curr_y + mv[i].second;

                    // 범위 넘어갈떄
                    if(next_x < 1 || next_y < 1 || next_x > ice_size || next_y > ice_size){
                        empty++;
                        continue;
                    }

                    if(ice[next_y][next_x]==0) empty++;
                }

                if(empty >= 2) isMelted[curr_y][curr_x] = true;
            }
        }

        for(int curr_y=1;curr_y<=ice_size;curr_y++){
            for(int curr_x=1;curr_x<=ice_size;curr_x++){

                if(isMelted[curr_y][curr_x] && ice[curr_y][curr_x] != 0) ice[curr_y][curr_x]--;
            }
        }
    }

    // 남아 있는 얼음 합 구하기
    int ice_sum=0;
    for(int curr_y=1;curr_y<=ice_size;curr_y++){
        for(int curr_x=1;curr_x<=ice_size;curr_x++){
            ice_sum += ice[curr_y][curr_x];
        }
    }
    cout << ice_sum << "\n";

    // for(int curr_y=1;curr_y<=ice_size;curr_y++){
    //     for(int curr_x=1;curr_x<=ice_size;curr_x++){
    //         cout << ice[curr_y][curr_x] << " ";
    //     }
    //     cout << "\n";
    // }

    // 남아있는 얼음 중 가장 큰 덩어리 칸 개수 구하기
    // BFS
    int ice_max = 0;
    queue<pair<int, int> > q;
    vector<vector<bool> > isVisited(ice_size+1, vector<bool>(ice_size+1, false));

    for(int y=1;y<=ice_size;y++){
        for(int x=1;x<=ice_size;x++){

            int cnt=0;
            if(ice[y][x]!=0 && !isVisited[y][x]){
                
                q.push({x,y});
                isVisited[y][x]=true;
                cnt++;

                while(!q.empty()){
                    int curr_x = q.front().first;
                    int curr_y = q.front().second;
                    q.pop();

                    for(int i=0;i<4;i++){
                        int next_x = curr_x + mv[i].first;
                        int next_y = curr_y + mv[i].second;

                        // 범위 넘어갈떄
                        if(next_x < 1 || next_y < 1 || next_x > ice_size || next_y > ice_size) continue;

                        // 방문 했거나 0일때
                        if(isVisited[next_y][next_x] || ice[next_y][next_x]==0) continue;

                        q.push({next_x, next_y});
                        isVisited[next_y][next_x]=true;
                        cnt++;
                    }
                }
            }

            if(ice_max < cnt) ice_max = cnt;
        }
    }
    cout << ice_max;
}