#include <bits/stdc++.h>

using namespace std;

int N, cnt;
set<string> name;

int main(){
    cin >> N;
    
    string temp;
    for(int i=1;i<=N;i++){
        cin >> temp;

        if(temp=="ENTER"){
            name.clear();
        }
        else if(name.find(temp)==name.end()){
            name.insert(temp);
            cnt++;
        }
        else {

        }
    }

    cout << cnt;

    return 0;
}