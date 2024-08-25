#include<bits/stdc++.h>

using namespace std;

int R, C;
vector<vector<char> > arr;
pair<int, int> arduino;
vector<pair<int, int> > crazy_arduino;
string movement;

vector<pair<int, int> > mv = {{0,0}, {-1,1}, {0,1}, {1,1}, {-1,0}, {0,0}, {1,0}, {-1,-1}, {0,-1}, {1,-1}};

int main(){
    cin >> R >> C; getchar();

    arr.resize(R+1, vector<char>(C+1));
    for(int y=1;y<=R;y++){
        for(int x=1;x<=C;x++){
            char c = getchar();
            arr[y][x]=c;

            if(arr[y][x]=='I'){
                arduino.first = x;
                arduino.second = y;
            }
            else if(arr[y][x]=='R'){
                crazy_arduino.push_back({x,y});
            }
        }
        getchar();
    }

    cin >> movement;

    for(int i=0;i<movement.size();i++){
        int order = movement[i]-48;

        //아두이노 이동
        int next_x = arduino.first + mv[order].first;
        int next_y = arduino.second + mv[order].second;

        // 아두이노 이동 한 곳이 미친 아두이노가 있을 때
        if(arr[next_y][next_x]=='R'){
            cout << "kraj " << i+1;
            return 0;
        }
        // 아두이노 이동 한 곳이 . 일때
        else if(arr[next_y][next_x]=='.'){
            // 원래 있던 아두이노 삭제
            arr[arduino.second][arduino.first] = '.';

            // 좌표 업데이트
            arduino.first = next_x;
            arduino.second = next_y;

            // 이동한 아두이노 명시
            arr[next_y][next_x] = 'I';
        }

        vector<vector<bool> > crazy_broke(R+1, vector<bool>(C+1, false));
        // 미친 아두이노 이동
        for(int k=0;k<crazy_arduino.size();k++){
            int curr_x = crazy_arduino[k].first;
            int curr_y = crazy_arduino[k].second;

            // 이미 파괴된 아두이노이면
            if(arr[curr_y][curr_x]=='.'){
                crazy_arduino[k].first=0;
                crazy_arduino[k].second=0;
                continue;
            }

            // 원래 있던 미친 아두이노 삭제
            arr[curr_y][curr_x] = '.';

            int dist=INT_MAX;
            int new_x, new_y;
            for(int z=1;z<=9;z++){
                int next_x = curr_x + mv[z].first;
                int next_y = curr_y + mv[z].second;

                // 미친 아두이노가 범위가 넘어갔을 때 
                if(next_x < 1 || next_y < 1 || next_x > C || next_y > R) continue;

                // 이동 했을 때 아두이노와 제일 가까운 좌표 체크
                int new_dist = abs(arduino.first - next_x) + abs(arduino.second - next_y);
                if(dist > new_dist){
                    dist = new_dist;
                    new_x = next_x;
                    new_y = next_y;
                }
            }

            // 좌표 업데이트
            crazy_arduino[k].first = new_x;
            crazy_arduino[k].second = new_y;

            if(arr[new_y][new_x]=='I'){
                cout << "kraj " << i+1;
                return 0;
            }
        }

        // 곂친 아두이노 체크
        for(int k=0;k<crazy_arduino.size();k++){
            int curr_x = crazy_arduino[k].first;
            int curr_y = crazy_arduino[k].second;

            if(arr[curr_y][curr_x]=='R'){
                crazy_broke[curr_y][curr_x] = true;
                continue;
            }

            arr[curr_y][curr_x]='R';
        }

        // 부숴진 아두이노 업데이트
        for(int k=0;k<crazy_arduino.size();k++){
            int curr_x = crazy_arduino[k].first;
            int curr_y = crazy_arduino[k].second;

            if(crazy_broke[curr_y][curr_x]){
                arr[curr_y][curr_x]='.';
            }
        }

        // for(int y=1;y<=R;y++){
        //     for(int x=1;x<=C;x++){
        //         cout << arr[y][x];
        //     }
        //     cout << "\n";
        // }
        // cout << "-----------------------\n";
    }   

    for(int y=1;y<=R;y++){
        for(int x=1;x<=C;x++){
            cout << arr[y][x];
        }
        cout << "\n";
    }
}