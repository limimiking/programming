/*************************************************************************
	> File Name: tree.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Sep 14 15:19:26 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct Tree {
    Node *root;
    int len;
}Tree;

Node *initNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void freeNode(Node *n) {
    n ? free(n) : 0;
    return;
}

Tree *initTree() {
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->root = NULL;
    t->len = 0;

    return t;
}

void insert(Node **rootaddr, int val) {
    if (!(*rootaddr)) {
        *rootaddr = initNode(val);
        return;
    }
    if (val > (*rootaddr)->val) insert(&(*rootaddr)->right, val);
    else insert(&(*rootaddr)->left, val);
    return;
}

//Node *insert(Node *root, int val) {
//    if (!root) {
//        Node *n = initNode(val);
//        return n;
//    }
//    if (val > root->val) root->right = insert(root->right, val);
//    else root->left = insert(root->left, val);
//    return root;
//}

void insertTree(Tree *t, int val) {
    if (!t) return;
//    t->root = insert(t->root, val);
    insert(&(t->root), val);
    t->len++;
    return;
}

void preorder(Node *root) {
    if (!root) return;
    printf("%d->", root->val);
    preorder(root->left);
    preorder(root->right);
    return;
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->val);
    return;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d->", root->val);
    inorder(root->right);
    return;
}

void orderTree(Tree *t, int opt) {
    if (!t) return;
    switch (opt) {
        case 0:
            printf("Pre:[");
            preorder(t->root);
            printf("]\n");
            break;
        case 1:
            printf("In:[");
            inorder(t->root);
            printf("]\n");
            break;
        case 2:
            printf("Post:[");
            postorder(t->root);
            printf("]\n");
            break;
    }
}

void freeAll(Node *root) {
    if (!root) return;
    freeAll(root->left);
    freeAll(root->right);
    freeNode(root);
    return;
}

void freeTree(Tree *t) {
    if (!t) return;
    freeAll(t->root);
    free(t);
}

void showGt(Node *root) {
    if (!root) return;
    printf("%d", root->val);
    if (!root->left && !root->right) return;
    printf("(");
    showGt(root->left);
    printf(",");
    showGt(root->right);
    printf(")");
    return;
}

void showGtTree(Tree *t) {
    if (!t) return;
    showGt(t->root);
    printf("\n");
    return;
}

Node *findNode(Node *root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    if (val >= root->val) return findNode(root->right, val);
    return findNode(root->left, val);
}

void findInTree(Tree *t, int val) {
    Node *p = findNode(t->root, val);
    if (!p) {
        printf("not found\n");
        return;
    }
    printf("find %d\n", p->val);
    return;

}

  

int main() {
    srand(time(0));
    int cnt = 30;
    Tree *t = initTree();
    while(cnt--) {
        int val = rand() % 100;
        int opt = rand() % 4;
        insertTree(t, val);
    }
    orderTree(t, 0);
    orderTree(t, 1);
    orderTree(t, 2);
    showGtTree(t);

    findInTree(t, 10);

    freeTree(t);
    return 0;
}
