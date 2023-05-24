#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int treenum, length, MAX = 0, MIN = 0, cutlength=0;
	long long result;
	scanf("%d %d", &treenum, &length);
	int* treelength = (int*)malloc(sizeof(int)*treenum);
	for (int i = 0; i < treenum; i++) {
		scanf("%d", &treelength[i]);
		if (MAX < treelength[i]) MAX = treelength[i];
	}
	while (1) {
		if (MAX - 1 == MIN&&result>=length) {
			printf("%d", cutlength);
			break;
		}
		else if (MAX - 1 == MIN && result < length) {
			printf("%d", cutlength - 1);
			break;
		}
		result = 0;
		cutlength = (MAX + MIN) / 2;
		for (int i = 0; i < treenum; i++) {
			if (treelength[i] > cutlength) {
				result = result + treelength[i] - cutlength;
			}
		}
		if (result < length) {
			MAX = cutlength;
		}
		else if (result > length) {
			MIN = cutlength;
		}
		else if (result == length) {
			printf("%d", cutlength);
			break;
		}
	}
	return 0;
}