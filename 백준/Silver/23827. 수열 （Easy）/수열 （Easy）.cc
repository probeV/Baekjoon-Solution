#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;

int main(){
    long long S=0;

    cin >> N;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        S+=arr[i];
    }

    long long res=0;
    for(int i=1;i<=N;i++){
        S=S-arr[i];
        res+= (arr[i] * S) % 1000000007;
    }

    cout << res % 1000000007;
    return 0;
}

// 1 2
// 1*2

// 1 2 3 
// 1*(2+3) + 2*(3)

// 1 2 3 4
// 1*(2+3+4) + 2*(3+4) + 3*(4)

// 1 2 3 4 5
// 