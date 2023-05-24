#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
int top=-1;
int stack[100000];

int main(void) {
	int MAX, num, index=0, start=1;
	char result[200000];
	scanf("%d", &MAX);
	int* sequence = (int*)malloc(sizeof(int) * MAX);
	for (int i = 0; i < MAX; i++) {
		scanf("%d", &sequence[i]);
	}
	for (int i = 0; i < MAX ; i++) {
		for (int j = start; j <= sequence[i]; j++) {
			stack[++top] = j;
			result[index++] = '+';
			start = sequence[i]+1;
		}
		if (stack[top] == sequence[i]) {
			top--;
			result[index++] = '-';
		}
		else if (stack[top] > sequence[i]) {
			break;
		}
	}
	if (top!=-1) {
		printf("NO");
		return 0;
	}
	for (int i = 0; i < index; i++) {
		printf("%c\n", result[i]);
	}
	return 0;
}

