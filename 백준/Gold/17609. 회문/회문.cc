#include<bits/stdc++.h>
using namespace std;

int isPal(string& curr, int left, int right, bool skipped){
    while(left < right){
        if(curr[left]==curr[right]){
            left++;
            right--;
        }
        else {
            if(skipped) return 2;

            int skipLeft = isPal(curr, left+1, right, true);
            int skipRight = isPal(curr, left, right-1, true);
            return min(skipLeft, skipRight);
        }
    }
    return skipped ? 1 : 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << isPal(s, 0, s.size()-1, false) << '\n';
    }
}

