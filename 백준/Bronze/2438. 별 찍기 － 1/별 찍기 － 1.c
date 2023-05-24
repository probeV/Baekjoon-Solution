#include <stdio.h>
int main()
{
	int a, b;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		for (int c = i; c >= 0; c--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}