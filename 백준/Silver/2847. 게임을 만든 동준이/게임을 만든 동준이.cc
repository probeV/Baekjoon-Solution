#include<bits/stdc++.h>

using namespace std;

int N, res=0;
vector<int> arr;

int main(){
    cin >> N;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    int next = arr[N];
    for(int i=N-1;i>=1;i--){
        int curr = arr[i];

        while(next <= curr){
            curr--;
            res++;
        }

        arr[i]=curr;
        next = curr;
    }

    cout << res;

}