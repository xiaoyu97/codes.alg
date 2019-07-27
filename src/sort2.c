/*
	选择排序
*/
#include <stdio.h>

#define NUMBER 9

void print(int *p, int n, int i)
{
	printf("%d:  ", i);
	for (int j = 0; j < n; j++) {
		printf("%d  ", p[j]);
	}
	printf("\n");
}

void swap(int *p, int a, int b) {
	int temp = p[a];
	p[a] = p[b];
	p[b] = temp;
}

void selectSort(int *p, int n)
{
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		int j = i + 1;
		while (j < n) {
			if (p[j] < p[min])
				min = j;
			j++;
		}
		if (min != i) {
			swap(p, i, min);
		}
		print(p, n, i + 1);
	}
}



int main(void)
{
	int a[NUMBER] = {3, 1, 7, 5, 2, 4, 9, 6, 8};
	print(a, NUMBER, 0);
	selectSort(a, NUMBER);
	return 0;
}