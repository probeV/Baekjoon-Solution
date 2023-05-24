#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0

int main(void) {
	int back, front, frontindex, backindex, len;
	int testcase, num;
	char command[400001];
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		int array[100001], error=false;
		scanf("%s", command);
		scanf("%d", &num);
		getchar();
		scanf("[%d,", &array[1]);
		for (int j = 2; j < num; j++) {
			scanf("%d,", &array[j]);
		}
		scanf("%d]", &array[num]);
		getchar();
		front = true;
		back = false;
		frontindex = 1;
		backindex = num;
		len = strlen(command);
		for (int j = 0; j < len && error == false; j++) {
			switch (command[j]){
			case 'R':
				if (front == true) {
					front = false;
					back = true;
				}
				else if (back == true) {
					front = true;
					back = false;
				}
				break;
			case 'D':
				if (backindex < frontindex) {
					printf("error\n");
					error = true;
				}
				else if (front == true) {
					frontindex++;
				}
				else if (back == true) {
					backindex--;
				}
				break;
			}
		}
		if (error == true) continue;
		if (backindex >= frontindex) {
			if (backindex == frontindex) {
				printf("[%d]\n", array[frontindex]);
			}
			else if (front == true) {
				printf("[%d,", array[frontindex]);
				for (int i = frontindex + 1; i < backindex; i++) {
					printf("%d,", array[i]);
				}
				printf("%d]\n", array[backindex]);
			}
			else if (back == true) {
				printf("[%d,", array[backindex]);
				for (int i = backindex - 1; i > frontindex; i--) {
					printf("%d,", array[i]);
				}
				printf("%d]\n", array[frontindex]);
			}
		}
		else {
			printf("[]\n");
		}
	}
	return 0;
}