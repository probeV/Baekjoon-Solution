#include<bits/stdc++.h>

using namespace std;

int N,M;
vector<vector<int> > dp;
vector<pair<int, int> > arr; // 일수, 페이지 수

int main(){
    cin >> N >> M;

    arr.resize(M+1);
    for(int i=1;i<=M;i++){
        cin >> arr[i].first >> arr[i].second;
    }

    dp.resize(N+1, vector<int>(M+1, 0));
    for(int i=1;i<=M;i++){
        for(int w=1;w<=N;w++){
            if(w >= arr[i].first){
                dp[w][i] = max(dp[w][i-1], arr[i].second + dp[w-arr[i].first][i-1]);
            }
            else{
                dp[w][i] = dp[w][i-1];
            }
        }
    }

    // for(int w=1;w<=N;w++){
    //     for(int i=1;i<=M;i++){
    //         cout << dp[w][i] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[N][M];
}