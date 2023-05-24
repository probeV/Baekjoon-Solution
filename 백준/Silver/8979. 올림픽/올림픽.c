#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
	int num, x, rank = 0;
	scanf("%d %d", &num, &x);
	int medal[1000][4];
	int visited[1000] = { 0, };
	for (int i = 0; i < num; i++) {
		scanf("%d %d %d %d", &medal[i][0], &medal[i][1], &medal[i][2], &medal[i][3]);
	}
	int z = 0;
	while (medal[z][0] != x) z++;
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < num; j++) {
			if (medal[j][i] > medal[z][i] && visited[j]==0) {
				rank++;
				visited[j] = 1;
			}
			else if (medal[j][i] < medal[z][i]&&visited[j]==0) {
				visited[j] = 1;
			}
		}
	}
	printf("%d", rank+1);
	return 0;
}