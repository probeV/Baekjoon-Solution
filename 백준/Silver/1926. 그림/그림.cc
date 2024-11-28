#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > arr;
vector<vector<bool> > isVisited;

vector<pair<int, int> > mv = {{1,0},{0,1},{-1,0},{0,-1}};

int cnt=0;
vector<int> res;

void BFS(int x, int y, int cnt){

    queue<pair<int, int> > q;

    res[cnt]++;
    isVisited[y][x]=true;
    q.push({x,y});

    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int next_x = curr_x + mv[i].first;
            int next_y = curr_y + mv[i].second;

            if(next_x <= 0 || next_y <= 0 || next_x > m || next_y > n) continue;

            if(arr[next_y][next_x]==1 && !isVisited[next_y][next_x]){
                res[cnt]++;
                isVisited[next_y][next_x]=true;
                q.push({next_x, next_y});
            }
        }

    }
}

int main(){
    cin >> n >> m;

    arr.resize(n+1, vector<int>(m+1));
    isVisited.resize(n+1, vector<bool>(m+1));

    for(int y=1;y<=n;y++){
        for(int x=1;x<=m;x++){
            cin >> arr[y][x];
        }
    }

    for(int y=1;y<=n;y++){
        for(int x=1;x<=m;x++){
            if(arr[y][x]==1 && !isVisited[y][x]){
                res.push_back(0);
                BFS(x,y, cnt++);
            }
        }
    }


    cout << res.size() << "\n";

    if(res.size()!=0)
        cout << *max_element(res.begin(), res.end());
    else
        cout << 0;
}