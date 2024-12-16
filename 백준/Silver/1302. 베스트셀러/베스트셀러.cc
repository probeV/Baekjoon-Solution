#include <bits/stdc++.h>

using namespace std;

int N;
map<string, int> arr;

int main(){
    cin >> N;

    string a;
    for(int i=1;i<=N;i++){
        cin >> a;

        if(arr.find(a)==arr.end()){
            arr.insert({a, 1});
        }
        else{
            arr[a]++;
        }
    }

    int res=0;
    string r;
    for(auto& pair : arr){
        if(res < pair.second){
            res = pair.second;
            r = pair.first;
        }
    }

    cout << r;
}