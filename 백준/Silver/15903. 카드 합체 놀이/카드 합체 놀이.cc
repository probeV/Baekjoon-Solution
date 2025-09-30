#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<long long> arr;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long>>> pq;

int main(){
    cin >> n >> m;

    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        pq.push({arr[i], i});
    }

    for(int t=1;t<=m;t++){
        pair<long long,long long> x = pq.top(); pq.pop();
        pair<long long,long long> y = pq.top(); pq.pop();
        
        //cout << x.first << " " << y.first << "\n";

        long long total = x.first+y.first;
        arr[x.second]=total; pq.push({total, x.second});
        arr[y.second]=total; pq.push({total, y.second});
    }

    long long res=0;
    for(int i=1;i<=n;i++){
        res += arr[i];
    }
    cout << res;
}