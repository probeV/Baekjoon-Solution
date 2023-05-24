#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	int pick1, pick2, total;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	
	if (d < e)
	{
		pick2 = d;
		if (a < b)
			{
				if (b < c)
				{
					pick1 = a;
				}
				else //b>c
				{
					if (a < c)
					{
						pick1 = a;
					}
					else
					{
						pick1 = c;
					}
				}
			}
			else//a>b
			{
				if (b > c)
				{
					pick1 = c;
				}
				else //b<c
				{
					pick1 = b;
				}

			}
		}
	else
	{
		pick2 = e;
		if (a < b)
		{
				if (b < c)
				{
					pick1 = a;
				}
				else //b>c
				{
					if (a < c)
					{
						pick1 = a;
					}
					else
					{
						pick1 = c;
					}
				}
		}
		else//a>b
		{
			if (b > c)
			{
				pick1 = c;
			}
			else //b<c
			{
				pick1 = b;
			}

		}
	}

	total = pick1 + pick2 - 50;
	printf("%d", total);
	return 0;
}