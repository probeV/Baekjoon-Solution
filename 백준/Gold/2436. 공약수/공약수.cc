#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

int A, B;
pair<long long, long long> divisor;

long long gcd(long long a, long long b){ // a > b
  if(b==0){
    return a;
  }
  else {
    return gcd(b, a%b);
  }
}

long long lcm(long long g, long long a, long long b){
  return (a*b)/g;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> A >> B; // A 최대공약수, B 최소공배수

  long long X = (long long)A*B;
  
  long long res = 9223372036854775807ll;
  for(int i=1;i<=(int)sqrt(X);i++){
    pair<long long, long long> temp;
    if(X%i==0){
      temp.first=i;

      if(i != X/i){
        temp.second=X/i;
      }
      else {
        temp.second=i;
      }

      if(res > temp.first + temp.second){
        int temp_gcd = gcd(temp.second, temp.first);
        if( temp_gcd == A && lcm(temp_gcd, temp.second, temp.first) == B){
          res = temp.first + temp.second;
          divisor.first=temp.first;
          divisor.second=temp.second;
        }
      }
    }
  }

  cout << divisor.first << " " << divisor.second;
}

