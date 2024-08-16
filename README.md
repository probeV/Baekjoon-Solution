## 백준, 프로그래머스
알고리즘



---

### 백준 8980번: 택배
#include<bits/stdc++.h>

using namespace std;

int N, C ,M;
map<int, vector<pair<int, int>> > arr;

int compare(pair<int, int> a, pair<int, int>  b){
    return a.first > b.first;
}

int main(){
    map<int, int> truck;

    cin >> N >> C >> M;

    //map 초기화
    for(int i=1;i<=N;i++){
        vector<pair<int, int>> v;
        arr.insert({i, v});
        truck.insert({i, 0});
    }

    //입력
    for(int i=1;i<=M;i++){
        int send, take, num;
        cin >> send >> take >> num;

        arr[send].push_back({take, num});
        //cout << arr[send][0].first << "\n";
    }

    //정렬
    for(int i=1;i<N;i++){
        sort(arr[i].begin(), arr[i].end());
    }

    // for(int i=1;i<N;i++){
    //     cout << arr[i][0].first << arr[i][0].second << arr[i].size() << "\n";
    // }

    //cout << arr[1][0].first << arr[1][0].second << arr[1].size() << "\n";
    //cout << arr[2][0].first << arr[2][0].second << arr[2].size() << "\n";
    //cout << arr[3][0].first << arr[3][0].second << arr[3].size() << "\n";

    //그리디
    int box = C, res=0;
    for(int send=1;send<=N;send++){

        //박스 배달 
        box = box + truck[send];
        res = res + truck[send];
        truck[send]=0;
        cout << "현재 넣을 수 있는 박스"<< box << "\n";
        
        // 트럭에 적재
        for(int i=0;i<arr[send].size();i++){
            int take = arr[send][i].first;
            int num = arr[send][i].second;

            // 트럭에  다 담을 수 있을 때
            if(box >= num){
                truck[take] = truck[take] + num;
                box = box - num;
            }
            // 다 못 담을 때
            else if(box > 0){
                truck[take] = truck[take] + box;
                box = 0;
            }
            cout << "현재 넣을 수 있는 박스" << box << " \n";
        }
        cout << "\n\n\n";
    }

    cout << res;

}

그냥 그리디 바로 적용 x, 2번예제에서 시작지점에서 도착지점까지의 거리에 따른 그리디를 적용해야할듯? 1시간 걸렸는데... 흠.. 예제를 미리 적용 해봤으면 코드 다 짜고 했을 때  시간 절약 되었을듯, 그리고 코드 너무 더럽게 짯다. pair 막 쓰지 말고 struct로 깔끔하게 다시 짜야할듯 더러워서 시간 더 걸림 
