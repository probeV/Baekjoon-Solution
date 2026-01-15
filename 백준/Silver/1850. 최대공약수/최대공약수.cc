#include <iostream>

using namespace std;

long long A, B;

int gcb(long long a, long long b){ // a > b
    if(b==0)
        return a;
    else
        return gcb(b, a%b);
}

int main(){
    cin >> A >> B;

    int res;
    if(A > B) res=gcb(A,B);
    else res=gcb(B,A);

    for(int i=1;i<=res;i++){
        cout << 1;
    }
}
