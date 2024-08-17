#include<bits/stdc++.h>

using namespace std;

int n, p, d;
int res=0;

vector<pair<int, int> > arr; // 일, 가격

int compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> p >> d;
        arr.push_back({d, p});
    }

    // 정렬
    sort(arr.begin(), arr.end(), compare);

    // 그리디
    // for(int i=0;i<arr.size();i++){
    //     cout << arr[i].first << " " << arr[i].second  << "\n";
    // }
    // cout << "\n\n";

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i].second);
        if(pq.size() > arr[i].first){
            pq.pop();
        }
    }

    while(!pq.empty()){
        res += pq.top();
        pq.pop();
    }
 
    cout << res;
}