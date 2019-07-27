/*
	插入排序
*/
#include <stdio.h>
#define NUMBER 9

void print(int a[], int n, int i)
{
	printf("%d:  ", i);
	for (int j = 0; j < n; j++) {
		printf("%d  ", a[j]);
	}
	printf("\n");
}

void insertSort(int a[], int n)
{
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int temp = a[i];
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
		print(a, n, i);
	}
}

int main(void)
{
	int a[NUMBER] = {3, 1, 7, 5, 2, 4, 9, 6, 8};
	print(a, NUMBER, 0);
	insertSort(a, NUMBER);
	return 0;
}