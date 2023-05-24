#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
#define INF -1

int visited[1000001] = { 0, };

void Eratosthenes(int N) {
	for (int i = 2; i*i <= N; i++) {
		if (visited[i] == true) continue;
		for (int j = 2; i*j <= N; j++) {
			visited[i * j] = true;
		}
	}
}

int Goldbach(int* sub1, int* sub2, int result) {
	for (int j = 3; *sub1 <= result; j=j+2) {
		if (visited[j] == false) *sub1 = j;
		if (visited[result - *sub1] == false) {
			*sub2 = result - *sub1;
			return true;
		}
	}
	return false;
}

int main(void) {
	int num, sub1=0, sub2=0, result;
	Eratosthenes(1000000);
	for (int i = 1; i <= 100000; i++) {
		scanf("%d", &num);

		if (num == 0) return 0;
		result=Goldbach(&sub1, &sub2, num);
		if (result == true) printf("%d = %d + %d\n", num, sub1, sub2);
		else printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}