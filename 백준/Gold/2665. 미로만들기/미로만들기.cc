#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int> > arr, dist;
vector<pair<int, int> > mv={{1,0},{0,1},{-1,0},{0,-1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    arr.resize(N+1, vector<int>(N+1));
    dist.resize(N+1, vector<int>(N+1));
    for(int y=1;y<=N;y++){
        string temp;
        cin >> temp;
        for(int x=1;x<=N;x++){
            arr[y][x] = temp[x-1]-'0';
            dist[y][x] = INT_MAX;
        }
    }

    deque<pair<int, int> > dq;
    dq.push_front({1,1});
    dist[1][1]=0;

    while(!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for(int i=0;i<4;i++){
            int nx = x + mv[i].first;
            int ny = y + mv[i].second;
            
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;

            int cost = dist[y][x] + (arr[ny][nx] == 0 ? 1 : 0);
            if(cost < dist[ny][nx]){
                dist[ny][nx]=cost;
                if(arr[ny][nx]==0){
                    dq.push_back({nx,ny});
                }
                else{
                    dq.push_front({nx,ny});
                }
            }
        }
    }

    cout << dist[N][N];
}
