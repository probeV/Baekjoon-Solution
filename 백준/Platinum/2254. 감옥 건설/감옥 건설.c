#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define SIZE 1000
#define INF INT_MAX

typedef struct {
	int x, y;
	bool visited;
}Arr;

Arr arr[SIZE + 1]; int stack[SIZE + 1]; int top; int count = 0;
int Mx, My;

int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
	long long temp = 1LL*(x2 - x1)*(y3 - y1) - 1LL*(x3 - x1)*(y2 - y1);
	
	if(temp < 0) //우회전 
		return -1;
	else if(temp > 0) //좌회전 
		return 1;
	return 0;
}

int compare(const void* x, const void* y) {
	double temp1 = atan2(((Arr *)x)->x-Mx, ((Arr *)x)->y-My);
	double temp2 = atan2(((Arr *)y)->x-Mx, ((Arr *)y)->y-My);
	
	if (temp1 < temp2)
		return 1;
	else if (temp1 > temp2)
		return -1;
	else
		return 0;
}

int find_start(int N) {
	Mx = INF; My = INF; top = -1;
	for (int i = 0; i < N; i++) {
		if (!arr[i].visited) {
			if (My > arr[i].y) {
				Mx = arr[i].x; My = arr[i].y;
			}
			else if (My == arr[i].y && Mx < arr[i].x) {
				Mx = arr[i].x;
			}
		}
	}
	if (Mx == INF || My == INF)
		return 0;
	else
		return 1;
}

int main(void) {
	int N, Px, Py;
	scanf("%d %d %d", &N, &Px, &Py);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
		arr[i].visited = false;
	}
	
	while(find_start(N)){
		qsort((Arr*)arr, N, sizeof(Arr), compare); int c;

		for (int i = 0; i < N; i++)
			if (Mx == arr[i].x && My == arr[i].y)
				stack[++top] = i;

//		printf("시작점 %d : %d %d\n", stack[0], Mx, My);
//		for (int i = 0; i < N; i++)
//			printf("%d : %d %d\n", i, arr[i].x, arr[i].y);

		for (int i = 0; i < N; i++) {
			if (!arr[i].visited && i != stack[0]) {
				stack[++top] = i;
				if (top <= 1)
					arr[i].visited = true;
				else {
					c = ccw(arr[stack[top - 2]].x, arr[stack[top - 1]].x, arr[stack[top]].x, arr[stack[top - 2]].y, arr[stack[top - 1]].y, arr[stack[top]].y);
					if (c == 1)//좌회전 
						arr[i].visited = true;
					else {//우회전 
						while (c != 1) {
							arr[stack[--top]].visited = false;
							stack[top] = i;
							arr[i].visited = true;
							if(top>=2)
								c = ccw(arr[stack[top - 2]].x, arr[stack[top - 1]].x, arr[stack[top]].x, arr[stack[top - 2]].y, arr[stack[top - 1]].y, arr[stack[top]].y);
							else
								break;
						}
					}
				}
			}
		}

		stack[++top] = stack[0];
		c = ccw(arr[stack[top - 2]].x, arr[stack[top - 1]].x, arr[stack[top]].x, arr[stack[top - 2]].y, arr[stack[top - 1]].y, arr[stack[top]].y);
		if (c==1)//좌회전 
			arr[stack[0]].visited = true;
		else {//우회전 
			while (c != 1) {
				arr[stack[--top]].visited = false;
				stack[top] = stack[0];
				arr[stack[0]].visited = true;
				if(top>=2)
					c = ccw(arr[stack[top - 2]].x, arr[stack[top - 1]].x, arr[stack[top]].x, arr[stack[top - 2]].y, arr[stack[top - 1]].y, arr[stack[top]].y);
				else
					break;					
			}
		}

//		printf("----------------\n");
//		for (int i = 0; i <= top; i++)
//			printf("%d -> %d %d\n", stack[i], arr[stack[i]].x, arr[stack[i]].y);
//			
		if (top > 2) {
			top = 0;
			do {
				top++;
				c = ccw(arr[stack[top - 1]].x, arr[stack[top]].x, Px, arr[stack[top - 1]].y, arr[stack[top]].y, Py);
				if (c != 1)
					break;
			} while (stack[top] != stack[0]);
			
			if(c!=-1 && stack[top]==stack[0])
				count++;
			else
				break;
		}
		else
			break;
	}
	
	printf("%d", count);
	return 0;
}