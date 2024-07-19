#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr;

int main(){
    cin >> N >> M;

    for(int i=0;i<N;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int str=0, end=0;
    int sum=arr[end];
    int cnt=0;
    while(str!=arr.size() && end!=arr.size()){
        if(sum == M){
            cnt++;
        }

        if (sum > M)
        {
            sum-=arr[str];
            str++;
        }
        
        else if (sum <= M)
        {
            end++;
            sum+=arr[end];
        }
    }

    cout << cnt;

}