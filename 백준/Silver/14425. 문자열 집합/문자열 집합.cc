#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, bool> a;
int res=0;

int main(){
    
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        string temp;
        cin >> temp;

        a.insert({temp, true});
    }

    for(int i=1; i<=M; i++){
        string temp;
        cin >> temp;

        if(a.find(temp) != a.end() ){
            res++;
        }
    }   

    cout << res;
}