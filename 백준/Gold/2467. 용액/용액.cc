#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;

int main(){
    cin >> N;

    for(int i=1;i<=N;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    int str=0, end=arr.size()-1;
    int sum=abs(arr[str]+arr[end]);
    int min=sum;
    int res_str=str, res_end=end;

    while(str < end){

        if(sum >= abs(arr[str]+arr[end-1]) && str < end-1){
            end--;
            sum=abs(arr[str]+arr[end]);

            if(min > sum){
                min = sum;
                res_str=str; res_end=end;
            }
            
            continue;
        }

        if(sum >= abs(arr[str+1]+arr[end]) && str+1 < end){
            str++;
            sum=abs(arr[str]+arr[end]);

            if(min > sum){
                min = sum;
                res_str=str; res_end=end;
            }

            continue;
        }  



        if(str+1 < end-1){
            str++; end--;
            sum=abs(arr[str]+arr[end]);

            if(min > sum){
                min = sum;
                res_str=str; res_end=end;
            }

            continue;
        }   

        break;
    }

    cout << arr[res_str] << " " << arr[res_end];
}