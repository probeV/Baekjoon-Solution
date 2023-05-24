#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = 0;
char arr[1001], stack[1001];

int main(void)
{
	int t;
	scanf("%d ", &t);
	for (int i = 0; i < t; i++) //반복문 실행
	{
		fgets(arr, 1001, stdin); //문장입력받기
		for (int i = 0; i < strlen(arr) - 1; i++)
		{
			if (arr[i] != ' ')
			{
				stack[top++] = arr[i];
			}

			if (arr[i] == ' ' || i == strlen(arr) - 2)
			{
				for (int i = top - 1; i >= 0; i--)
					printf("%c", stack[i]);
				printf(" ");
				top = 0;
			}
		}
		printf("\n");
	}
	return 0;
}