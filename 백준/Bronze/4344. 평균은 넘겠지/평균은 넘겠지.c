#include <stdio.h>

int main(void) {
    int num, N;

    scanf("%d", &num);
    
    while(num--) {
        scanf("%d", &N);
        int score[N], sum=0, high=0;
        double avg = 0;
        for(int i=0; i<N; i++) {
            scanf("%d", score+i);
            sum += score[i];
        }           
        avg = (double)sum/N;
        for(int i=0; i<N; i++) if(score[i] > avg) high++;
        printf("%.3lf%%\n", (double)high*100/N);
    }
}