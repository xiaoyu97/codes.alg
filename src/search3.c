/*
	二分查找
*/
#include <stdio.h>
#include <stdlib.h>
#define FAILED -1
#define LENGTH 11

typedef struct table {
	int *p;
	int length;
} Table;

Table createTable(int length)
{
	Table table;
	table.p = (int *)malloc(length * sizeof(int));
	table.length = 0;
	for (int i = 0; i < length; i++)
	{
		table.p[i] = i + 1;
		table.length++;
	}
	return table;
}

void displayTable(Table table) {
	for (int i = 0; i < table.length; i++)
	{
		printf("%d  ", table.p[i]);
	}
	printf("\n");
}

int search(Table table, int key)
{
	int low = 0;
	int high = table.length - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (table.p[mid] == key)
			return mid;
		else {
			if (table.p[mid] > key)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return FAILED;
}

int main(void)
{
	int key;

	Table table = createTable(LENGTH);
	printf("数组元素：\n");
	displayTable(table);

	printf("请输入要查找的关键字：\n");
	scanf("%d", &key);

	int idx = search(table, key);
	if (idx == FAILED)
		puts("查找失败！");
	else
		printf("查找的关键字%d在第%d个\n", key, idx + 1);
	
	return 0;
}