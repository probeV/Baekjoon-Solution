#include <bits/stdc++.h>

using namespace std;

int N, M; // 학생 수, 키 비교 횟수 

vector<vector<int>> arr;
vector<int> key;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    arr.resize(N+1, vector<int>());
    for(int i=0;i<M;i++){
        int x, y;
        cin >> x >> y;

        arr[x].push_back(y);
    }

    vector<int> inDegree(N+1,0);
    vector<int> result;

    // 진입 차수 계산 
    for(int i=1;i<N+1;i++){
        for(int v : arr[i]){
            inDegree[v]++;
        }
    }

    queue<int> q;
    for(int i=1;i<N+1;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        result.push_back(u);

        for(int v : arr[u]) {
            inDegree[v]--;
            if(inDegree[v]==0){
                q.push(v);
            }
        }
    }

    for(int node : result){
        cout << node << " ";
    }
}


