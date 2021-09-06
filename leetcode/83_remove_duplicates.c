/*************************************************************************
	> File Name: 19_remove_nth_before_end.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Aug 30 15:42:34 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CNT 15

typedef struct ListNode {
    int val;
    struct ListNode *next;
}Node;

typedef struct List {
    Node head;
    int len;
}List;

Node* initNode(int val) {
    Node* n = (Node *)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
};

void freeNode(Node* n) {
    n?free(n):0;
    return;
}

List* initList() {
    List* l = (List*)malloc(sizeof(List));
    l->head.next = NULL;
    l->len = 0;
    return l;
}

void freeList(List *l) {
    if (!l) return;
    Node* p = &(l->head);
    Node* pre;
    while(p) {
        pre = p;
        p = p->next;
        free(pre);
    }
    free(l); //important
    return ;
}

int insertNode(List *l, int idx, Node* n) {
    if (!l) return 0;
    if (idx < 0 || idx > l->len) return 0;
    Node* p = &(l->head);
    while(idx--)
        p = p->next;
    n->next = p->next;
    p->next = n;

    l->len++;
    return 1;
}

int insertValue(List *l, int idx, int val) {
    Node* n = initNode(val);
    if (!insertNode(l, idx, n)) {
        freeNode(n);
        return 0;
    }
    return 1;
}

int erase(List *l, int idx) {
    if (!l) return 0;
    if (idx < 0 || idx >= l->len) return 0;
    Node* p = &(l->head);
    while(idx--) p = p->next;
    Node* n_to_erase = p->next;
    p->next = n_to_erase->next;
    freeNode(n_to_erase);
    l->len--;
    return 1;
}

void showList(List *l) {
    if (!l) return;
    Node *p = l->head.next;
    printf("List:[");
    while (p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL]\n");
    return;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head) return NULL;
    struct ListNode *p = head;
    struct ListNode *remove;
    while(p->next) {
        if (p->next->val == p->val) {
            remove = p->next;
            p->next = remove->next;
            free(remove);
        }
        else {
            p = p->next;
        }
    }
    return head;
}

int main() {
    srand(time(0));
    List *l = initList();
    int val = 0;
    for (int cnt = 0; cnt < CNT; cnt++) {
        val += (rand() % 10 < 3);
        insertValue(l, cnt, val);
    }
    showList(l);
    l->head.next = deleteDuplicates(l->head.next);
    showList(l);
    
    return 0;
}
