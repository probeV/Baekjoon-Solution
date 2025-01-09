#include <bits/stdc++.h>

using namespace std;

int N;

bool compare(string a, string b) {
    return a + b > b + a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<string> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), compare);


    string res;
    for(string& s:arr){
        res +=s;
    }
    if(res[0] =='0'){
        cout << 0;
        return 0;
    }
    else{
        cout << res;
    }
    
}

// 99792
// 3
// 9 92 97

// 33 332 30
// 3
// 33 332 30

// 998890
// 3
// 9 90 988

// 9534330
// 5
// 3 30 34 5 9      

// 10000
// 5
// 0 0 0 0 1

// 10 100 1004
// 10 1004 100