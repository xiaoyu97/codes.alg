#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define ADDNUM 9
#define ADDPOS 3
#define DELPOS 3
#define SEARCHNUM 3
#define MODIFYPOS 3
#define MODIFYNUM 27

int length;

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
    printf("共%d个元素：", length);

    while (temp->next) {
        temp = temp->next;
        printf("  %d", temp->elem);
    }

    printf("\n");
}

/*找到指定位置的上一个节点*/
Node *getPreNode(Node *head, int pos, int min , int max) {
    if (pos > max   || pos < min) {
        printf("位置有误\n");
        return NULL;
    }

    Node *temp = head;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    return temp;
}
void add(Node *head, int elem, int pos) {
    Node *pre = getPreNode(head, pos, 0, length);

    if (pre == NULL) {
        return;
    }

    //新建一个结点
    Node *add = (Node *)malloc(sizeof(Node));
    add->elem = elem;
    add->next = pre->next;//将新结点的next指向上一个结点原来的next
    pre->next = add;//将上一个结点指向新结点

    length++;
}

void delete(Node *head, int pos) {
    Node *pre = getPreNode(head, pos, 0, length - 1);

    if (pre == NULL) {
        return;
    }

    Node *del = pre->next;//需要删除的结点
    pre->next = del->next;//将上一个结点的指针指向删除结点的后一个结点
    free(del);//释放内存
    del = NULL;

    length--;
}

int search(Node *head, int elem) {
    int i = 0;
    Node *temp = head;

    while (temp->next) {
        temp = temp->next;

        if (temp->elem == elem) {
            return i;
        }

        i++;
    }

    return -1;
}

void modify(Node *head, int pos, int val) {
    Node *temp = head;

    for (int i = 0; i < pos + 1 ; i++) {
        temp = temp->next;
    }

    temp->elem = val;
}

void freeNode(Node *head) {
    Node *cur = head->next;
    Node *next;

    while (cur->next) {
        next = cur->next;
        free(cur);
        cur = NULL;
        cur = next;
    }
}

int main(void) {
    Node *head ; //创建头结点指针
    Node *pre = head;//将头结点作为首元结点的前一个结点

    for (int i = 0; i < SIZE; i++) {
        pre = initNode(pre, i + 1);//创建结点，并将新建结点作为后一个结点的前结点
    }

    length = SIZE;

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
}