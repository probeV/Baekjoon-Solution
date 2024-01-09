#include <bits/stdc++.h>

using namespace std;

#define MAX 11

int N,K, res=0;
int ipt[MAX];

int main(){
    cin >> N >> K;

    for(int i=1;i<=N;i++){
        cin >> ipt[i];
    }

    for(int i=N;i>=1;i--){
        int m=1;
        while(K>=ipt[i]*m){
            m++;
        }
        K=K-ipt[i]*(m-1);
        res=res+m-1;
    }

    cout << res;
}