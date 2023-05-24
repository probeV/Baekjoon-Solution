#include <stdio.h>

int main(void)
{
    int x, key = 0, i = 2, j = 1, k, cnt = 2;
    
    scanf("%d", &x);
    
    if(x == 1)
    {
        printf("1/1");
        return 0;
    }
    
    while(1)
    {
        if(i <= x && i + j >= x)
        {
            if(j % 2 == 1) key = 0;
            else key = 1;
            break;
        }
        i = i + j + 1;
        j++;
    }
    
    i = 2;
    while(1)
    {
        j = 1;
        for(k = i; k > 0; k--)
        {
            if(x == cnt)
            {
                printf("%d/%d", (key == 1) ? k : j, (key == 1) ? j : k);
                return 0;
            }
            j++; cnt++;
        }
        i++;
    }
    return 0;
}