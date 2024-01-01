#include <bits/stdc++.h>

using namespace std;

vector<int> num = {1,1,2,2,2,8};
vector<int> ipt;

int main(){
    int n;
    for(int i=0;i<6;i++){
        cin >> n;
        cout << num[i]-n << " ";
    }
}
