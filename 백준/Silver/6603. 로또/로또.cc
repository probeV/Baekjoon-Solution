#include<bits/stdc++.h>

using namespace std;

int k;
vector<int> arr;

void DFS(int idx, vector<int> &res){
    if(res.size()==6){
        for(int i=0;i<6;i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = idx; i < arr.size(); i++) {
        res.push_back(arr[i]);
        DFS(i + 1, res); // 다음 숫자를 선택
        res.pop_back();
    }

}

int main(){

    while(1){
        cin >> k;

        if(k==0) break;

        arr.clear();
        int temp;
        for(int i=1;i<=k;i++){
            cin >> temp;
            arr.push_back(temp);
        }

        vector<int> res;
        DFS(0, res);

        cout << "\n";
    }

}