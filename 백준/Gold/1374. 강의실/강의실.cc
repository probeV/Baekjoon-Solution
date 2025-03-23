#include <bits/stdc++.h>

using namespace std;

int N; // 강의의 개수
vector<pair<int, int> > arr; // 강의 번호, 강의 시작 시간, 강의 종료 시간

int compare(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++){
        int x;
        pair<int, int> temp;
        cin >> x >> temp.first >> temp.second;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), compare);

    int cnt=0;
    priority_queue<int> pq;

    for(int i=0;i<N;i++){
        if(!pq.empty() && pq.top()*-1 <= arr[i].first){
            pq.pop();
            pq.push(arr[i].second*-1);
        }
        else {
            pq.push(arr[i].second*-1);
            cnt++;
        }
    }

    cout << cnt;

}