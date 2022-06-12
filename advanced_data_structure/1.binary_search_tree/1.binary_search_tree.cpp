/*************************************************************************
    > File Name: 1.binary_search_tree.cpp
    > Author: Bruce_Lin
    > Mail: xiaotian.lin@hit.edu.cn
    > Created Time: Fri Apr 15 11:25:42 2022
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>

#define KEY(n) (n ? n->key : 0)

#define TEST(func) { \
    while (~scanf("%d", &key)) { \
        if (key == -1) break; \
        root = func(root, key); \
        printf("\n=== %s %d %s BST ===\n", #func, key, #func[0]=='e' ? "from" : "to"); \
        output(root); \
        inorder_output(root); \
    } \
}

typedef struct Node {
    int key;
    Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (root == NULL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;

}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}
Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (root->key > key) root->lchild = erase(root->lchild, key);
    else if (root->key < key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        } else if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

void print_node(Node *root) {
    printf("( %3d | %3d, %3d  )\n",
        KEY(root),
        KEY(root->lchild), KEY(root->rchild)
    );
    return ;

}

void output(Node *root) {
    if (root == NULL) return;
    print_node(root);
    output(root->lchild);
    output(root->rchild);
    return ;
    
}

void inorder_output(Node *root) {
    if (root == NULL) return;
    inorder_output(root->lchild);
    printf("%d ", root->key);
    inorder_output(root->rchild);
    return ;
    
}

int main() {
    Node *root = NULL;
    int key;
    //insert
    TEST(insert);

    //erase
    TEST(erase);

    return 0;
}

