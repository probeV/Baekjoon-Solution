#include <bits/stdc++.h>

using namespace std;

int T, n;
map<string, vector<string>> arr;

int main(){
    cin >> T;

    for(int t=1;t<=T;t++){
        arr.clear();
        int res=1;

        cin >> n;

        for(int i=1;i<=n;i++){
            string name, kind;

            cin >> name >> kind;
            arr[kind].push_back(name);
        }

        for(auto [key, value] : arr){
            res *= (value.size()+1);
        }

        cout << res-1 << "\n";
    }
}