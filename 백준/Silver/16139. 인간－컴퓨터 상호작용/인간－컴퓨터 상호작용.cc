#include<bits/stdc++.h>

using namespace std;

string S;
char a;
int l, r, q;
map<char, vector<int> > m;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S >> q;

    int s = S.size();

    for(int i=1;i<=26;i++){
        m.insert({96+i, vector<int>(1,0)});
    }

    for(int i=0;i<s;i++){
        
        for(int j=1;j<=26;j++){
            m[96+j].push_back(m[96+j].back());
        }
        
        m[S[i]][i+1]++;
    }

    for(int i=1;i<=q;i++){
        cin >> a >> l >> r;

        // for(int i=0;i<m[a].size();i++){
        //     cout << m[a][i] << " ";
        // }
        // cout << "\n";

        cout << m[a][r+1] - m[a][l] << "\n";
    }
}