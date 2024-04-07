#include <iostream>
using namespace std;

int main() {
    int H, W, N, M;
    int result;
    
    cin >> H >> W >> N >> M;   
    
    if(H%(N+1)==0)
        result = H/(N+1);
    else
        result = H/(N+1)+1;
    
    if(W%(M+1)==0)
        result *= W/(M+1);
    else
        result *= W/(M+1)+1;
    
    cout << result;
    
    return 0;
}