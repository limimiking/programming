/*************************************************************************
	> File Name: threadedBinaryTree.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed Sep 15 10:45:11 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CHILD 0
#define THREAD 1
typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    int ltag, rtag;
}Node;

Node *initNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    n->ltag = CHILD;
    n->rtag = CHILD;
    return n;
}

void freeNode (Node *p) {
    p ? free(p) : 0;
    return;
}

void insert(Node **raddr, int val) {
    if (!(*raddr)) {
        (*raddr) = initNode(val);
        return;
    }

    if (val > (*raddr)->val)
        insert(&(*raddr)->right, val);
    else
        insert(&(*raddr)->left, val);
}

void freeAll(Node *root) {
    if (!root) return;
    freeAll(root->left);
    freeAll(root->right);
    free(root);
    return;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
    return;
}

Node *pre = NULL;
void buildThread(Node *root) {
    if (!root)
        return;
    buildThread(root->left);
    if (!root->left) {
        root->left = pre;
        root->ltag = THREAD;
    }
    
}

int main() {
    srand(time(0));
    Node *root = NULL;
    int cnt = 10;
    while(cnt--) {
        int val = rand() % 100;
        insert(&root ,val);
        printf("%d ", val);
    }
    putchar(10);
    inorder(root);
    freeAll(root);
    return 0;
}
