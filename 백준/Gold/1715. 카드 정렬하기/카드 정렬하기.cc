#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int> q;
int res=0;

int main(){
    cin >> N;

    for(int i=1;i<=N;i++){
        int temp;
        cin >> temp;
        q.push(-1*temp);
    }

    for(int i=0;i<N-1;i++){
        int m1 = -1*q.top();
        q.pop();
        int m2 = -1*q.top();
        q.pop();

        q.push(-1*(m1+m2));
        res+=m1+m2;
    }
    cout << res;
}