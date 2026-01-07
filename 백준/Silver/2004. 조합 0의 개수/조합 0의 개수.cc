#include <iostream>
#include <algorithm>
using namespace std;

// n!에서 소수 p의 지수를 구하는 함수 (Legendre's Formula)
long long countPrimeInFactorial(long long n, long long p) {
    long long count = 0;
    long long power = p;
    
    while (power <= n) {
        count += n / power;
        // 오버플로우 방지: power * p > n인 경우 중단
        if (power > n / p) break;
        power *= p;
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m;
    cin >> n >> m;
    
    // C(n,m) = n! / (m! * (n-m)!)
    // 끝자리 0의 개수 = min(2의 지수, 5의 지수)
    
    // 2의 지수 계산
    long long twos = countPrimeInFactorial(n, 2) 
                   - countPrimeInFactorial(m, 2) 
                   - countPrimeInFactorial(n - m, 2);
    
    // 5의 지수 계산  
    long long fives = countPrimeInFactorial(n, 5)
                    - countPrimeInFactorial(m, 5)
                    - countPrimeInFactorial(n - m, 5);
    
    // 10 = 2 × 5이므로, 10의 지수는 둘 중 작은 값
    cout << min(twos, fives) << '\n';
    
    return 0;
}