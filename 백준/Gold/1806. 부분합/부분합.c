#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

int main(void) {
	int num, sumresult, startindex, endindex, result, len = 1000000;
	scanf("%d %d", &num, &sumresult);
	int* sequence = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &sequence[i]);
	}
	startindex = 0;
	endindex = 0;
	result = sequence[0];
	while (startindex != num) {
		if ((result >= sumresult && startindex != endindex) || endindex == num - 1) {
			if (len > endindex - startindex + 1 && (endindex != num - 1 || result >= sumresult)) {
				len = endindex - startindex + 1;
			}
			if (startindex < num) result = result - sequence[startindex++];
		}
		else if (result < sumresult) {
			result = result + sequence[++endindex];
		}
		else if (result >= sumresult && startindex == endindex) {
			if (len > endindex - startindex + 1 && endindex != num - 1) {
				len = endindex - startindex + 1;
			}
			if (startindex < num) result = result + sequence[++endindex];
		}
	}
	if (len == 1000000) {
		printf("0");
		return 0;
	}
	printf("%d", len);
	return 0;
}