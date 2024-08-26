#include<bits/stdc++.h>

using namespace std;

int N, K;
vector<int> arr;
vector<int> s;

int main(){
    cin >> N >> K;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    s.resize(N-K+2, 0);
    for(int i=1;i<=K;i++){
        s[1] += arr[i];
    }

    for(int i=K+1;i<=N;i++){
        s[i-K+1] = s[i-K]-arr[i-K]+arr[i];
    }

    int res = INT_MIN;
    for(int i=1;i<=N-K+1;i++){
        res = max(res, s[i]);
    }

    cout << res;
}