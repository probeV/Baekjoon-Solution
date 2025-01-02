#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 1000001

int T;
vector<bool>isVisited(MAXSIZE, true);

void ast(){
    isVisited[1]=false;
    isVisited[0]=false;

    for(int i=2;i*i<MAXSIZE;i++){
        if(isVisited[i]){
            for(int j=i*i;j<MAXSIZE;j=j+i){
                isVisited[j]=false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    ast(); 
    for(int i=1;i<=T;i++){
        int N, cnt=0;
        cin >> N;

        for(int j=2;j<=N/2;j++){
            if(isVisited[j] && isVisited[N-j]){
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
}