#include <stdio.h>
int main()
{
	int a, b, c, d=1;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d %d", &b, &c);
		printf("Case #%d: %d\n", d, b + c);
		d++;
	}
	return 0;
}