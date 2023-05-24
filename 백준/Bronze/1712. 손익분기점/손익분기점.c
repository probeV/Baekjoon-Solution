#include <stdio.h>

int main()
{
	int A, B, C, num=0;
	scanf("%d %d %d", &A, &B, &C);
	if(B>=C)
	{
		printf("-1");
		return 0;
	}
	num = A / (C - B) + 1;
	printf("%d", num);
}