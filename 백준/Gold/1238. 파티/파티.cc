#include  <bits/stdc++.h>

using namespace std;

#define MAXSIZE 10001

int N, M, X;
map<int, vector<pair<int, int>>> path; // 마을 번호, 가는 시간
int res[MAXSIZE], diff[MAXSIZE];

void Dijk(int start, int end){
    priority_queue<pair<int, int>> pq; // 가중치, 마을 번호
    for(int i=1;i<=N;i++){
        diff[i]=INT_MAX;
    }

    pq.push({0, start});
    diff[start]=0;

    while(!pq.empty()){

        int curr_x = pq.top().second;
        int curr_w = -pq.top().first;
        pq.pop();

        for(int i=0;i<path[curr_x].size();i++){
            int next_x = path[curr_x][i].first;
            int next_w = path[curr_x][i].second;

            if(diff[next_x] > curr_w + next_w){
                diff[next_x] = curr_w + next_w;
                pq.push({-diff[next_x], next_x});

            }
        }
    }


    if(start != end) res[start] += diff[end];
    else{
        for(int i=1;i<=N;i++){
            res[i] += diff[i];
        }
    }
}

int main(void){
    cin >> N >> M >> X;

    int start, end, T;
    for(int i=1; i<=M; i++){
        cin >> start >> end >> T;
        
        if(path.find(start) == path.end()){
            vector<pair<int, int>> v;
            path.insert({start, v});
        }
        
        path[start].push_back({end, T});
    }

    for(int i=1;i<=N;i++){
        if(i==X) continue;
        Dijk(i, X);
    }

    Dijk(X,X);

    int max=0;
    for(int i=1;i<=N;i++){
        //cout << res[i] << " ";
        if(max < res[i]) max = res[i];
    }

    cout << max;
}