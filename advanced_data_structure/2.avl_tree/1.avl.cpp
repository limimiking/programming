/*************************************************************************
	> File Name: 1.avl.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sun Apr 17 20:27:55 2022
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

// virtual null node
Node __NIL;
#define NIL (&__NIL)
#define DEBUG
#ifdef DEBUG

#define LOG(frm, args...) { \
    printf(frm, ##args); \
} \

#else
#define LOG(frm, args...) {}
#endif
__attribute__((constructor)) // run before main function
void init_NIL() {
    NIL->key = NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

#define max(a, b) ((a) > (b) ? (a) : (b))

void update_height(Node *root) {
    root->h = max(root->lchild->h, root->rchild->h) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    LOG("%d left_rotate\n", root->key);
    Node *new_root = root->rchild;
    root->rchild = new_root->lchild;
    new_root->lchild = root;
    update_height(root);
    update_height(new_root);
    return new_root;
}

Node *right_rotate(Node *root) {
    LOG("%d right_rotate\n", root->key);
    Node *new_root = root->lchild;
    root->lchild = new_root->rchild;
    new_root->rchild = root;
    update_height(root);
    update_height(new_root);
    return new_root;
}

const char *type_str[4] = {"LL", "LR", "RR", "RL"};

Node *maintain(Node *root) {
    if (abs(root->lchild->h - root->rchild->h) < 2) return root;
    int type = -1; // LL:0 LR:1 RR:2 RL:3
    if (root->lchild->h > root->rchild->h) {
        // L_
        if (root->lchild->lchild->h < root->lchild->rchild->h) {
            // LR
            root->lchild = left_rotate(root->lchild);
            type += 1;
        }
        type += 1;
        root = right_rotate(root);
    } else {
        // R_
        type = 1;
        if (root->rchild->rchild->h < root->rchild->lchild->h) {
            // RL
            root->rchild = right_rotate(root->rchild);
            type += 1;
        }
        type += 1;
        root = left_rotate(root);
    }
    LOG("TYPE : %s\n", type_str[type]);
    return root;
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    update_height(root);
    return maintain(root);
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) root->lchild = erase(root->lchild, key);
    else if (root->key < key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *tmp = root->lchild != NIL ? root->lchild : root->rchild;
            free(root);
            return tmp;
        } else {
            Node *tmp = root->lchild;
            while(tmp->rchild != NIL) tmp = tmp->rchild;
            root->key = tmp->key;
            root->lchild = erase(root->lchild, tmp->key);
        }
    }
    update_height(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print_node(Node *root) {
    printf("[%3d(%3d) | %3d %3d]\n",
        root->key, root->h,
        root->lchild->key,
        root->rchild->key
    );
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    print_node(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}
int main() {
    Node *root = NIL;
    int key;
    // insert
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        printf("insert %d to AVL Tree\n", key);
        root = insert(root, key);
        output(root);
    }
    // erase
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        printf("erase %d from AVL Tree\n", key);
        root = erase(root, key);
        output(root);
    }
    return 0;
}
