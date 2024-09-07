#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int T,N;

int main() {
    cin >> T;

    while(T--) {
        cin >> N;
        vector<int> v;

        for(int i=0;i<N;i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        ll result=0;
        int max_value=-1;

        for(int i=N-1;i>=0;i--) {
            max_value=max(max_value,v[i]);
            result+=max_value-v[i];
        }

        cout << result << "\n";
    }
}
