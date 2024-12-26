#include<bits/stdc++.h>

using namespace std;

// 학생 수, 졸고 있는 학생 수, 출석 코드 보낼 학생수, 주어질 구간 수
int N, K, Q, M;
vector<int> isAttend;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> Q >> M;

    isAttend.resize(N+3);
    int idx;
    for(int i=1;i<=K;i++){
        cin >> idx;
        isAttend[idx]=-1;
    }
    for(int i=1;i<=Q;i++){
        cin >> idx;

        // 처음 출석 번호 받은 놈이 졸때  
        if(isAttend[idx]==-1){
            continue;
        }

        int j=1;
        while(idx*j <= N+2){
            // 졸지 않을 때
            if(isAttend[idx*j]==0){
                isAttend[idx*j]=1;
            }
            j++;
        }
    }
    for(int i=3;i<=N+2;i++){
        if(isAttend[i]==-1 || isAttend[i]==0)
            isAttend[i]=isAttend[i-1]+1;
        else 
            isAttend[i]=isAttend[i-1];
        // cout << isAttend[i] << " ";
    }

    int x, y;
    for(int i=1;i<=M;i++){
        cin >> x >> y;
        cout << isAttend[y]-isAttend[x-1] << "\n";
    }

}

// 2 1 1 1
// 3
// 3
// 3 4