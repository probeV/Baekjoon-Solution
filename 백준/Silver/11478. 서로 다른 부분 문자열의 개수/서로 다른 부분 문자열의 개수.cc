#include <bits/stdc++.h>

using namespace std;

string S;
set<string> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    for(int i=0;i<S.size();i++){
        for(int j=1;j<=S.size();j++){
            // cout << S.substr(i,j) << "\n";
            arr.insert(S.substr(i,j));
        }
    }

    cout << arr.size();
}
