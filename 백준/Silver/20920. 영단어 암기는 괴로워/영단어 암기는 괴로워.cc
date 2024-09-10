#include<bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> m;
vector<pair<int, string> > arr;

int compare(pair<int, string> &a, pair<int, string> &b){
    if(a.first == b.first){
        if(a.second.size() == b.second.size()){
            return a.second < b.second;
        }

        return a.second.size() > b.second.size();
    }

    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=1;i<=N;i++){
        string s;
        cin >> s;

        if(s.size() < M) continue;

        if(m.find(s) != m.end()){
            m[s]++;
        }
        else{
            arr.push_back({0, s});
            m[s]=1;
        }
    }

    for(int i=0;i<arr.size();i++){
        arr[i].first = m[arr[i].second];
    }

    sort(arr.begin(), arr.end(), compare);
    for(int i=0;i<arr.size();i++){
        cout << arr[i].second << "\n";
    }
}