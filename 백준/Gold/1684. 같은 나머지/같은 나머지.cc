#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

int n;
vector<int> arr;

// N = D*Q + R
// 모든 정수를 D 로 나눴을 때 나머지가 같아지는 경우, 가장 큰 D 

int gcd(int a, int b){
  if(a<b){
    int tmp=a;
    a=b;
    b=tmp;
  }

  if(b==0){
    return a;
  }
  else {
    return gcd(b, a%b);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;
  arr.resize(n);
  for(int i=1;i<=n;i++){
    cin >> arr[i];
  }
  sort(arr.begin()+1, arr.end());

  int res=abs(arr[2]-arr[1]);
  for(int i=3;i<=n;i++){
    res = gcd(res, abs(arr[i]-arr[i-1]));
  }

  cout << res;
}

