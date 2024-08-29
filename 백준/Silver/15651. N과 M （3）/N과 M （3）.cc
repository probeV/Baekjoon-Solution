#include<bits/stdc++.h>

using namespace std;

int N, M;

void DFS(vector<int> &res){

    if(res.size()==M){
        for(int i=0;i<M;i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1;i<=N;i++){
        res.push_back(i);
        DFS(res);
        res.pop_back();
    }

}

int main(){
    cin >> N >> M;

    vector<int> res;
    DFS(res);

}