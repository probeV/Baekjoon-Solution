#include <stdio.h>
#include <string.h>

int main(void) {
	char string[200];
	fgets(string, 200, stdin);
	string[strlen(string) - 1] = '\0';
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] >= 65 && string[i] <= 90) {
			if (string[i] + 13 <= 90) string[i] += 13;
			else if (string[i] - 13 >= 65) string[i] -= 13;
		}
		else if (string[i] >= 97 && string[i] <= 122) {
			if (string[i] + 13 <= 122) string[i] += 13;
			else if (string[i] - 13 >= 97) string[i] -= 13;
		}
	}
	printf("%s", string);
	return 0;
}