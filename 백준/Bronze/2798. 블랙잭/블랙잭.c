#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void) {
	int cardnum, targetresult, point1 = 0, point2, point3, result=0, subresult;
	scanf("%d %d", &cardnum, &targetresult);
	int cardarray[100];
	for (int i = 0; i < cardnum; i++) {
		scanf("%d", &cardarray[i]);
	}
	while (point1 <= cardnum - 3) {
		point2 = point1 + 1;
		while (point2 <= cardnum - 2) {
			point3 = point2 + 1;
			while (point3 <= cardnum - 1) {
				subresult = cardarray[point1] + cardarray[point2] + cardarray[point3];
				if (abs(targetresult - subresult) < abs(targetresult - result) && targetresult > subresult) result = subresult;
				else if (targetresult == subresult) {
					printf("%d", subresult);
					return 0;
				}
				point3++;
			}
			point2++;
		}
		point1++;
	}
	printf("%d", result);
	return 0;
}