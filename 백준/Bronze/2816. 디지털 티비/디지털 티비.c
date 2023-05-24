#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int num, len, kbs1index, kbs2index;
	char* arr[100];
	char chartemp[100];
	char* temp;
	scanf("%d", &num);
	if (num < 1 || num>100) {
		return 0;
	}
	for (int i = 0; i < num; i++) {
		scanf("%s", &chartemp);
		len= strlen(chartemp) + 1;
		arr[i] = (char*)malloc(sizeof(char) * len);
		strcpy(arr[i], chartemp);
	}
	for (int i = 0; i < num; i++) {
		if (!strcmp(arr[i], "KBS1")) kbs1index = i;
		if (!strcmp(arr[i], "KBS2")) kbs2index = i;
	}
	if (kbs1index > kbs2index) {
		for (int i = 0; i < kbs1index; i++) {
			printf("1");
		}
		for (int i = 0; i < kbs1index; i++) {
			printf("4");
		}
		kbs2index++;
		for (int i = 0; i < kbs2index; i++) {
			printf("1");
		}
		for (int i = 0; i < kbs2index - 1; i++) {
			printf("4");
		}
	}
	else {
		for (int i = 0; i < kbs1index; i++) {
			printf("1");
		}
		for (int i = 0; i < kbs1index; i++) {
			printf("4");
		}
		for (int i = 0; i < kbs2index; i++) {
			printf("1");
		}
		for (int i = 0; i < kbs2index - 1; i++) {
			printf("4");
		}
	}
	return 0;
}