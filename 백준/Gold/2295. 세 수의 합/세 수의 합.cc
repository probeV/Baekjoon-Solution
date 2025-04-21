#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    set<int> bout;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bout.insert(arr[i] + arr[j]);
        }
    }

    bool flag = true;
    for (int i = n-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            if (bout.count(arr[i] - arr[j])) {
                cout << arr[i] << endl;
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    return 0;
}
