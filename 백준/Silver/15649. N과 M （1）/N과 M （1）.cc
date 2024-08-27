#include<bits/stdc++.h>

using namespace std;

int N, M;

void DFS(vector<bool> &isVisited, vector<int> &res){
    if(res.size() == M){
        for(int i=0;i<M;i++)
            cout << res[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1;i<=N;i++){
        if(!isVisited[i]){
            isVisited[i]=true;
            res.push_back(i);
            DFS(isVisited, res);
            isVisited[i]=false;
            res.pop_back();
        }
    }
}

int main(){
    cin >> N >> M;

    vector<bool> isVisited(N+1, false);
    vector<int> res;

    DFS(isVisited, res);
}