#include <bits/stdc++.h>

using namespace std;

int A, B;
set<int> a,b;

int main(){
    cin >> A >> B;

    int tmp;
    for(int i=1;i<=A;i++){
        cin >> tmp;
        a.insert(tmp);
    }
    for(int i=1;i<=B;i++){
        cin >> tmp;
        b.insert(tmp);
    }

    vector<int> res;
    set_difference(a.begin(),a.end(), b.begin(), b.end(), inserter(res, res.begin()));
    sort(res.begin(), res.end());

    cout <<  res.size() << "\n";
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
}