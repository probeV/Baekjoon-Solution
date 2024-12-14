#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;

int main(){
    cin >> N;

    int temp;
    for(int i=1;i<=N;i++){
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int res=0;
    for(int i=0;i<N;i++){
        if(res < (N-i)*arr[i])
            res = (N-i)*arr[i];
    }

    cout << res;

}


