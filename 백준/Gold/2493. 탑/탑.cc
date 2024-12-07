#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr, res;

int main(){
    cin >> N;

    arr.resize(N+1);
    res.resize(N+1);

    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    stack<pair<int, int> > s;   // 탑 높이, 인덱스 
    for(int i=N;i>0;i--){
        // 현재 탑이 수신한 신호 체크 
        while(!s.empty() && s.top().first <= arr[i]){
            res[s.top().second]=i;
            s.pop();
        }

        // 현재 탑 스택에 넣기
        s.push({arr[i], i});
    }

    while(!s.empty()){
        res[s.top().second]=0;
        s.pop();
    }

    for(int i=1;i<=N;i++){
        cout << res[i] << " ";
    }

}