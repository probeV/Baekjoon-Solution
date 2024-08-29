#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> dp;

int main(){
    cin >> N;

    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(2);

    for(int i=3;i<=N;i++){
        dp.push_back((dp[i-1]+dp[i-2])%15746);
    }

    
    // for(int i=1;i<=N;i++){
    //     cout << dp[i] << " ";
    // }

    cout << dp[N]%15746;
}