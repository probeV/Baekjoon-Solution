#include <stdio.h>

int main()
{
	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);

	if (x > 0)
	{
		if (y > 0)
		{
			printf("1");
		}
		else
		{
			printf("4");
		}

	}
	if (x < 0)
	{
		if (y > 0)
		{
			printf("2");
		}
		else
		{
			printf("3");
		}

	}

}