#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int N, M;
int ipt[MAX];

int main(){  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        cin >> ipt[i];
        ipt[i]+=ipt[i-1];
    }

    for(int i=1;i<=M;i++){
        int start, end;
        cin >> start >> end;

        cout << ipt[end]-ipt[start-1] << '\n';
    }
}

