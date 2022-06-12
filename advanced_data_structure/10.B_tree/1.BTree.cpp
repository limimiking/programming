/*************************************************************************
	> File Name: 1.BTree.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun  6 17:22:59 2022
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_M 3
typedef struct Node {
    int n;
    int key[MAX_M + 1]; // at most MAX_M - 1 keys, +1 for convenience during shifting
    struct Node *next[MAX_M + 1]; // at most MAX_M children, may exceed MAX_M during maintaining
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->n = 0;
    memset(p->next, 0, sizeof(Node *) * (MAX_M + 1));
    return p;
}

Node *insert_key(Node *root, int key) {
    if (root == NULL) {
        root = getNewNode();
        root->key[(root->n)++] = key;
        return root;
    }
    int pos = 0;
    while (pos < root->n && root->key[pos] < key) pos += 1;
    if (pos < root->n && root->key[pos] == key) return root;
    for (int i = root->n - 1; i >= pos; i--) {
        root->key[i + 1] = root->key[i];
    }
    root->key[pos] = key;
    root->n += 1;
    return root;
}

Node *insert_maintain(Node *root, Node *child, int pos) {
    if (child->n < MAX_M) return root;
    int spos = MAX_M / 2; // node split
    Node *left = getNewNode();
    Node *right = getNewNode();
    left->n = spos;
    right->n = MAX_M  - spos - 1;
    for (int i = 0; i < left->n; i++) {
        left->key[i] = child->key[i];
        left->next[i] = child->next[i];
    }
    left->next[left->n] = child->next[left->n];
    for (int i = 0 ; i < right->n; i++) {
        right->key[i] = child->key[spos + 1 + i];
        right->next[i] = child->next[spos + 1 + i];
    }
    right->next[right->n] = child->next[MAX_M];
    for (int i = root->n; i >= pos; i--) {
        root->key[i + 1] = root->key[i];
        root->next[i + 1] = root->next[i];
    }
    root->key[pos] = child->key[spos];
    root->next[pos] = left;
    root->next[pos + 1] = right;
    root->n += 1;
    free(child);
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NULL || root->next[0] == NULL) {
        return insert_key(root, key);
    }
    int pos = 0;
    while (pos < root->n && root->key[pos] < key) pos += 1;
    if (pos < root->n && root->key[pos] == key) return root;
    __insert(root->next[pos], key);
    return insert_maintain(root, root->next[pos], pos);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    if (root->n == MAX_M) {
        Node *p = getNewNode();
        p->next[0] = root;
        root = insert_maintain(p, root, 0);
    }
    return root;
}

void clear(Node *root) {
    if (root == NULL) return ;
    if (root->next[0] != NULL) {
        for (int i = 0; i <= root->n; i++) {
            clear(root->next[i]);
        }
    }
    free(root);
    return ;
}


void print_node(Node *root) {
    printf("%d : ", root->n);
    for (int i = 0; i < root->n; i++) {
        printf("%4d ", root->key[i]);
    }
    printf("|");
    if (root->next[0] != NULL) {
        for (int i = 0; i <= root->n; i++) {
            printf(" %4d", root->next[i]->key[0]);
        }
    }
    printf("\n");
    return ;
}

void output(Node *root) {
    if (root == NULL) return;
    print_node(root);
    for (int i = 0; i <= root->n; i++) {
        output(root->next[i]);
    }
    return ;
}
int main() {
    srand(time(0));
    Node *root = NULL;
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
        printf("\ninsert %d to BTree: \n", val);
        output(root);
    }
    #undef MAX_OP
    return 0;

}
