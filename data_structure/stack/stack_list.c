/*************************************************************************
	> File Name: stack_list.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Sep  6 11:37:19 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}Node;

typedef struct Stack {
    Node *head;
    int len;
}Stack;

Node *initNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
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
    s->len = 0;
    return s;
}
