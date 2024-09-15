#include<bits/stdc++.h>

using namespace std;

int N, S;
vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    cin >> S;

    for(int i=1;i<=S;i++){
        int s, n;

        cin >> s >> n;

        // 남자
        if(s==1){

            for(int x=1;n*x <= N;x++){
                arr[n*x] = !arr[n*x];
            }
        }
        // 여자
        else if(s==2){
            int idx=1;

            arr[n] = !arr[n];

            while(n-idx>=1 && n+idx<=N && arr[n+idx] == arr[n-idx]){
                arr[n+idx] = !arr[n+idx];
                arr[n-idx] = !arr[n-idx];
                idx++;
            }

        }
    }

    for(int i=1;i<=N;i++){
        cout << arr[i] <<" ";
        if(i%20==0) cout << "\n";
    }

}