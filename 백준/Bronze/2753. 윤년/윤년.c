#include <stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d", &a);

	b = a % 4;

	if (b == 0)
	{
		c = a % 100;
		d = a % 400;

		if (c != 0)
		{
			printf("1");
		}

		else if (d == 0)
		{
			printf("1");
		}

		else
		{
			printf("0");
		}
	}

	else
	{
		printf("0");
	}

	return 0;
}