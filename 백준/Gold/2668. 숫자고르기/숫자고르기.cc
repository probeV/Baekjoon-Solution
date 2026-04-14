#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;
vector<bool> isVisited;
set<int> res;

bool solve(int start, int curr){    // 시작 인덱스 / 현재 인덱스 

    int next = arr[curr];

    if(next==start){
        res.insert(curr);
        return true;
    }

    if(isVisited[next]){
        return false;
    }
    else{
        isVisited[next]=true;

        if(solve(start, next)){
            res.insert(curr);
            return true;
        }
        else {
            isVisited[next]=false;
            return false;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr.resize(N+1);
    isVisited.resize(N+1);

    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    for(int i=1;i<=N;i++){
        isVisited[i]=true;
        solve(i, i);
    }

    cout << res.size() << "\n";
    for(auto a : res){
        cout << a << "\n";
    }
}