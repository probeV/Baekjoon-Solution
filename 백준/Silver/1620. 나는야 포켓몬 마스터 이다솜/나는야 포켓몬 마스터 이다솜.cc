#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> name;
map<int, string> number;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;

        name.insert({temp, i});
        number.insert({i,temp});
    }

    for(int i=0;i<M;i++){
        string temp;
        cin >> temp;

        //숫자일 때
        if(temp[0]-'0'>0 && temp[0]-'0'<=9){
            cout << number[stoi(temp)-1] << "\n";
        }
        //알파벳일 때
        else{
            cout << name[temp]+1 << "\n";
        }
    }
}