#include<bits/stdc++.h>

using namespace std;

string S;
char a;
int l, r, q;
map<char, vector<int> > m;

int main(){
    cin >> S >> q;

    int s = S.size();
    for(int i=0;i<s;i++){

        if(m.find(S[i]) == m.end()){
            m.insert({S[i], vector<int>(i, 0)});
            m[S[i]].push_back(1);

            for(int j=i+1;j<s;j++){
                if(S[j]==S[i]){
                    m[S[i]].push_back(m[S[i]][j-1]+1);
                }
                else{
                    m[S[i]].push_back(m[S[i]][j-1]);
                }
            }
        }

    }

    for(int i=1;i<=q;i++){
        cin >> a >> l >> r;

        // for(int i=0;i<m[a].size();i++){
        //     cout << m[a][i] << " ";
        // }
        // cout << "\n";

        if(m.find(a) == m.end()){
            cout << 0 << "\n";
            continue;
        }

        if(l==0)
            cout << m[a][r] << "\n";
        else 
            cout << m[a][r] - m[a][l-1] << "\n";
    }
}