/*************************************************************************
	> File Name: rb_tree.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Apr 19 22:30:41 2022
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int key, color; // color = 0 red, 1 black, 2 double black
    Node *lchild, *rchild;

} Node;

Node __NIL;
#define NIL (&__NIL)

__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NULL;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = 0;
    return p;
}

int has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *left_rotate(Node *root) {
    Node *new_root = root->rchild;
    root->rchild = new_root->lchild;
    new_root->lchild = root;
    return new_root;
}

Node *right_rotate(Node *root) {
    Node *new_root = root->lchild;
    root->lchild = new_root->rchild;
    new_root->rchild = root;
    return new_root;
}

Node *insert_maitain(Node *root) {
    if (!has_red_child(root)) return root;
    if (
        !(root->lchild->color == 0 && has_red_child(root->lchild)) &&
        !(root->rchild->color == 0 && has_red_child(root->rchild))
    ) return root;

    // rotate
    if (root->rchild->color == 1) {
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else if (root->lchild->color == 1) {
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    root->color = 0;
    root->rchild->color = root->lchild->color = 1;
    return root;
}

Node *__insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    return insert_maitain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = 1;
    return root;
}


Node *erase_maintain(Node *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    // root is father of double black
    // sibling of double black is red or black, thus discuss as following
    int type = 0;
    if (has_red_child(root)) {
        // sibling is red, need to rotate and change color to get black sibling while keep balance.

        // need rebalance one of the child trees, which certainly has two black.
        // children due to the following adjustment.

        // root is certainly red becuase it has red child.
        type = 0; // 0:right child is red, need left rotate 1:left child is red, need right rotate
        root->color = 0; // change color before rotate for conciseness
        if (root->rchild->color == 0) root = left_rotate(root); // L type 0 double black in left tree
        else root = right_rotate(root), type = 1; // R type 1 double black in right tree
        root->color = 1;
        if (type) root->rchild = erase_maintain(root->rchild); // R type 1
        else root->lchild = erase_maintain(root->lchild); // L type 0
        return root;
    }
    // sibling is black
    if ((root->lchild->color == 1 && !has_red_child(root->lchild)) || 
        (root->rchild->color == 1 && !has_red_child(root->rchild))
    ) {
        // sibling has no red child
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        root->color += 1;
        return root;
    }
    // sibling is black and has red child
    if (root->lchild->color == 1) {
        // sibling on the left
        if (root->lchild->lchild->color != 0) {
            // LL is not red (not certainly black, sometimes NIL with double black) so LR is red, need left_rotate on lchild
            root->lchild = left_rotate(root->lchild);
        }
        // change color to rebalance(omit for conciseness)
        // root->lchild->color = 1, root->lchild->lchild->color = 0
        // makes no difference if omit becuase root->lchild->lchild will become root->lchild after rotation
        // LL is red, need right_rotate on root
        root->rchild->color = 1; // double black on the right, turn it back to black
        root->lchild->color = root->color; // change color before rotate for conciseness
        root = right_rotate(root);
    } else {
        // sibling on the right, dual problem
        if (root->rchild->rchild->color != 0) {
            root->rchild = right_rotate(root->rchild);
        }
        root->lchild->color = 1;
        root->rchild->color = root->color;
        root = left_rotate(root);
    }
    root->rchild->color = root->lchild->color = 1;
    return root;
}

Node *__erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) root->lchild = __erase(root->lchild, key);
    else if (root->key < key) root->rchild = __erase(root->rchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            // degree 0 and degree 1
            Node *tmp = root->lchild != NIL ? root->lchild : root->rchild;
            tmp->color += root->color;
            free(root);
            return tmp;
        } else {
            Node *tmp = root->lchild;
            while (tmp->rchild != NIL) tmp = tmp->rchild;
            root->key = tmp->key;
            root->lchild = __erase(root->lchild, tmp->key);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = 1;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print_node(Node *root) {
    //const char* color[2] = {"\e[97m\e[41m", "\e[97m\e[40m"};
    //printf("( %3d(\e[0m%s%d\e[0m) | %3d %3d )\n", root->key, color[root->color], root->color, root->lchild->key, root->rchild->key);
    printf("%d %d %d %d\n", root->key, root->color, root->lchild->key, root->rchild->key);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    print_node(root);
    output(root->rchild);
    return ;
}

int main() {
    Node *root = NIL;
    int opt, key;
    // insert 
    while (~scanf("%d%d", &opt, &key)) {
        switch (opt) {
            case 1:
                root = insert(root, key);
                break;
            case 2:
                root = erase(root, key);
                break;
            case 3:
                output(root);
                break;
        }
    }
    return 0;
}
