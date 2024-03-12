#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 100001

vector<pair<int, int> > res;
stack<int> s;
int h[MAXSIZE];

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    res.push_back({0, 0});
    for(int i=1;i<=N;i++){
        cin >> h[i];
        res.push_back({0, 0});
    }

    //오른쪽에서 부터 시작
    for(int i=N;i>=1;i--){
        //자기 자신보다 작은거 다 빼버리기
        while(!s.empty() && h[s.top()] <= h[i]){
            s.pop();
        }

        if(!s.empty()){
            res[i].second += s.size();
            res[i].first = s.top();
        }
        

        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    //왼쪽에서 부터 시작
    for(int i=1;i<=N;i++){
        //자기 자신보다 작은거 다 빼버리기
        while(!s.empty() && h[s.top()] <= h[i]){
            s.pop();
        }

        res[i].second += s.size();

        if(!s.empty() && res[i].second!=0 && abs(res[i].first - i) >= abs(s.top() - i)){
            res[i].first = s.top();
        }

        s.push(i);
    }


    for(int i=1;i<=N;i++){
        if(res[i].first != 0){
            cout << res[i].second << " " << res[i].first << "\n";
        }
        else{
            cout << "0" << "\n";
        }

    }


}