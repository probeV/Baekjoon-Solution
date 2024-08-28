#include<bits/stdc++.h>

using namespace std;

int N;
vector<long long> dis;
vector<long long> cost;

int main(){
    cin >> N;

    dis.resize(N);
    for(int i=1;i<N;i++){
        cin >> dis[i];
    }

    cost.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> cost[i];
    }

    long long curr_cost=0;
    int idx=1;
    for(int i=1;i<N;i++){
        if(cost[idx] >= cost[i]){
            idx=i;
        }
        curr_cost = curr_cost + dis[i]*cost[idx];
    }

    cout << curr_cost;
}