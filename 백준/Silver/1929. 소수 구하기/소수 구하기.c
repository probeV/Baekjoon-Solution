#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

int visited[1000001] = { 0, };

void Eratosthenes(int N) {
	for (int i = 2; i <= N; i++) {
		if (visited[i] == true) continue;
		for (int j = 2; j * i <= N; j++) {
			visited[i * j] = true;
		}
	}
}

int main(void) {
	int M, N;
	scanf("%d %d", &M, &N);
	Eratosthenes(N);
	for (int i = M; i <= N; i++) {
		if (i != 1 && visited[i] == false) printf("%d\n", i);
	}
	return 0;
}