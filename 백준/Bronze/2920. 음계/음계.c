#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0

int main(void) {
	int array[9], mixed=false, ascending=false, descending=false;
	for (int i = 1; i <= 8; i++) {
		scanf("%d", &array[i]);
		if (i == 1) {
			if (array[1] == 1) {
				ascending = true;
			}
			else if (array[1] == 8) {
				descending = true;
			}
			else {
				mixed = true;
			}
		}
		if (ascending &&i >= 2 && array[i - 1] + 1 != array[i]) {
			ascending = false;
			mixed = true;
		}
		if (descending && i >= 2 && array[i - 1] - 1 != array[i]) {
			descending = false;
			mixed = true;
		}
	}

	if (ascending) {
		printf("ascending");
	}
	else if (descending) {
		printf("descending");
	}
	else if (mixed) {
		printf("mixed");
	}
	return 0;
}
