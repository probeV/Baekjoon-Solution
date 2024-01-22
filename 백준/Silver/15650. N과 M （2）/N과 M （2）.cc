#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> res;

void print() {
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

void recur(int num, int idx) {

    if (num == M) {
        print();
        return;
    }
    else {
        for (int i = idx; i <= N; i++) {
            res.push_back(i);
            recur(num + 1, i + 1);
            res.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;

    recur(0, 1);

}