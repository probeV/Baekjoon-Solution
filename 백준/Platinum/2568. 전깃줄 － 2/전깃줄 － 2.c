#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100000
#define INF 210000000

int result[SIZE+1];
int Pos[SIZE + 1]; 
int LIS[SIZE + 1];
int arr[SIZE + 1][2];

void quickSort(int L, int R) {
      int left = L, right = R;
      int pivot = arr[(L + R) / 2][0];    
      int temp1; int temp2;
      do
      {
        while (arr[left][0] < pivot)    
            left++;
        while (arr[right][0] > pivot)   
            right--;
        if (left<= right)   
        {
            temp1 = arr[left][0];
            temp2 = arr[left][1];
            arr[left][0] = arr[right][0];
            arr[left][1] = arr[right][1];
            arr[right][0] = temp1;
            arr[right][1] = temp2;
            
            left++;
            right--;
        }
      } while (left<= right);    
 
   
    if (L < right)
        quickSort(L, right);    
 
    if (left < R)
        quickSort(left, R);     
}

int BinarySearch(int target, int size)
{
	int mid, start, end;
	start = 1, end = size;

	while (end > start) // end가 start보다 같거나 작아지면, 그 값이 Upper Bound이므로 반복을 종료한다.
	{
		mid = (start + end) / 2; 
		if (LIS[mid] > target) // 중간값이 원하는 값보다 클 경우, 끝값을 중간값으로 설정하여 다시 탐색한다.
			end = mid;
		else start = mid + 1; // 중간값이 원하는 값보다 작거나 같을 경우, 시작값을 중간값+1로 설정하여 다시 탐색한다.
	}
	return end;
}

int main(void) {
	int N; int Max=0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);

	quickSort(1, N);
		
	for(int i=0;i<=N;i++)
		LIS[i]=INF;
		
	for(int i=1;i<=N;i++){
			
		int j=BinarySearch(arr[i][1], N);
			
		LIS[j]=arr[i][1];
		Pos[i]=j;
		Max = Max > j ? Max : j;
	}
	
	int count=0;
	for(int i=N;i>=1;i--){
		if (Pos[i]==Max)
			Max--;
		else
			result[count++]=arr[i][0];
	}
	
	printf("%d\n", count);
	for(;count>=1;count--)
		printf("%d\n", result[count-1]);
	
	return 0;
}