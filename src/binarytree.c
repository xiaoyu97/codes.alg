/*
	二叉树链式存储
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *lchild, *rchild;
} TreeNode;

int main(void) {
    TreeNode *parent = (TreeNode *)malloc(sizeof(TreeNode));
    parent->data = 1;
    parent->lchild = (TreeNode *)malloc(sizeof(TreeNode));
    parent->lchild->data = 2;
    parent->lchild->lchild = (TreeNode *)malloc(sizeof(TreeNode));
    parent->lchild->lchild->data = 4;
    parent->lchild->lchild->lchild = NULL;
    parent->lchild->lchild->rchild = NULL;
    parent->lchild->rchild = NULL;
    parent->rchild = (TreeNode *)malloc(sizeof(TreeNode));
    parent->rchild->data = 3;
    parent->rchild->lchild = NULL;
    parent->rchild->rchild = NULL;
    
    printf("%d\n", parent->lchild->lchild->data);

    free(parent->lchild->lchild);
    parent->lchild->lchild = NULL;
    free(parent->lchild);
    parent->lchild = NULL;
    free(parent->rchild);
    parent->rchild = NULL;
    free(parent);
    parent = NULL;
    return 0;
}