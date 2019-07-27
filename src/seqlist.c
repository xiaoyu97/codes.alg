/*
    顺序表
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define ADDNUM 9
#define ADDPOS 3
#define DELPOS 3
#define SEARCHNUM 4
#define MODIFYNUM 27

typedef struct {
    int *head;       //顺序表指针变量
    int length;      //记录当前顺序表的长度
    int capacity;    //记录顺序表分配的存储容量

} SeqList;

/*初始化顺序表*/
SeqList initSeqList() {
    SeqList list;
    list.head = (int *)malloc(SIZE * sizeof(int));

    if (!list.head) {
        printf("初始化失败！\n");
        exit(0);
    }

    list.length = 0;
    list.capacity = SIZE;
    return list;
}

/*显示顺序表*/
void displayList(SeqList list) {
    for (int i = 0; i < list.length; i++) {
        printf("%d  ", list.head[i]);
    }

    printf("\n");
}

/*增*/
SeqList add(SeqList list, int elem, int pos) {
    //插入位置判断，取值范围为0～length
    if (pos > list.length  || pos < 0) {
        printf("插入位置有误\n");
        return list;
    }

    //重新分配内存
    if (list.length == list.capacity) {
        int *temp = (int *)realloc(list.head, (list.capacity + 1) * sizeof(int));

        if (!temp) {
            printf("内存分配失败！\n");
            return list;
        }

        list.head = temp;
        list.capacity += 1;
    }

    //插入位置及以后的元素依次后移一位
    for (int i = list.length - 1; i >= pos ; i--) {
        list.head[i + 1] = list.head[i];
    }

    list.head[pos] = elem;//元素插入空出的位置

    list.length++;//表长度+1
    return list;
}

/*删*/
SeqList delete(SeqList list , int pos) {
    //删除位置判断，取值范围为0～length-1
    if (pos >= list.length || pos < 0) {
        printf("删除位置有误\n");
        return list;
    }

    //将删除位置后续元素依次前移
    for (int i = pos ; i < list.length - 1 ; i++) {
        list.head[i] = list.head[i + 1];
    }

    list.length--;//表长度-1

    return list;
}

/*查*/
int search(SeqList list , int elem) {
    //顺序查找
    for (int i = 0; i < list.length; i++) {
        if (list.head[i] == elem) {
            return i ;
        }
    }

    return -1;
}

/*改*/
SeqList modify(SeqList list , int elem, int val) {
    int pos = search(list, elem);
    
    list.head[pos] = val;
    return list;
}

int main(void) {
    SeqList list = initSeqList();

    for (int i = 0; i < SIZE; i++) {
        list.head[i] = i + 1;
        list.length++;
    }

    printf("顺序表中存储的元素分别是：\n");
    displayList(list);

    printf("在顺序表的第%d个位置插入元素：%d\n", ADDPOS, ADDNUM);
    list = add(list, ADDNUM, ADDPOS);
    displayList(list);

    printf("删除第%d个元素\n", DELPOS);
    list = delete(list, DELPOS);
    displayList(list);

    printf("查找元素为%d的位置\n", SEARCHNUM);
    int pos = search(list, SEARCHNUM);
    printf("元素%d的位置为第%d个\n", SEARCHNUM, pos);

    printf("将%d修改为%d\n", SEARCHNUM, MODIFYNUM);
    list = modify(list, SEARCHNUM, MODIFYNUM);
    displayList(list);

    printf("内存空间为%d  数组长度为%d\n", list.capacity, list.length);

    free(list.head);
    list.head = NULL;

    return 0;
}