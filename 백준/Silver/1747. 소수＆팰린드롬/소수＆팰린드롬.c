#include <stdio.h>
#define true 1
#define false 0
int Calc(int num) 
{
	int result=1;
	for (int i = 0;i<=num; i++) {
		result = result * 10;
	}
	return result;
}
int DecimalFunc(int num) 
{
	if (num == 1) return false;
	for (int i = 2; i < num; i++) {
		if ((num) % i == 0) {
			return false;
		}
	}
	return num;
}
int PenilFunc(int* arr, int indexnum) 
{
	if ((indexnum + 1) % 2 == 0)
	{
		for (int i =1; ((indexnum + 1) / 2) - i >= 0; i++)
		{
			if (arr[((indexnum + 1) / 2) - i] != arr[((indexnum + 1) / 2) + i - 1])
			{
				return false;
			}
			if (((indexnum + 1) / 2) - i == 0)
			{
				return true;
			}
		}
	}
	else
	{
		for (int i =1; ((indexnum + 1) / 2) - i >= 0; i++)
		{
			if (arr[((indexnum + 1) / 2) - i] != arr[((indexnum + 1) / 2) + i])
			{
				return false;
			}
			if (((indexnum + 1) / 2) - i == 0)
			{
				return true;
			}
		}
	}
}

int main() {
	int subnum, scannum, decimalnum, penilnum, endnum=0;
	scanf("%d", &scannum);
	if (scannum < 1 || scannum>1000000) return 0;
	int i=0;
	while (true) {
		if (scannum > 9) {
			subnum = scannum + i;
			i++;
			penilnum = subnum;
			int arr[7] = { 0,0,0,0,0,0,0 };
			int k = 0;
			while (true) {
				arr[k] = (subnum % Calc(k)) / (Calc(k) / 10);
				subnum = subnum - arr[k];
				if (penilnum / Calc(k) == 0) break;
				k++;
			}
			endnum = PenilFunc(arr, k);
			if (endnum == false) continue;
			else if (endnum == true) {
				decimalnum = DecimalFunc(penilnum);
				if (decimalnum == false) continue;
				else printf("%d", decimalnum);
			}
		}
		else {
			while (true) {
				endnum = DecimalFunc(scannum + i);
				i++;
				if(endnum!=false){
					printf("%d", endnum);
					break;
				}
			}
		}
		return 0;
	}
}

