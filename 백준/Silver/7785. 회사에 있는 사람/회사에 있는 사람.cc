#include <bits/stdc++.h>

using namespace std;

int N;
set<string, greater<string> > arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string tmp;
    string order;
    for(int i=1;i<=N;i++){
        cin >> tmp >> order;

        if(order == "enter"){
            arr.insert(tmp);
        }
        else if(order == "leave"){
            arr.erase(tmp);
        }
    }

    for(auto a:arr){
        cout << a << "\n";
    }
}
