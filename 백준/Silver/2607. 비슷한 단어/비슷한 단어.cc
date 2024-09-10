#include<bits/stdc++.h>

using namespace std;

int N;
vector<multiset<char>> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=1;i<=N;i++){
        multiset<char> s;

        string ss;
        cin >> ss;

        for(int j=0;j<ss.size();j++){  // i 대신 j로 수정
            s.insert(ss[j]);
        }

        arr.push_back(s);
    }

    int res=0;
    for(int i=0;i<=0;i++){
        for(int j=i+1;j<N;j++){
            multiset<char> temp;
            set_intersection(
                arr[i].begin(), arr[i].end(), 
                arr[j].begin(), arr[j].end(),
                inserter(temp, temp.begin()));

            if(
                (abs((int)(temp.size() - arr[i].size())) <= 1) && 
                (abs((int)(temp.size() - arr[j].size())) <= 1)){
                res++;
            }
        }
    }

    cout << res;
}
