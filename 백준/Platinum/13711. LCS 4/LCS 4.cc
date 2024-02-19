#include <bits/stdc++.h>

using namespace std;

vector<int> seq, LIS;
vector<int>::iterator it;

map<int, int> pos;

int main(void){
    int N;

    cin >> N;

    int ipt;
    for(int i=1;i<=N;i++){
        cin >> ipt;
        pos.insert({ipt, i});
    }
    for(int i=1;i<=N;i++){
        cin >> ipt;
        seq.push_back(pos[ipt]);
    }

    // for(int i=0;i<N;i++){
    //     cout << seq[i];
    // }

    for(int i=0;i<N;i++){
        if(LIS.empty() || LIS.back() < seq[i]){
            LIS.push_back(seq[i]);
        }
        else{
            it = upper_bound(LIS.begin(), LIS.end(), seq[i]);
            *it=seq[i];
        }
    }

    cout << LIS.size();
}