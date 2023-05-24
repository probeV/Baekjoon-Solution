#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX_SIZE 1000000
#define false 0

int resultarray[MAX_SIZE + 1] = { false, };

int makeone(int num, int result) {
	if (resultarray[num] == false && num != 1) {
		if (num % 3 == 0 && num % 2 == 0) {
			if (resultarray[num / 3] < resultarray[num / 2]) {
				result++;
				resultarray[num] = result + makeone(num / 3, result);
				return  resultarray[num];
			}
			else {
				result++;
				resultarray[num] = result + makeone(num / 2, result);
				return  resultarray[num];
			}
		}
		else if (num % 3 == 0) {
			if (resultarray[num - 1] < resultarray[num / 3]) {
				result++;
				resultarray[num] = result + makeone(num - 1, result);
				return  resultarray[num];
			}
			else {
				result++;
				resultarray[num] = result + makeone(num / 3, result);
				return  resultarray[num];
			}
		}
		else if (num % 2 == 0) {
			if (resultarray[num - 1] < resultarray[num / 2]) {
				result++;
				resultarray[num] = result + makeone(num - 1, result);
				return  resultarray[num];
			}
			else {
				result++;
				resultarray[num] = result + makeone(num / 2, result);
				return  resultarray[num];
			}
		}
		else {
			result++;
			resultarray[num] = result + makeone(num - 1, result);
			return  resultarray[num];
		}
	}
	return resultarray[num];
}

int main(void) {
	int num, result;
	scanf("%d", &num);
	resultarray[1]=0;
	for (int i = 2; i <= num; i++) {
		result = 0;
		if (resultarray[i] == false) {
			makeone(i, result);
		}
	}
	printf("%d", resultarray[num]);
	return 0;
}