#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

int N;
vector<int> arr;
map<int, int> common;

void getDivisors(int x){
  for(int i=1;i<=(int)sqrt(x);i++){
    if(x%i == 0){
      common[i]++;
      if(i != x/i){
        common[x/i]++;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  arr.resize(N+1);
  for(int i=1;i<=N;i++){
    cin >> arr[i];
  }
  sort(arr.begin()+1, arr.end());
  
  for(int i=1;i<N;i++){
    for(int j=i+1;j<=N;j++){
      getDivisors(arr[j]-arr[i]);
    }
  }

  for (auto& [key, value] : common) {
    if(value == N*(N-1)/2 && key != 1){
      cout << key << " ";
    }
  }
}