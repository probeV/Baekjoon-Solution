#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0

int arr[501][501];

int case1(int N, int M) {
	int MAX = 0, temp;
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i + 3 <= M; i++) {
			temp = arr[j][i + 3] + arr[j][i + 2] + arr[j][i + 1] + arr[j][i];
			if (temp > MAX) MAX = temp;
		}
	}
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i + 3 <= N; i++) {
			temp = arr[i + 3][j] + arr[i + 2][j] + arr[i + 1][j] + arr[i][j];
			if (temp > MAX) MAX = temp;
		}
	}
	return MAX;
}

int case2(int N, int M) {
	int MAX = 0, temp;
	for (int j = 1; j+1 <= N; j++) {
		for (int i = 1; i+1 <= M; i++) {
			temp = arr[j][i] + arr[j][i + 1] + arr[j + 1][i] + arr[j + 1][i + 1];
			if (temp > MAX) MAX = temp;
		}
	}
	return  MAX;
}

int case3(int N, int M) {
	int MAX = 0, temp;
	for (int j = 1; j+2 <= N; j++) {
		for (int i = 1; i+1 <= M; i++) {
			temp = arr[j][i] + arr[j+1][i] + arr[j+2][i] + arr[j+2][i+1];
			if (temp > MAX) MAX = temp;
			temp = arr[j][i] + arr[j+1][i] + arr[j+2][i] + arr[j][i+1];
			if (temp > MAX) MAX = temp;
			temp = arr[j][i] + arr[j][i+1] + arr[j+1][i+1] + arr[j+2][i+1];
			if (temp > MAX) MAX = temp;
			temp = arr[j+2][i] + arr[j][i+1] + arr[j+1][i+1] + arr[j+2][i+1];
			if (temp > MAX) MAX = temp;
		}
	}
	for (int j = 1; j + 1 <= N; j++) {
		for (int i = 1; i + 2 <= M; i++) {
			temp = arr[j][i] + arr[j][i+1] + arr[j][i+2] + arr[j+1][i+2];
			if (temp > MAX) MAX = temp;
			temp = arr[j+1][i] + arr[j+1][i+1] + arr[j+1][i+2] + arr[j][i+2];
			if (temp > MAX) MAX = temp;
			temp = arr[j][i] + arr[j+1][i] + arr[j][i+1] + arr[j][i+2];
			if (temp > MAX) MAX = temp;
			temp = arr[j][i] + arr[j+1][i] + arr[j+1][i+1] + arr[j+1][i+2];
			if (temp > MAX) MAX = temp;
		}
	}
	return MAX;
}

int case4(int N, int M) {
	int MAX = 0, temp;
	for (int j = 1; j+2 <= N; j++) {
		for (int i = 1; i+1 <= M; i++) {
			temp = arr[j][i] + arr[j+1][i] + arr[j+1][i+1] + arr[j+2][i+1];
			if (temp > MAX) MAX = temp;
			temp = arr[j][i+1] + arr[j+1][i] + arr[j+1][i+1] + arr[j+2][i];
			if (temp > MAX) MAX = temp;
		}
	}
	for (int j = 1; j + 1 <= N; j++) {
		for (int i = 1; i + 2 <= M; i++) {
			temp = arr[j][i] + arr[j][i+1] + arr[j+1][i+1] + arr[j+1][i+2];
			if (temp > MAX) MAX = temp;
			temp = arr[j+1][i] + arr[j][i+1] + arr[j+1][i+1] + arr[j][i+2];
			if (temp > MAX) MAX = temp;
		}
	}
	return MAX;
}

int case5(int N, int M) {
	int MAX = 0, temp;
	for (int j = 1; j+1 <= N; j++) {
		for (int i = 1; i+2 <= M; i++) {
			temp = arr[j+1][i] + arr[j+1][i+1] + arr[j+1][i+2] + arr[j][i+1];
			if (temp > MAX) MAX = temp;
			temp = arr[j][i] + arr[j][i+1] + arr[j][i+2] + arr[j+1][i+1];
			if (temp > MAX) MAX = temp;
		}
	}
	for (int j = 1; j+2 <= N; j++) {
		for (int i = 1; i+1 <= M; i++) {
			temp = arr[j][i+1] + arr[j+1][i+1] + arr[j+2][i+1] + arr[j+1][i];
			if (temp > MAX) MAX = temp;
			temp = arr[j][i] + arr[j+1][i] + arr[j+2][i] + arr[j+1][i+1];
			if (temp > MAX) MAX = temp;
		}
	}
	return MAX;
}

int main(void) {
	int N, M, result;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int temp1 = (case1(N, M) > case2(N, M)) ? case1(N, M) : case2(N, M);
	int temp2 = (case3(N, M) > case4(N, M)) ? case3(N, M) : case4(N, M);
	result = (temp1 > temp2 ? temp1 : temp2) < case5(N, M) ? case5(N, M) : (temp1 > temp2 ? temp1 : temp2);
	printf("%d", result);
	return 0;
}