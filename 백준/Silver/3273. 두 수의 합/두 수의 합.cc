#include<bits/stdc++.h>

using namespace std;

int n, x;
vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    cin >> x;

    sort(arr.begin(), arr.end());

    int right = n-1;
    int res=0;
    for(int left=0;left<right;left++){

        while(arr[left]+arr[right] > x){
            right--;
        }

        if(left<right && arr[left]+arr[right]==x){
            res++;
        }
    }

    cout << res;
}