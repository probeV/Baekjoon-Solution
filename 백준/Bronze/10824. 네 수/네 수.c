#include <stdio.h>
#include <string.h>

int main(void) {
	long long a, b, c, d, i = 1, j = 1;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	while (b / i != 0) i = i * 10;
	while (d / j != 0) j = j * 10;
	a = a * i + b;
	c = c * j + d;
	printf("%lld", a + c);
	return 0;
}