#include<bits/stdc++.h>

using namespace std;

int p, m;
vector<pair<int, string> > user;
vector<vector<pair<int, string> > > room;

int compare(pair<int, string> &a, pair<int, string> &b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    cin >> p >> m;

    user.resize(p+1);
    for(int i=1;i<=p;i++){
        cin >> user[i].first >> user[i].second;
    }

    for(int i=1;i<=p;i++){
        //플레이어 입장 신청
        int curr_level = user[i].first;
        string curr_name = user[i].second;

        bool isRoom = false;
        for(int j=0;j<room.size();j++){
            // 매칭 가능한 방 있을 때 && 정원이 다 차지 않았다면
            if(room[j][0].first - 10 <= curr_level && room[j][0].first + 10 >= curr_level && room[j].size() < m){
                room[j].push_back({curr_level, curr_name});
                isRoom = true;
                break;
            }
        }
        // 매칭 가능한 방이 없을 때 방 생성
        if(!isRoom){
            room.push_back(vector<pair<int, string> >(1, {curr_level, curr_name}));
        }
    }

    
    // 정원이 꽉 찬 방 게임 시작
    for(int j=0;j<room.size();j++){
        if(room[j].size() == m){
            cout << "Started!" << "\n";
        }
        else{
            cout << "Waiting!" << "\n";
        }

        sort(room[j].begin(), room[j].end(), compare);
        for(int k=0;k<room[j].size();k++){
            cout << room[j][k].first << " " << room[j][k].second << "\n";
        }

    }
}