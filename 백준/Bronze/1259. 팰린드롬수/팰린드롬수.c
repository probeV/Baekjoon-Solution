#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

int main() {
	char num[6];
	int end, start;
	while (1) {
		scanf("%s", &num);
		if (num[0] == '0') return 0;
		if (strlen(num) == 1) printf("yes\n");
		else {
			end = strlen(num)-1;
			start = 0;
			while (start != end && start + 1 != end && num[start] == num[end]) {
				start++;
				end--;
			}
			if (start == end) {
				printf("yes\n");
			}
			else if (start + 1 == end) {
				if(num[start]==num[end]) printf("yes\n");\
				else printf("no\n");
			}
			else printf("no\n");
		}
	}
	return 0;
}