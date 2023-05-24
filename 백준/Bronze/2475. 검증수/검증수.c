#include <stdio.h>
 
int main() {
    int num, result = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num);
        result = result + num * num;
    }
    printf("%d\n", result % 10);
    return 0;
}