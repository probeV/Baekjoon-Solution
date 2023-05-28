#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char** stringarray, int j, int k) {
	char* temp;
	temp = stringarray[j];
	stringarray[j] = stringarray[j + 1];
	stringarray[j + 1] = temp;
}

int main(void) {
	char string[1001], temp[1001];
	scanf("%s", string);
	int len = strlen(string);
	char** stringarray = (char**)malloc(sizeof(char*) * len);
	for (int i = 0; i < len; i++) {
		stringarray[i] = (char*)malloc(sizeof(char) * 1001);
	}


	for (int i = 0;i<len; i++) {
		for (int j = 0; j <= len; j++) {
			temp[j] = string[j + i];
		}
		strcpy(stringarray[i], temp);
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			int k = 0;
			for (;(stringarray[j][k] == stringarray[j + 1][k]); k++);
			if (stringarray[j][k] > stringarray[j + 1][k]) swap(stringarray, j, k);
		}
	}

	for (int i = 0; i < len; i++) {
		printf("%s\n", stringarray[i]);
	}
	return 0;
}