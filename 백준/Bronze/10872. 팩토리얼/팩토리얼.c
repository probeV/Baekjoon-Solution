#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int factorial(int num) {
	if (num == 0) return 1;
	return num * factorial(num - 1);
}

int main(void) {
	int num;
	scanf("%d", &num);
	printf("%d", factorial(num));
	return 0;
}