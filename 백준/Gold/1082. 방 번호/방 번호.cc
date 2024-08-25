#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int> > arr;
vector<pair<int, int> > price_sorted_arr;
vector<int> res;

int compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    cin >> N;

    for(int i=0;i<N;i++){
        int temp;
        cin >> temp;
        arr.push_back({i, temp});
    }

    cin >> M;

    price_sorted_arr.resize(N);
    copy(arr.begin(), arr.end(), price_sorted_arr.begin());
    
    // 가격으로 정렬
    sort(price_sorted_arr.begin(), price_sorted_arr.end(), compare);

    // for(int i=0;i<price_sorted_arr.size();i++){
    //     cout << price_sorted_arr[i].first << price_sorted_arr[i].second << "\n";
    // }

    int wallet = M;
    if(price_sorted_arr.size() > 1 && price_sorted_arr[0].first == 0 && wallet >= price_sorted_arr[1].second){
        wallet = wallet - price_sorted_arr[1].second;
        res.push_back(price_sorted_arr[1].first);
    }

    while(wallet >= price_sorted_arr[0].second){
        wallet = wallet - price_sorted_arr[0].second;
        res.push_back(price_sorted_arr[0].first);
    }

    // for(int i=0;i<res.size();i++){
    //     cout << res[i];
    // }

    //cout << wallet;

    // 해당 자릿수에서 제일 큰 수 찾기
    for(int idx = 0; idx < res.size() ; idx++){
        for(int i=N-1;i>=0;i--){
            // cout << wallet << " " << arr[i].first << "," << arr[i].second << "\n";

            if(price_sorted_arr[0].first != res[idx]){
                if(wallet + price_sorted_arr[1].second >= arr[i].second){
                    wallet = wallet + price_sorted_arr[1].second - arr[i].second;
                    res[idx] = arr[i].first;
                    break;
                }
            }
            else if(wallet + price_sorted_arr[0].second >= arr[i].second){
                wallet = wallet + price_sorted_arr[0].second - arr[i].second;
                res[idx] = arr[i].first;
                break;
            }
        }
    }

    if(res[0]==0){
        cout << 0;
        return 0;
    }
        

    for(int i=0;i<res.size();i++){
        cout << res[i];
    }
}