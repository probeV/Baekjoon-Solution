#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Data {
    int zeronum;
    int onenum;
}Data;

Data data, sub1data, sub2data, temp;

int fibonacci(int n) {
    sub1data.zeronum = 1;
    sub1data.onenum = 0;
    sub2data.zeronum = 0;
    sub2data.onenum = 1;
    for (int i = 2; i <= n && n >= 2; i++) {
        temp = sub2data;
        sub2data.zeronum = sub1data.zeronum + sub2data.zeronum;
        sub2data.onenum = sub1data.onenum + sub2data.onenum;
        sub1data = temp;
    }
}

int main(void) {
    int num, x;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        data.zeronum = 0; data.onenum = 0;
        scanf("%d", &x);
        fibonacci(x);
        if(x==0) printf("%d %d\n", sub1data.zeronum, sub1data.onenum);
        else printf("%d %d\n", sub2data.zeronum, sub2data.onenum);
    }
    return 0;
}