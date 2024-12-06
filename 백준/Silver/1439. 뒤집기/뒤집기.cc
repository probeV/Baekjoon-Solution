#include <bits/stdc++.h>

using namespace std;

string S;
int cnt[2];

int main(){
    cin >> S;

    char temp=S[0];
    for(int i=1;i<S.size();i++){
        if(temp==S[i]) continue;
        else if(temp!=S[i]) {
            cnt[S[i-1]-'0']++;
            temp = S[i];
        }
    }

    if(temp != S[S.size()-1]-'0') cnt[S[S.size()-1]-'0']++;

    cout << min(cnt[0], cnt[1]);
}