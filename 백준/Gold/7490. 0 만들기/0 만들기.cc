#include <bits/stdc++.h>

using namespace std;

int T, N;
string str;

void Solve(int pos, int sum, int last){
  if(pos==N+1){
    if(sum + last==0){
      cout << str << "\n";
    }
    return;
  }


  // 붙이기
  str+=' '; str += ('0'+pos);
  int newLast = (last>=0) ? last*10 + pos : last*10-pos; 
  Solve(pos+1, sum, newLast);
  str.pop_back(); str.pop_back();
  
  // 덧셈
  str += '+'; str += ('0' + pos);
  Solve(pos + 1, sum + last, pos);
  str.pop_back(); str.pop_back();

  // 뺄셈
  str += '-'; str += ('0' + pos);
  Solve(pos + 1, sum + last, -  pos);
  str.pop_back(); str.pop_back();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for(int i=1;i<=T;i++){
    cin >> N;

    str='1';
    Solve(2,0,1);

    cout << "\n";
  }
}