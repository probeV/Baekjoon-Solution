#include <stdio.h>
#include<math.h>

void hanoi(int start, int end, int num) {
	if (num == 1) {   //start에서 하나 남았을 때 end로 이동
		printf("%d %d\n", start, end);
		return;
	}
	hanoi(start, 6 - start - end, num - 1);   //6-start-end는 경유지, start에서 경유지로 맨 밑에 꺼 뺴고 모두 이동 이것을 재귀로 반복해서 num이 1 일 때까지
	printf("%d %d\n", start, end);
	hanoi(6 - start - end, end, num - 1);   //맨 밑에꺼 목적지로 이동시키고 나머지 경유지를 start로 재시작

}

int main() {
	int num;
	scanf("%d", &num);
	printf("%d\n", (int)(pow(2, num) - 1));
	hanoi(1, 3, num);
	return 0;
}
