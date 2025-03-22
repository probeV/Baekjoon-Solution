#include<bits/stdc++.h>

using namespace std;

int N, D;
map<int, vector<pair<int, int> > > arr;
vector<int> res;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;  // tmpEnd 같으면 tmpLen 작은 순
    return a.first < b.first;  // tmpEnd 기준 오름차순
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;  // 지름길 개수 N , 고속도로의 길이 D
    vector<int> dp(D+1, INT_MAX);

    
    for(int i=1;i<=N;i++){ 
        int tmpStart, tmpEnd, tmpLen;
        cin >> tmpStart >> tmpEnd >> tmpLen; // 지름김 시작 위치, 도착 위치, 지름길 길이이
        
        if(arr.find(tmpStart)==arr.end()){ // 시작점이 존재하지 않으면 
            arr[tmpStart] = vector<pair<int, int>>();
        }
        arr[tmpStart].push_back({tmpEnd, tmpLen});
    }

    for (auto& [key, value] : arr) {
        sort(value.begin(), value.end(), compare);
    }

    dp[0]=0;
    for(int i=0;i<=D;i++){

        if(dp[i] > dp[i-1]+1)
            dp[i]=dp[i-1]+1;

        if(arr.find(i)!=arr.end()){ // 지름길 있으면 
            for(auto& it :arr[i]){
                // 지름길 도착지가 고속도로 길이를 넘지 않고, 
                if(it.first <= D && dp[it.first] > dp[i-1]+it.second)
                    dp[it.first]=dp[i]+it.second;
            }
        }
    }

    // for(int i=1;i<=D+1;i++){
    //     cout << dp[i] << " ";
    // }

    cout << dp[D];


}