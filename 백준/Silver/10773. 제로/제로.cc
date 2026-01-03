#include <iostream>
#include <vector>

using namespace std;

int K, top;
vector<int> stack;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> K;
  int tmp;
  stack.resize(100001);
  for(int i=1;i<=K;i++){
    cin >> tmp;
    if(tmp == 0){
      top--;
    }    
    else{
      stack[top]=tmp;
      top++;
    }
  }

  int res=0;
  for(int i=0;i<top;i++){
    res+=stack[i];
  }

  cout << res;
}