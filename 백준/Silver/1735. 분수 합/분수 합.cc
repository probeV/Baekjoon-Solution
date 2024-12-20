#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main(){
    cin >> a >> b >> c >> d;

    int up = a*d + c*b;
    int down = b*d;

    int tmp = gcd(up, down);

    cout << up/tmp << " " << down/tmp;
}