#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void){
	int T, N, M, X, Y;
	scanf("%d", &T); getchar();
	for(int i=1;i<=T;i++){
		scanf("%d %d", &N, &M); getchar();
		
		char tempX[SIZE], tempY[SIZE];
		for(int j=0;j<M;j++){
			scanf("%c", &tempX[j]); getchar();
		}
		tempX[M]='\0';
		for(int j=0;j<M;j++){
			scanf("%c", &tempY[j]); getchar();
		}
		tempY[M]='\0';
		
		X=atoi(tempX); Y=atoi(tempY);
		
		char arr[101];
		for(int j=0;j<N;j++){
			scanf("%c", &arr[j]); getchar();
		}
		arr[N]='\0';
		
		//구현 
		int idx, res=0;;
		for(int j=0;j<N;j++){
			char temp[SIZE];
			int count=0;
			idx=j; 
			for(int k=0;k<M;k++){
				temp[count++]=arr[(idx+k)%N];
			}
			temp[count]='\0';
			
			int r=atoi(temp);
			
			if(X<=r && Y>=r)
				res++;
		}
		
		printf("%d\n", res); 
	}
}