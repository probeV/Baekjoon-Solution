#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> arr;

int main(){
    cin >> N;

    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    for(int i=3;i<=N;i++){
        arr.push_back(arr[i-2] + arr[i-1] + 1);
    }

    if(N==1 || N==2) cout << 1;
    else cout << arr[N-2] + 1;
}
