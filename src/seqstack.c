/*
	顺序栈
*/
#include <stdio.h>
#define SIZE 5

/*入栈*/
int push(int *p, int top, int elem) {
    p[++top] = elem;
    printf("入栈元素：%d，栈顶为：%d\n", elem, top);
    return top;
}

/*出栈*/
int pop(int *p, int top) {
    if (top == -1) {
        printf("空栈\n");
        return -1;
    }

    printf("出栈元素：%d  ", p[top]);
    p[top--] = 0;
    printf("栈顶为：%d\n", top);
    return top;
}

int main() {
    int a[20] = {0};
    int top = -1;

    for (int i = 0; i < SIZE; i++) {
        top = push(a, top, i + 1);
    }

    for (int i = 0; i <= SIZE; i++) {
        top = pop(a, top);
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}