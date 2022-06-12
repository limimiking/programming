/*************************************************************************
    > File Name: 1.binary_search_tree.cpp
    > Author: Bruce_Lin
    > Mail: xiaotian.lin@hit.edu.cn
    > Created Time: Fri Apr 15 11:25:42 2022
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>

#define KEY(n) (n ? n->key : 0)
#define CNT(n) (n ? n->cnt : 0)

#define TEST(func) { \
    while (~scanf("%d", &key)) { \
        if (key == -1) break; \
        root = func(root, key); \
        printf("\n=== %s %d %s BST ===\n", #func, key, #func[0]=='e' ? "from" : "to"); \
        output(root); \
        printf("Node cnt: %d\n", CNT(root)); \
        inorder_output(root); \
        printf("\n"); \
    } \
}

typedef struct Node {
    int key, cnt;
    Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->cnt = 1;
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

void update_cnt(Node *root) {
    root->cnt = CNT(root->lchild) + CNT(root->rchild) + 1; 
    return ;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    update_cnt(root);
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
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_cnt(root);
    return root;
}

void print_node(Node *root) {
    printf("( %3d | %3d, %3d  )\n",
        KEY(root),
        KEY(root->lchild), KEY(root->rchild)
    );
    return ;

}

void output_range(Node *root, int l, int r) {
    if (root == NULL) return;
    output_range(root->lchild, l, r);
    if (root->key <=r && root->key >= l) printf("%d ", root->key);
    output_range(root->rchild, l, r);
    return;

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

Node *search(Node *root, int key) {
    if (root == NULL || root->key == key) return root;
    if (root->key > key) return search(root->lchild, key);
    return search(root->rchild, key);
}

Node *__find_k(Node *root, int k) {
    if (root == NULL) return NULL;
    if (CNT(root->lchild) >= k) return __find_k(root->lchild, k);
    if (CNT(root->lchild) + 1 == k) return root;
    return __find_k(root->rchild, k - CNT(root->lchild) - 1);
}

Node *find_k(Node *root, int k) {
    if (k <= 0 || k > CNT(root)) return NULL;
    return __find_k(root, k);
}
int main() {
    Node *root = NULL;
    Node *ret = NULL;
    int key;
    //insert
    TEST(insert);

    //erase
    //TEST(erase);

    // search
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        ret = search(root, key);
        if (ret) printf("find %d from BST\n", ret->key);
        else printf("%d not found\n", key);
    }

    // find kth
    while (~scanf("%d", &key)) {
        if (key == -1) break;
        ret = find_k(root, key);
        if (ret) printf("find %dth: %d\n", key, ret->key);
        else printf("%dth not found\n", key);
    }

    // output range
    int l, r;
    while (~scanf("%d%d", &l, &r)) {
        if (l == -1) break;
        printf("find range [%d, %d]: ", l, r);
        output_range(root, l, r);
        printf("\n");
    }
    

    return 0;
}

