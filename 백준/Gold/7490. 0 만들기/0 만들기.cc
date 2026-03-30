#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<string> result;

void Calculate(deque<char> &arr){
  int next=0;

  vector<int> num;
  vector<char> cal;

  // parsing
  for(char a:arr){
    
    if(a >= '0' && a <= '9'){
      if(next!=0){
        next = next * 10 + (a-'0');
      }
      else{
        next = a-'0';
      }
    }
    else if(a == ' '){

    }
    else{ // 부호
      num.push_back(next);
      next=0;

      cal.push_back(a);
    }
  }
  num.push_back(next);

  // for(int a:num) cout << a << ",";
  // cout << "\n";
  // for(char a:cal) cout << a << ",";
  // cout << "\n";

  // calculate
  int res=num[0]; 
  for(int i=1;i<num.size();i++){
    int C = cal[i-1];
    if(C=='+'){
      res = res + num[i];
    }
    else { // -
      res = res - num[i];
    }
  }

  // cout << res << "\n\n";
  // for(char a:arr){
  //   cout << a;
  // }
  // cout << "\n";
  
  if(res==0){
    string str(arr.begin(), arr.end());
    result.push_back(str);
    // cout << str << "\n";
  }
}

void BackTracking(int prev, deque<char> arr){
  if(prev>N-1){
    Calculate(arr);
    return;
  }

  int curr=prev+1;

  // for(char a:arr){
  //   cout << a;
  // }
  // cout << "\n";

  // + 
  arr.push_back('+');
  arr.push_back(curr+'0');
  BackTracking(curr, arr);
  arr.pop_back(); arr.pop_back();

  // -
  arr.push_back('-');
  arr.push_back(curr+'0');
  BackTracking(curr, arr);
  arr.pop_back(); arr.pop_back();

  // 이어 붙이기
  arr.push_back(' ');
  arr.push_back(curr+'0');
  BackTracking(curr, arr);
  arr.pop_back();
  
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for(int i=1;i<=T;i++){
    cin >> N;
    result.clear();

    deque<char> arr;
    arr.push_back(1+'0');
    BackTracking(1, arr);

    sort(result.begin(), result.end());
    
    for(string s : result) cout << s << "\n";
    cout << "\n";
  }

  
  
}