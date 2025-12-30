#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<vector<int> > tri;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  tri.push_back({1});
  tri.push_back({1,1});

  for(int i=2;i<=N;i++){
    vector<int> prev_tri=tri[i-1];
    vector<int> curr_tri;

    curr_tri.push_back(1);
    for(int x=0;x<prev_tri.size()-1;x++){
      curr_tri.push_back((prev_tri[x]+prev_tri[x+1])% 10007);
    }
    curr_tri.push_back(1);

    tri.push_back(curr_tri);
  }

  // for(int i=0;i<=N;i++){
  //   vector<int> curr_tri = tri[i];
  //   for(int x=0;x<curr_tri.size();x++){
  //     cout << curr_tri[x] << " ";
  //   }
  //   cout << "\n";
  // }

  cout << tri[N][K];
}