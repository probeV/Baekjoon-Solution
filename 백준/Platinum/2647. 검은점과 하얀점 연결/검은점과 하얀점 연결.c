#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define INF 9999

int result[50][2]={0,0};
int result_count=0;

void check(int i, int j, int **distance){
	int temp=INF;
	int x1=-1; int y1=-1;
	int x2=-1; int y2=-1;

	if(i+1==j){
		printf("%d %d\n", i,j);
		return;
	}
	
	//최소 찾기 
	for (int k = i; k <= j-1; k++) {
		if (distance[i][k]!=INF && distance[k+1][j]!=INF &&temp > distance[i][k] + distance[k + 1][j]) {
			temp=distance[i][k] + distance[k + 1][j];
			x1=i; y1=k;
			x2=k+1; y2=j;
		}
	}
	if (temp > distance[i][j]) {
		printf("%d %d \n", i,j);
		temp = distance[i][j];
		x1=i+1; y1=j-1;
		x2=-1; y2=-1;
	}
	
	
	if(x1!=-1 && y1!=-1)
		check(x1,y1, distance);
	if(x2!=-1 && y2!=-1)
		check(x2,y2, distance);

}

int main(void) {
	int N;
	scanf("%d", &N);
	getchar();

	char* arr = (char*)malloc(sizeof(char) * (N + 2));
	fgets(arr, N + 2, stdin);
	char* M = (char*)malloc(sizeof(char) * (N + 1));
	for (int i = 1; i <= N; i++)
		M[i] = arr[i - 1];
	free(arr);

	int** distance = (int**)malloc(sizeof(int*) * (N + 1));
	for (int i = 0; i <= N; i++) {
		distance[i] = (int*)malloc(sizeof(int) * (N + 1));
		for (int j = 0; j <= N; j++) {
			distance[i][j] = INF;
		}
	}

	int** H = (int**)malloc(sizeof(int*) * (N + 1));
	for (int i = 0; i <= N; i++) {
		H[i] = (int*)malloc(sizeof(int) * (N + 1));
		memset(H[i], 0, sizeof(int) * (N + 1));
	}

	for (int dia = 0; 2 * dia + 1 <= N - 1; dia++) {
		int D = 2 * dia + 1;
		bool isHight = false;
		for (int i = 1; i <= N - D; i++) {
			int temp = INF;
			int j = i + D;
			
			//i,j 붙어있으면 체크 할 필요 x 
			if (D > 1) {
				for (int k = i + 1; k <= j - 2; k++) {
					if (temp > distance[i][k] + distance[k + 1][j]) {
						temp = distance[i][k] + distance[k + 1][j];
						H[i][j] = H[i][k] > H[k + 1][j] ? H[i][k] : H[k + 1][j];
					}
				}
				if (M[i]!=M[j] && temp > distance[i + 1][j - 1] + j - i + 2 * (H[i + 1][j - 1] + 1)) {
					temp = distance[i + 1][j - 1] + j - i + 2 * (H[i + 1][j - 1] + 1);
					H[i][j] = H[i + 1][j - 1] + 1;
				}
			}
			else { //i,j 붙어있을 때 초기값  
				if (M[i] != M[j]) {
					int h = 1;
					temp = j - i + 2 * h;
				}
				H[i][j] = 1;
			}

			distance[i][j] = temp;

		}
	}

	printf("%d\n", distance[1][N]);
	
//	for(int i=1;i<=N;i++){
//		for(int j=1;j<=N;j++){
//			printf("%d ", distance[i][j]);
//		}
//		printf("\n");
//	}
	
	check(1,N, distance);

	return 0;
}