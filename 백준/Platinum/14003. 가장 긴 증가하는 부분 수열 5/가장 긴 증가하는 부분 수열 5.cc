#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 1000001

int seq[MAXSIZE], pos[MAXSIZE], LIS[MAXSIZE];
int idx = 1;


//idx는 LIS의 인덱스
//n은 pos의 인덱스
void BinarySearch(int target, int n) {
    int front = 1, end = idx, mid;

    //최댓값이 갱신되었을 때
    if (LIS[idx] < target) {
        LIS[++idx] = target;
        pos[n + 1] = idx;
        return;
    }

    while (front <= end) {
        mid = (front + end) / 2;

        if (LIS[mid] < target) {
            front = mid + 1;
        }
        else if (LIS[mid] > target) {
            end = mid - 1;
        }
        else {
            //이미 LIS 배열에 같은 수가 있을 때
            //해당 숫자가 LIS에서의 위치만 추가
            pos[n + 1] = mid;
            return;
        }
    }


    //선정된 mid가 target보다 작을 때
    //선정된 mid 보다 한칸 앞에 LIS 넣어야함 
    if (LIS[mid] < target) {
        LIS[mid + 1] = target;
        pos[n + 1] = mid+1;
    }
    //선정된 mid가 target 보다 클 때
    //선정된 mid에 그대로 LIS에 넣어야함 
    else if(LIS[mid] > target) {
        LIS[mid] = target;
        pos[n + 1] = mid;
    }


}

int main(void) {
    int N;

    cin >> N;

    int ipt;
    for (int i = 1; i <= N; i++) {
        cin >> ipt;
        seq[i] = ipt;
    }

    pos[1] = 1;
    LIS[1] = seq[1];

    for (int i = 2; i <= N; i++) {
        BinarySearch(seq[i], i - 1);
    }

    int max = INT_MIN;
    for (int i = 1; i <= N; i++) {
        if (max < pos[i]) {
            max = pos[i];
        }
    }

    cout << max << "\n";

    vector<int> res;
    for(int i=N;i>0;i--){
        if(pos[i]==max){
            res.push_back(seq[i]);
            max--;
        }
    }

    //출력
    for(int i=res.size()-1;i>=0;i--){
        cout << res[i] << " ";
    }
}
