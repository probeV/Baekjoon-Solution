#include<bits/stdc++.h>

using namespace std;

int t,n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;

    for(int i=1;i<=t;i++){
        cin >> n;

        vector<int> arr;
        int tmp;
        for(int j=1;j<=n;j++){
            cin >> tmp;
            arr.push_back(tmp);
        }

        long long res=0;
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                res += gcd(arr[j], arr[k]);
            }
        }

        cout << res << "\n";
    }
}

