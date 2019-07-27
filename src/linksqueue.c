/*
	链队列
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct node {
    int data;
    struct node *next;
} QNode;

QNode *initHeadNode() {
    QNode *node = (QNode *)malloc(sizeof(QNode));
    node->next = NULL;
    return node;
}

QNode *inQueue(QNode *end , int data) {
    QNode *node = (QNode *)malloc(sizeof(QNode));
    node->data = data;
    node->next = NULL;
    printf("入队元素：%d\n", node->data);
    end->next = node;
    end = node;
    return end;
}

void outQueue(QNode *top, QNode *end) {
    if (top->next == NULL) {
        printf("队列为空\n");
    } else {
        QNode *out = top->next;
        printf("出队元素：%d\n", out->data);
        top->next = out->next;

        if (end == out) {
            end = top;
        }

        free(out);
        out = NULL;
    }
}

int main() {
    QNode *top, *end;
    top = end = initHeadNode();

    for (int i = 0; i < SIZE; i++) {
        end = inQueue(end, i + 1);
    }

    for (int i = 0; i <= SIZE; i++) {
        outQueue(top, end);
    }

    return 0;
}