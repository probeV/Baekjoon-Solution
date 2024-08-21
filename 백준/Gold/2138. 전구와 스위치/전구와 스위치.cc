#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> init;
vector<int> res;

void change(vector<int> &arr, int x, int y, int z){
    if(arr[x]==0) arr[x]=1;
    else arr[x]=0;

    if(arr[y]==0) arr[y]=1;
    else arr[y]=0;

    if(arr[z]==0) arr[z]=1;
    else arr[z]=0;
}

int main(){
    cin >> N;

    for(int i=1;i<=N;i++){
        int temp;
        scanf("%1d", &temp);
        init.push_back(temp);
    }

    for(int i=1;i<=N;i++){
        int temp;
        scanf("%1d", &temp);
        res.push_back(temp);
    }

    //cout << res[0] << res[1];

    // 처음 부터 누르고 시작
    vector<int> arr;
    arr.resize(init.size());
    copy(init.begin(), init.end(), arr.begin());
    arr.push_back(0);
    int temp1=0;

    //cout << arr[0] << "" << arr[1];

    for(int i=0;i<N;i++){
        if(i==0){
            temp1++;
            if(arr[i]==0) arr[i]=1;
            else arr[i]=0;

            if(arr[i+1]==0) arr[i+1]=1;
            else arr[i+1]=0;

            //cout << arr[0] << " " << arr[1];
            continue;
        }

        // cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
        // cout << res[0] << " " << res[1] << " " << res[2] << "\n\n";

        if(arr[i-1]==res[i-1]) continue;
        else{
            temp1++;
            change(arr, i-1, i, i+1);
            
        }
    }

    for(int i=0;i<N;i++){
        if(arr[i]!=res[i]){
            temp1 = INT_MAX;
        }
    }

    // 두번쨰 부터 시작
    copy(init.begin(), init.end(), arr.begin());
    arr.push_back(0);
    int temp2=0;
    for(int i=1;i<N;i++){
        if(arr[i-1]==res[i-1]) continue;
        else{
            temp2++;
            change(arr, i-1, i, i+1);
        }
    }

    for(int i=0;i<N;i++){
        if(arr[i]!=res[i]){
            temp2 = INT_MAX;
        }
    }

    int result = min(temp1, temp2);
    
    if(result == INT_MAX) cout << -1;
    else cout << result;
}