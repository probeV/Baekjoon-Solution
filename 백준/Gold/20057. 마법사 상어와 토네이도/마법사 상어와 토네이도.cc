#include<bits/stdc++.h>

using namespace std;

int N;
vector<vector<int> > arr;

vector<pair<int, int> > mv = {{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int, pair<int, int> > > sand_mv = { {5, {-2,0}},
    {10, {-1,-1}}, {7, {0, -1}}, {1, {1,-1}}, {2, {0,-2}},
    {10, {-1,1}},{7, {0,1}}, {1, {1,1}}, {2, {0,2}}, {0, {-1,0}} }; // 방향 (-1,0) 방향 기준

int res;

int main(){
    cin >> N;

    arr.resize(N+1, vector<int>(N+1));

    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            cin >> arr[y][x];
        }
    }

    int curr_x = (N+1)/2;
    int curr_y = (N+1)/2;
    int dir = 0;

    while(curr_x!=1 || curr_y!=1){
        // for(int y=1;y<=N;y++){
        //     for(int x=1;x<=N;x++){
        //         cout << arr[y][x] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "--------\n";

        int dir_idx = dir%4;
        int movement = min((dir/2+1), N-1);
        dir++;

        // 토네이도 방향 + 이동 거리 
        for(int i=1;i<=movement;i++){
            int next_x = curr_x + mv[dir_idx].first;
            int next_y = curr_y + mv[dir_idx].second;

            //cout << next_x << next_y << " " << arr[next_y][next_x] << "\n";

            int sand = arr[next_y][next_x];
            int sand_moved_total = 0;

            // 토네이도 이동 시 모래 계산
            for(int k=0;k<10;k++){
                int per = sand_mv[k].first;
                int dx = sand_mv[k].second.first;
                int dy = sand_mv[k].second.second;

                if(dir_idx==1){
                    int temp=dx;
                    dx=-dy;
                    dy=-temp;
                }
                else if(dir_idx==2){
                    dx=-dx;
                }
                else if(dir_idx==3){
                    int temp=dx;
                    dx=dy;
                    dy=temp;
                }

                //cout << per << " " << dx << dy << "\n";

                int sand_x = next_x + dx;
                int sand_y = next_y + dy;
                int sand_moved;

                if(k==9){
                    sand_moved = sand - sand_moved_total;
                }
                else{
                    sand_moved = (per*sand)/100;
                    sand_moved_total += sand_moved;
                }

                //격자 바깥으로 나간 모래
                if(sand_x < 1 || sand_x > N || sand_y < 1 || sand_y > N){
                    //cout << "\n";
                    res += sand_moved;
                    continue;
                }

                arr[sand_y][sand_x] += sand_moved;

                //cout  << sand_x << sand_y << " " << arr[sand_y][sand_x] << "\n";
            }
            
            curr_x = next_x;
            curr_y = next_y;
            arr[curr_y][curr_x]=0;
        }
    }

    cout << res;
}