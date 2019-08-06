/*利用栈的数据结构特征实现十进制数到二进制数的转换*/
#include <stdio.h>

int main(void) {
    int num;
    int result[30];
    int top = -1;
    printf("请输入一个正整数：");
    scanf("%d", &num);

    while (num > 0) {
        result[++top] = num % 2;
        num = num / 2;
    }

    printf("转化为二进制后为：");

    while (top >= 0) {
        printf("%d", result[top--]);
    }

    printf("\n");

    return 0;

}