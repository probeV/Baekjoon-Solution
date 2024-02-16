#include <bits/stdc++.h>
using namespace std;
int main(void){
	int People[1001]={}, cnt=0, N, K, delcnt=0, Kcnt=0;
	scanf("%d %d",&N,&K);
	memset(People, 0, 1001*sizeof(int));
	People[0] = -1;
	printf("<");
	while(cnt<N){
		delcnt++;
		if(delcnt>N)
			delcnt -= N;
		if(People[delcnt]==0){
			Kcnt++;
			if(Kcnt==K){
				if(cnt==N-1){
					printf("%d",delcnt);
					cnt++;
				}	
				else{
					People[delcnt] = -1;
					printf("%d, ",delcnt);
					Kcnt -= K;
					cnt++;
				}	
			}
		}
	}
	printf(">");
}