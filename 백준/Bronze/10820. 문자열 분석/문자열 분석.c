#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char string[101];
	for (int n = 0;n<100;n++) {
		int Sletter = 0, Lletter = 0, Number = 0, Blank = 0;
		int ch=getchar();
		while (ch != '\n') {
			if (ch == EOF) return 0;
			else if (ch >= 97 && ch <= 122) { //소문자
				Sletter++;
			}
			else if (ch >= 65 && ch <= 90) { //대문자
				Lletter++;
			}
			else if (ch >= 48 && ch <= 57) { //숫자
				Number++;
			}
			else Blank++;
			ch = getchar();
		}
		printf("%d %d %d %d\n", Sletter, Lletter, Number, Blank);
	}
	return 0;
}
