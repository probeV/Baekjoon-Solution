#include <bits/stdc++.h>

using namespace std;

int A, B, C;

long long fpow(int A, int num)
{

    if (num == 1)
    {
        return A;
    }

    long long x = fpow(A, num / 2)%C;

    if (num % 2 == 0)
    {
        long long temp =(x * x)%C;
        return temp;
    }
    else
    {
        long long temp =((x * x)%C * (A%C))%C;
        return temp;
    }
}

int main()
{
    cin >> A >> B >> C;

    cout << fpow(A, B) % C;
}