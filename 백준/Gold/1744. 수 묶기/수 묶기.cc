#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> plu;
vector<int> minu;
int zero=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1;i<=N;i++){
        int temp;
        cin >> temp;
        if(temp > 0){
            plu.push_back(temp);
        }
        else if(temp == 0){
            zero++;
        }
        else if(temp < 0){
            minu.push_back(temp);
        }
    }

    sort(plu.begin(), plu.end(), greater<int>());
    sort(minu.begin(), minu.end());

    int res=0;
    // plu 먼저 처리
    for(int i=0;i<plu.size();i++){
        if(i==plu.size()-1) { // 뒤에 숫자가 더 없을 때
            res += plu[i];
            continue;
        }

        // 뒤에 숫자가 더 있을 때 
        if(plu[i]!=1 && plu[i+1] > 1){ // 현재 숫자가 1이 아니고 뒤 숫자가 양수(1 이상의) 일 때 
            res += plu[i+1]*plu[i];
            i++;
        }
        else{
            res += plu[i];
        }
    }

    // minu 처리
    for(int i=0;i<minu.size();i++){
        if(i==minu.size()-1) { // 뒤에 숫자가 더 없을 때
            if(zero > 0){ // 0 이 있으면 남은 음수 없애버리기기
                continue;
            }
            
            res += minu[i];
            continue;
        }

        // 뒤에 숫자가 더 있을 때 
        res += minu[i+1]*minu[i];
        i++;
    }

    cout << res;
}


// 음수*음수, 양수*양수, 0*음수, 1은 패스  
// 큰거 중심으로 곱 시작 
// -> 곱이 더 안좋을 수도 있네
// 0과 음수는 조금 다르네 -> 가장 큰 음수 * 가장 큰 음수 or 가장 큰 음수 * 0 

// 1 1 1 4
// 0 0 0 0 4

// -1
// -1 0 1
// 1 1
