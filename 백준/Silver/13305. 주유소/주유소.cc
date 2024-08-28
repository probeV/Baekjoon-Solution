#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> dis;
vector<int> cost;
int dis_sum;

int main(){
    cin >> N;

    dis.resize(N);
    for(int i=1;i<N;i++){
        cin >> dis[i];
        dis_sum += dis[i];
    }

    cost.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> cost[i];
    }

    long curr_cost = cost[1] * dis_sum;
    int idx=1;
    for(int i=2;i<N;i++){
        if(cost[idx] > cost[i]){
            //cout << idx << " " << i <<"\n";

            curr_cost = curr_cost + (dis_sum - dis[i-1])*(cost[i] - cost[i-1]);
            idx=i;
        }

        dis_sum = dis_sum - dis[i-1];
    }

    cout << curr_cost;
}