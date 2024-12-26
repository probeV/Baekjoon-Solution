#include <bits/stdc++.h>

using namespace std;

int n, b, a;
vector<int> p;
stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> b >> a;

    p.resize(n);

    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    int cnt=0, res=0;
    for(int i=0;i<n;i++){

        res = res + p[i];
        s.push(p[i]);
        cnt++;
        
        while(b < res && !s.empty() && a>0){    
            // 할인할 선물이 남아있고, 할인 개수 남아 있고, 현재 가격이  할인해야할 때 
            res = res - s.top();
            res = res + s.top()/2;
            s.pop();
            a--;
        }
        
        if(b < res) {   // 할인 하고도 값 넘어가면 진짜 끝 
            cnt--;
            break;
        }

    }
    
    cout << cnt;
}
