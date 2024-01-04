#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> ipt;

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        int temp;
        cin >> temp;
        ipt.push_back(temp);
    }

    sort(ipt.begin(), ipt.end());

    for (int i = 0; i < N; i++)
    {
        cout << ipt[i] <<"\n";
    }
}