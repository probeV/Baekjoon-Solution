#include <stdio.h>
#define true 1
#define false 0

int main(void) {
	int num, temp1, temp2, temp3, result = -1, i = 1;
	scanf("%d", &num);
	temp1 = num;
	for (; result != num; i++) {
		temp3 = temp1;
		if (temp1 < 10) {
			temp1 = temp1 * 10;
		}
		temp2 = (temp1 / 10) + (temp1 % 10);
		result = (temp3 % 10) * 10 + temp2 % 10;
		temp1 = result;
	}
	printf("%d", i-1);
	return 0;
}