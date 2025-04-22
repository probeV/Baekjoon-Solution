#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> mv = {{1,0},{0,1},{-1,0},{0,-1}};

struct q_type {
    int cnt;
    int x;
    int y;
    vector<vector<int>> pos;
};

bool checking(const vector<vector<int>>& pos) {
    int num = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 2 && j == 2) {
                if(pos[i][j] != 0) return false;
            } else {
                if(pos[i][j] != num++) return false;
            }
        }
    }
    return true;
}

// 퍼즐 상태를 문자열로 변환
string toString(const vector<vector<int>>& pos) {
    string s;
    for(auto& row : pos) {
        for(auto& val : row) {
            s += to_string(val);
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> arr(3, vector<int>(3));
    int zx, zy;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0) {
                zx = j;
                zy = i;
            }
        }
    }

    queue<q_type> q;
    set<string> isVisited;

    q.push({0, zx, zy, arr});
    isVisited.insert(toString(arr));

    int res = -1; // 실패했을 때를 대비해서 -1 초기화

    while(!q.empty()) {
        int cnt = q.front().cnt;
        int x = q.front().x;
        int y = q.front().y;
        vector<vector<int>> pos = q.front().pos;
        q.pop();

        if(checking(pos)) {
            res = cnt;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int next_x = x + mv[i].first;
            int next_y = y + mv[i].second;

            if(next_x < 0 || next_x >= 3 || next_y < 0 || next_y >= 3) continue;

            vector<vector<int>> next_pos = pos;
            swap(next_pos[y][x], next_pos[next_y][next_x]);

            string next_state = toString(next_pos);
            if(isVisited.find(next_state) == isVisited.end()) {
                isVisited.insert(next_state);
                q.push({cnt+1, next_x, next_y, next_pos});
            }
        }
    }

    cout << res;
}
