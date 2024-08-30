#include<bits/stdc++.h>

using namespace std;

int N, m=INT_MAX;
vector<vector<int> > S;

void DFS(vector<int> &team1, int idx){

    if(team1.size() == N/2){
        
        vector<int> team2;
        for(int i=0;i<N;i++){
            for(int j=0;j<N/2;j++){
                if(i==team1[j]) break;
                else if(j==(N/2)-1) team2.push_back(i);
            }
        }

        int temp1=0, temp2=0;
        for(int i=0;i<N/2;i++){
            for(int j=0;j<N/2;j++){
                temp1 += S[team1[i]][team1[j]];
                temp2 += S[team2[i]][team2[j]];
            }
        }

        if(m > abs(temp1-temp2)){
            m = abs(temp1-temp2);

            // for(int j=0;j<N/2;j++){
            //     cout << team1[j]+1 << " ";
            // }
            // cout << " -> " << m <<"\n";

        } 

        return;
    }

    for(int i=idx;i<N;i++){
        team1.push_back(i);
        DFS(team1, i+1);
        team1.pop_back();
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    S.resize(N, vector<int>(N));
    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            cin >> S[y][x];
        }
    }

    vector<int> team1;
    DFS(team1, 0);

    cout << m;
}