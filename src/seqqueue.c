/*
	顺序队列
*/
#include <stdio.h>
#define SIZE 5

int inQueue(int *p, int end, int data) {
    p[end] = data;
    printf("入队元素：%d\n", p[end]);
    end++;
    return end;
}

int outQueue(int *p, int top, int end) {
    if (top == end) {
        printf("队列为空\n");
    } else {
        printf("出队元素：%d\n", p[top]);
        p[top++] = 0;
    }

    return top;
}

int main() {
    int a[20];
    int top, end;
    top = end = 0;

    for (int i = 0; i < SIZE; i++) {
        end = inQueue(a, end, i + 1);
        printf("队头：%d  队尾：%d\n", top, end);
    }

    for (int i = 0; i <= SIZE; i++) {
        top = outQueue(a, top, end);
        printf("队头：%d  队尾：%d\n", top, end);
    }

    return 0;
}