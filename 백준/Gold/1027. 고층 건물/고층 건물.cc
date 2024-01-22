#include <bits/stdc++.h>

using namespace std;

#define MAX 51

int N;

int res[MAX]={};
long long hight[MAX];



int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> hight[i];
    }

    for(int x=1;x<N;x++){
        for(int i=x+1;i<=N;i++){
            //인접해 있다면 보임
            if(x+1==i){
                res[x]++; res[i]++;
            }
            else{
                double Xa=x, Ya=hight[x];
                double Xb=i, Yb=hight[i];

                //중간 빌딩 높이 체크
                for(int j=x+1;j<i;j++){
                    //중간 빌딩이 가린다면
                    if(hight[j]>=(Yb-Ya)/(Xb-Xa)*(j-Xa)+Ya){
                        break;
                    }
                    //중간 빌딩이 하나도 가리지않는다면
                    if(j==i-1){
                        res[x]++; res[i]++;
                    }
                }
            }
        }
    }

    int result=0;
    for(int i=1;i<=N;i++){
        if(result < res[i]){
            result=res[i];
        }
    }
    
    cout << result;

}