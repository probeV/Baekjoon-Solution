#include <stdio.h>
int main()
{
	int a, b, c;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		for (b = a - i - 1; b > 0; b--)
		{
			printf(" ");
		}

		for (c = i + 1; c > 0; c--)
		{
			printf("*");
		}

		printf("\n");
	}
	return 0;
}