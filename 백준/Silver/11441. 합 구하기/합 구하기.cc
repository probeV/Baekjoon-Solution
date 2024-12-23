#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr, s;
vector<pair<int, int> > interval;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    arr.resize(N+1);
    s.resize(N+1,0);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        s[i]= s[i-1]+arr[i];
    }

    cin >> M;
    interval.resize(M+1);
    for(int i=1;i<=M;i++){
        cin >> interval[i].first >> interval[i].second;
    }

    for(int i=1;i<=M;i++){
        cout << s[interval[i].second]-s[interval[i].first-1] << "\n";
    }
}