#include<bits/stdc++.h>
using namespace std;

int N;

int isLarge(vector<int> &arr, int left, int right){
    int res=0;

    while(left < right){
        int score = (right-left-1) * min(arr[left], arr[right]);
        res = (res > score) ? res : score;
        if(arr[left] < arr[right]){
            left++;
        }
        else if(arr[left] > arr[right]){
            right--;
        }
        else{
            left++;
            right--;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    cout << isLarge(arr, 0, N-1);

}