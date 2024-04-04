#include  <bits/stdc++.h>

using namespace std;

#define MAXSIZE 500001

int N, M, L, K;
vector<pair<int, int>> star;
int res = 0;

int main(){
    cin >> N >> M >> L >> K;

    int x, y;
    star.push_back({0,0});
    for(int i=1;i<=K;i++){
        cin >> x >> y;

        star.push_back({x, y});
    }

    for(int i=1;i<=K;i++){
        int x = star[i].first;
        int nx = x + L;
        for(int j=1;j<=K;j++){
            int temp=0;
            int y = star[j].second;
            int ny = y + L;

            for(int k=1;k<=K;k++){
                int curr_x = star[k].first;
                int curr_y = star[k].second;
                if(curr_x <= nx && curr_x >= x && curr_y <= ny && curr_y >= y){
                    temp++;
                }
            }

            if(res < temp){
                res = temp;
            }
        }
    }

    cout << K-res;
}