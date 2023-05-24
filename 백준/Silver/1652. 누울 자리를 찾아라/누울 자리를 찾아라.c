#include <stdio.h>

int main(void) {
	int roomsize, horiznum = 0, lengthnum = 0;
	char arr[100][100];
	scanf("%d", &roomsize);
	for (int i = 0; i < roomsize; i++) {
		scanf("%s", arr[i]);
	}
	for (int j = 0; j < roomsize; j++) {
		int emptynum = 0;
		for (int i = 0; i < roomsize; i++) {
			if (arr[j][i] == 'X') {
				if (emptynum >= 2) horiznum++;
				emptynum = 0;
			}
			else if (arr[j][i] == '.') {
				emptynum++;
			}
		}
		if (emptynum >= 2) horiznum++;
	}
	for (int j = 0; j < roomsize; j++) {
		int emptynum = 0;
		for (int i = 0; i < roomsize; i++) {
			if (arr[i][j] == 'X') {
				if (emptynum >= 2) lengthnum++;
				emptynum = 0;
			}
			else if (arr[i][j] == '.') {
				emptynum++;
			}
		}
		if (emptynum >= 2) lengthnum++;
	}
	printf("%d %d", horiznum, lengthnum);
	return 0;
}