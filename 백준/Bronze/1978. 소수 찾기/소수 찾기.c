#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

int visited[1001] = { 0, };

void Eratosthenes(int num) {
	for (int i = 2; i <= num; i++) {
		if (visited[i] == true) continue;
		for (int j = 2;j*i<=num;j++) {
			visited[i * j] = true;
		}
	}
}

int main(void) {
	int num, result=0;
	scanf("%d", &num);
	int* arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	Eratosthenes(1000);
	for (int i = 0; i < num; i++) {
		if (arr[i] != 1 && visited[arr[i]] == false) result++;
	}
	printf("%d", result);
	return 0;
}