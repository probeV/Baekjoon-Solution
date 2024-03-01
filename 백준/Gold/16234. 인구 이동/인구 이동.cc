#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 51

bool isPlay = true;
int N, L, R, p;
int people[MAXSIZE][MAXSIZE];
bool isVisited[MAXSIZE][MAXSIZE];

vector<pair<int, int> > v;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int x, int y){
    queue<pair<int, int> > q;

    q.push({x,y});
    isVisited[x][y] = true;

    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];

            //범위를 벗어났을 때, 방문했을 때
            if(next_x > N || next_y > N || next_x <= 0 || next_y <= 0 || isVisited[next_x][next_y]){
                continue;
            }
            
            int diff = abs(people[curr_x][curr_y] - people[next_x][next_y]);

            if(diff >= L && diff <=R){
                isVisited[next_x][next_y] = true;
                q.push({next_x, next_y});
                v.push_back({next_x, next_y});

                p += people[next_x][next_y];
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            cin >> people[x][y];
        }
    }

    int cnt=0;

    while(1){
        isPlay = false;

        memset(isVisited, 0, sizeof(isVisited));
        
        for(int y=1;y<=N;y++){
            for(int x=1;x<=N;x++){
                if(!isVisited[x][y]){
                    v.clear();
                    v.push_back({x, y});
                    p=people[x][y];

                    BFS(x, y);
                }

                if(v.size() >= 2){
                    isPlay=true;
                    for(int i=0;i<v.size();i++){
                        people[v[i].first][v[i].second] = p /v.size();
                    }
                }
            }
        }

        if(!isPlay) break;
        else cnt++;
    }

    cout << cnt;
}