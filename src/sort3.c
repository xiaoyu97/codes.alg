/*
	冒泡排序
*/
#include <stdio.h>

#define NUMBER 9

void print(int *p, int n, int i, int j)
{
	printf("第%d次起泡 %d:  ", i + 1, j + 1);
	for (int j = 0; j < n; j++) {
		printf("%d  ", p[j]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j + 1 < n - i; j++) {
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
			print(a, n, i, j);
		}
	}
}

int main(void)
{
	int a[NUMBER] = {3, 1, 7, 5, 2, 4, 9, 6, 8};
	printf("初始数组：");
	for (int j = 0; j < NUMBER; j++) {
		printf("%d  ", a[j]);
	}
	printf("\n");
	
	bubbleSort(a, NUMBER);
	return 0;
}