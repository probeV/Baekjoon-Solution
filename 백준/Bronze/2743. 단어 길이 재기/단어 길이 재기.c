#include <stdio.h>


int main(void) {
	char string[101];
	scanf("%s", string);
	int i = 0;
	for (; string[i] != '\0'; i++);
	printf("%d", i);
	return 0;
}