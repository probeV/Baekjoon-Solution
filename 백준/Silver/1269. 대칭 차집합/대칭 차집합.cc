#include <bits/stdc++.h>

using namespace std;

int A, B;
set<int> a,b, res;

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

    set<int> intersec1, intersec2;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(intersec1, intersec1.begin()));
    set_difference(b.begin(), b.end(), a.begin(), a.end(),  inserter(intersec2, intersec2.begin()));
    set_union(intersec1.begin(), intersec1.end(), intersec2.begin(), intersec2.end(), inserter(res, res.begin()));

    cout << res.size();
    
}