/*************************************************************************
	> File Name: stack_list.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Sep  6 11:37:19 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}Node;

typedef struct Stack {
    Node *head;
//    int len;
}Stack;

Node *initNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) return NULL;
    n->val = val;
    n->next = NULL;
    return n;
}

void freeNode(Node *n) {
    n ? free(n) : 0;
    return;
}

Stack *initStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->head = NULL;
//    s->len = 0;
    return s;
}

void freeStack(Stack *s) {
    if (!s) return;
    Node *p = s->head;
    Node *remove;
    while(p) {
        remove = p;
        p = p->next;
        freeNode(remove);
    }
    return;
}

int push(Stack *s, int val) {
    if (!s) return 0;
    Node *n = initNode(val);
    if (!n) return 0;
    n->next = s->head;
    s->head = n;
//    s->len++;
    return 1;
}

int isEmpty(Stack *s) {
    return !(s && s->head);
}

int pop(Stack *s) {
    Node *p = s->head;
    int val = p->val;
    s->head = p->next;
    freeNode(p);
//    s->len--;
    return val;
}

void showStack(Stack *s) {
    if (!s) return;
    Node *p = s->head;
    printf("Stack:[");
    while(p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL]\n");
    printf("-------------\n");
    return;
}

int main() {
    srand(time(0));
    Stack *s = initStack();
    int cnt = 20;
    while (cnt--) {
        int val = rand() % 100;
        int opt = rand() % 4;
        switch (opt) {
            case 0:
            case 1:
            case 2:
                printf("push %d, res = %s\n", val, push(s, val) ? "SUC" : "ERR");
                break;
            case 3:
                isEmpty(s) ? printf("pop nothing\n") : printf("pop %d\n", pop(s));
        }
        showStack(s);
    }
    freeStack(s);
    return 0;
}
