#include<bits/stdc++.h>

using namespace std;

int N, X;
vector<int> arr;
vector<int> res;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> X;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    int temp=0;
    for(int i=1;i<=X;i++){
        temp += arr[i];
    }

    res.push_back(temp);
    for(int i=X+1;i<=N;i++){
        temp = temp - arr[i-X] + arr[i];
        res.push_back(temp);
    }

    int M = *max_element(res.begin(), res.end());
    int cnt=0;  
    for(int i=0;i<res.size();i++){
        if(M==res[i]) cnt++;
    }   

    if(M==0){
        cout << "SAD\n";
    }
        
    else{
        cout << M << "\n";
        cout << cnt;
    }
        
}