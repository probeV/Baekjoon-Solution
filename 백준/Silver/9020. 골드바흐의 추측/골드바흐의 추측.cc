#include <bits/stdc++.h>

using namespace std;

int T;
vector<pair<int, int> > arr(1e4+1, {0,0});
set<int> decimal;

void astra(){
    vector<bool> isVisited(1e4+1, false);
    isVisited[0]=isVisited[1]=true;

    for(int i=2;i<=1e4;i++){
        if(!isVisited[i]){
            decimal.insert(i);
            for(int j=i*i;j<=1e4;j = j+i){
                isVisited[j]=true;
            }
        }
    }
}

int main(){
    cin >> T;

    astra();
    decimal.erase(2);
    arr[4]={2,2};

    for(set<int>::iterator it= decimal.begin(); it!=decimal.end(); it++){
        for(set<int>::iterator it2=it; it2!=decimal.end(); it2++){
            int sum =  *it + *it2;
            if(sum > 1e4) break;
            arr[*it2 + *it] = {*it, *it2};
        }
    }

    for(int i=1;i<=T;i++){
        int tmp; cin >> tmp;

        cout << arr[tmp].first << " " << arr[tmp].second << "\n";
    }
}