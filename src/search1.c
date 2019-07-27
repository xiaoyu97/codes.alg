/*
	顺序查找
*/
#include <stdio.h>

#define NUMBER 5
#define FAILED -1

int search(int v[], int key, int n)
{
	for (int i = 0; i < n; i++) {
		if (v[i] == key)
			return i;
	}
	return FAILED;
}

int main(void)
{
	int ky, idx;
	int vx[NUMBER];

	for (int i = 0; i < NUMBER; i++) {
		printf("vx[%d]:", i);
		scanf("%d", &vx[i]);
	}

	printf("要查找的值：");
	scanf("%d", &ky);

	idx = search(vx, ky, NUMBER);

	if (idx == FAILED)
		puts("查找失败，数组中无此值！");
	else
		printf("%d是数组的第%d号元素\n", ky, idx + 1);

	return 0;
}