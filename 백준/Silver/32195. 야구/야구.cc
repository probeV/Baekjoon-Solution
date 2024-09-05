#include<bits/stdc++.h>

using namespace std;

int N, Q;
vector<int> R;  

struct ball_distance {
    long long dis;
    int x;
    int y;

    // 비교 연산자 오버로드
    bool operator<(const ball_distance& other) const {
        return dis < other.dis;
    }
};

struct ball_info {
    int in;
    int ho;
};

int foul = 0;
vector<struct ball_distance> ball;
vector<struct ball_info> res;

void bianry_search(long long r, int idx) {
    int front = 0, end = ball.size() - 1, mid;

    while (front <= end) {
        mid = (front + end) / 2;
            
        // 경계 찾기
        if (r >= ball[mid].dis) {
            front = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    res[idx].ho = ball.size() - front;
    res[idx].in = front;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1;i <= N;i++) {
        int temp_x, temp_y;
        cin >> temp_x >> temp_y;

        // 파울 체크
        if (temp_y >= temp_x && temp_y >= temp_x * -1) {
            long long temp_dis = (long long)(pow(temp_x, 2) + pow(temp_y, 2));
            ball.push_back({ temp_dis, temp_x, temp_y });
        }
        else {
            foul++;
        }
    }
    sort(ball.begin(), ball.end());

    cin >> Q;
    R.resize(Q + 1);
    for (int i = 1;i <= Q;i++) {
        cin >> R[i];
    }

    res.resize(Q+1);
    for (int i = 1;i <= Q;i++) {
        int curr_R = R[i];
        
        bianry_search((long long)pow(curr_R,2), i);
    }

    for (int i = 1;i <= Q;i++) {
        cout << foul << " " << res[i].in << " " << res[i].ho << "\n";
    }
}