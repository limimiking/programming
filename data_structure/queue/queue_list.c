/*************************************************************************
	> File Name: queue_stack.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Sep 11 21:15:46 2021
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

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

Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;

}

void freeQueue(Queue *q) {
    if (!q) return;
    Node *p = q->head;
    Node *remove;
    while(p) {
        remove = p;
        p = p->next;
        freeNode(remove);
    }
    free(q);
}

int push(Queue *q, int val) {
    if (!q) return 0;
    Node *n = initNode(val);
    if (!n) return 0;
    if (!q->head) {
        q->head = q->tail = n;
        return 1;
    }
    q->tail->next = n; 
    q->tail = n;
    return 1;
}

int pop(Queue *q) {
    Node *remove = q->head;
    q->head = remove->next;
    if (!q->head) q->tail = NULL;
    int val = remove->val;
    freeNode(remove);
    return val;
}

int isEmpty(Queue *q) {
    return !q || !q->head; 
}

void showQueue(Queue *q) {
    if (!q) return;
    Node *p = q->head;
    printf("Queue:[");;
    while(p) {
        printf("%d->", p->val); 
        p = p->next;
    }
    printf("NULL]\n");
}

int main() {
    srand(time(0));
    Queue *q = initQueue();
    int cnt = 30;
    while (cnt--) {
        int val = rand() % 100;
        int opt = rand() % 4;
        switch (opt) {
            case 0:
            case 1:
            case 2:
                printf("push %d, res = %s\n", val, push(q, val) ? "SUC" : "ERR");
                break;
            case 3:
                isEmpty(q) ? printf("pop nothing\n") : printf("pop %d\n", pop(q));
                break;
        }
        showQueue(q);
    }

    freeQueue(q);
    
    return 0;
}
