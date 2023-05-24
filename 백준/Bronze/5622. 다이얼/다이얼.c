#include <stdio.h>
#include <string.h>

int dial(int n);

int main(void) {
	
	char ab[15];
	int T=0;
	
	gets(ab);
	
	for(int i='A'; i<='Z'; i++) {
		for(int j=0; j<strlen(ab); j++) {
			if( ab[j] == i ) T += dial(i);
		}
	}
	
	T += strlen(ab);
	
	printf("%d", T);
	
}

int dial(int n) {
	switch(n) {
		case 'A' :
		case 'B' :
		case 'C' :
			return 2;
		case 'D' :
		case 'E' :
		case 'F' :
			return 3;
		case 'G' :
		case 'H' :
		case 'I' :
			return 4;
		case 'J' :
		case 'K' :
		case 'L' :
			return 5;
		case 'M' :
		case 'N' :
		case 'O' :
			return 6;
		case 'P' :
		case 'Q' :
		case 'R' :
		case 'S' :
			return 7;
		case 'T' :
		case 'U' :
		case 'V' :
			return 8;
		case 'W' :
		case 'X' :
		case 'Y' :
		case 'Z' :
			return 9;
	}
	
}