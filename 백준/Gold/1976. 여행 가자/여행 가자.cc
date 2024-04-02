#include  <bits/stdc++.h>

using namespace std;

#define MAXSIZE 201

int N, M;
int path[MAXSIZE][MAXSIZE];
vector<int> plan;

bool BFS(int start, int end){
    queue<int> q;
    bool isVisited[MAXSIZE];

    memset(isVisited, 0, sizeof(isVisited));

    q.push(start);
    isVisited[start]=true;

    while(!q.empty()){
        int curr=q.front();
        q.pop();

        if(curr==end){
            return true;
        }

        for(int i=1;i<=N;i++){
            if(path[curr][i] && !isVisited[i]){
                q.push(i);
                isVisited[i]=true;
            }
        }
    }

    return false;
}

int main(){
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> path[i][j];
        }
    }

    int tmp;
    for(int i=1;i<=M;i++){
        cin >> tmp;
        plan.push_back(tmp);
    }

    bool res;
    for(int i=1;i<M;i++){
        res = BFS(plan[i-1], plan[i]);

        if(!res){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}