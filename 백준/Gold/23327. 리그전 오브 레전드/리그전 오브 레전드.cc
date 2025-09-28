#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<long long> team;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;

    team.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> team[i];
    }

    int start, end;
    vector<long long> preSum(N+1, 0), preSqrSum(N+1, 0);
    for(int x=1;x<=N;x++){
        preSum[x] = preSum[x-1] + team[x];
        preSqrSum[x] = preSqrSum[x-1] + team[x]*team[x];
    }

    // for(int x=1;x<=N;x++){
    //     cout << preSum[x] << " ";
    // }
    // cout << "\n";

    // for(int x=1;x<=N;x++){
    //     cout << preSqrSum[x] << " ";
    // }
    // cout << "\n";

    for(int i=1;i<=Q;i++){
        cin >> start >> end;
        long long preSumSqr = (preSum[end]-preSum[start-1])*(preSum[end]-preSum[start-1]);
        long long preSqrSumSum = preSqrSum[end]-preSqrSum[start-1];

        cout << (preSumSqr - preSqrSumSum)/2 << "\n";
    }
}