#include <stdio.h>
 
int main() {
    int n, x;
    scanf("%d %d", &n, &x);
 
    int value;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        if (value < x) printf("%d ", value);
    }
    return 0;
}