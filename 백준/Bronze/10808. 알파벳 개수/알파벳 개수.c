#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
	char S[101];
	int numarray[26]={0,};
	fgets(S, 101, stdin);
	S[strlen(S) - 1] == '\0';
	for (int i = 0; i < strlen(S); i++) {
		numarray[S[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", numarray[i]);
	}
	return 0;
}