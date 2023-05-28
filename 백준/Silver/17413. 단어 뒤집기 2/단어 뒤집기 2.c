#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[100002], arr[100002];
int top = -1;

int main(void) {
	fgets(arr, 100002, stdin);
	for (int i = 0; i < strlen(arr) - 1; i++){
		if (arr[i] != ' ' && arr[i] != '<') {
			stack[++top] = arr[i];
		}

		if (arr[i] == '<') {
			if (top != -1) {
				for (; top != -1; top--)
					printf("%c", stack[top]);
			}
			for (; arr[i] != '>'; i++) {
				printf("%c", arr[i]);
			}
			printf("%c", arr[i]);
		}
		else if (arr[i] == ' ') {
			for (; top != -1; top--)
				printf("%c", stack[top]);
			printf(" ");
		}
		else if (i == strlen(arr) - 2) {
			for (; top != -1; top--)
				printf("%c", stack[top]);
		}
	}
	return 0;
}
