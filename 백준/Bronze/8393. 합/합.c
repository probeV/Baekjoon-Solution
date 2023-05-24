#include <stdio.h>
int main(void)
{
    int a,i;
    int result =0;
    
    scanf("%d", &a);
    
    for (i=1;i<=a;i++)
        result=result + i;
    
    printf("%d", result);
        return 0;
}