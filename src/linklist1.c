/*
	链表
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define ADDNUM 9
#define ADDPOS 6
#define DELPOS 5
#define SEARCHNUM 3
#define MODIFYPOS 3
#define MODIFYNUM 27

typedef struct node {
    int elem;
    struct node *next;
} Node;

/*创建一个结点*/
Node *initNode(Node *pre, int elem) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->elem = elem;
    node->next = NULL;
    pre->next = node;
    return node;
}

/*显示链表*/
void display(Node *p) {
    Node *temp = p;
    printf("共%d个元素：", temp->elem);

    while (temp->next) {
        temp = temp->next;//跳过头结点
        printf("  %d", temp->elem);
    }

    printf("\n");
}

/*增*/
void add(Node *p, int elem, int pos) {
    //插入位置判断，取值范围为0～length
    int length = p->elem;//传入的是头结点，直接取链表长度值

    if (pos > length   || pos < 0) {
        printf("插入位置有误\n");
        return;
    }

    //找到需要插入位置的上一个结点
    Node *temp = p;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    //新建一个结点
    Node *add = (Node *)malloc(sizeof(Node));
    add->elem = elem;
    add->next = temp->next;//将新结点的next指向上一个结点原来的next
    temp->next = add;//将上一个结点指向新结点

    p->elem ++;//表长度+1
}

/*删*/
void delete(Node *p, int pos) {
    //删除位置判断，取值范围为0～length-1
    int length = p->elem;//传入的是头结点，直接取链表长度值

    if (pos >= length || pos < 0) {
        printf("删除位置有误\n");
        return;
    }

    //找到需要删除位置的上一个结点
    Node *temp = p;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    Node *del = temp->next;//需要删除的结点
    temp->next = del->next;//将上一个结点的指针指向删除结点的后一个结点
    free(del);//释放内存
    del = NULL;

    p->elem --;//表长度-1
}

/*查*/
int search(Node *p , int elem) {
    int i = 0;
    Node *temp = p;

    while (temp->next) {
        temp = temp->next;

        if (temp->elem == elem) {
            return i;
        }

        i++;
    }

    return -1;
}

/*改*/
void modify(Node *p, int pos, int val) {
    Node *temp = p;

    for (int i = 0; i < pos + 1 ; i++) {
        temp = temp->next;
    }

    temp->elem = val;
}

void freeNode(Node *p) {
    Node *cur = p;
    Node *next;

    while (cur->next) {
        next = cur->next;
        free(cur);
        cur = NULL;
        cur = next;
    }
}

int main(void) {
    Node *head = (Node *)malloc(sizeof(Node)); //创建头结点
    Node *pre = head;//将头结点作为首元结点的前一个结点

    for (int i = 0; i < SIZE; i++) {
        pre = initNode(pre, i + 1);//创建结点，并将新建结点作为后一个结点的前结点
    }

    head->elem = SIZE;

    display(head);

    printf("在第%d个位置上插入元素%d。\n", ADDPOS, ADDNUM);
    add(head, ADDNUM, ADDPOS);
    display(head);

    printf("删除第%d个位置上元素\n", DELPOS);
    delete(head, DELPOS);
    display(head);

    printf("查找元素%d的位置\n", SEARCHNUM);
    printf("元素%d的位置为第%d个\n", SEARCHNUM, search(head, SEARCHNUM));

    printf("把第%d个元素修改为%d\n", MODIFYPOS, MODIFYNUM);
    modify(head, MODIFYPOS, MODIFYNUM);
    display(head);

    freeNode(head);
    return 0;
}
