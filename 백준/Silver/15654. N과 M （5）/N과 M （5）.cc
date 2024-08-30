#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr;
vector<vector<int> > res;

void DFS(vector<int> &temp, vector<bool> &isVisited){

    if(temp.size() == M){
        res.push_back(temp);
        return;
    }

    for(int i=1;i<=N;i++){
        if(!isVisited[i]){
            temp.push_back(arr[i]);
            isVisited[i] = true;
            DFS(temp, isVisited);
            temp.pop_back();
            isVisited[i]=false;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    vector<int> temp;
    vector<bool> isVisited(N+1, false);
    DFS(temp, isVisited);

    sort(res.begin(), res.end());

    for(int i=0;i<res.size();i++){
        for(int j=0;j<M;j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}