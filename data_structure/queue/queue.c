/*************************************************************************
	> File Name: queue.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Sep 11 14:36:58 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct Queue{
    int *data;
    int size;
    int head, tail;
}Queue;

Queue *initQueue(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->size = n;
    q->head = q->tail = 0;
    return q;
}

void freeQueue(Queue *q) {
    if (!q) return;
    free(q->data);
    free(q);
    return;
}


int expand(Queue *q);
int push(Queue *q, int val) {
    if (!q) return 0;
    if ((q->tail + 1) % q->size == q->head) {
        if (!expand(q)) return 0;
    }
    q->tail = (q->tail + 1) % q->size;
    q->data[q->tail] = val;
    return 1;
}

int isEmpty(Queue *q) {
    return !q || q->head == q->tail;
}
int pop(Queue *q) {
    q->head = (q->head + 1) % q->size;
    return q->data[q->head];
}

void showQueue(Queue *q) {
    if (isEmpty(q)) return;
    int cursor = q->head;
    printf("Queue :[");
    do {
        cursor == q->head || printf(",");
        cursor = (cursor + 1) % q->size;
        printf("%d", q->data[cursor]);
    } while (cursor != q->tail);
    printf("]\n");
    return;
}

int expand(Queue *q) {
    if (!q) return 0;
    int expand_size = q->size;
    int new_tail = 0;
    int *tmp = NULL;
    int cursor = q->head;

    while (expand_size) {
        tmp = (int *)malloc(sizeof(int) * (q->size + expand_size));
        if (tmp) break;
        expand_size >> 1;
    }
    
    if (!isEmpty(q)) {
        do {
            cursor = (cursor + 1) % q->size;
            tmp[++new_tail] = q->data[cursor];
        } while (cursor != q->tail);
    }

    if (!tmp) {
        printf("\e[0m\e[31mexpand failed\e[0m\n");
        return 0;
    }
    free(q->data);
    q->data = tmp;
    q->head = 0;
    q->tail = new_tail;
    q->size += expand_size;
    printf("\e[0m\e[32mexpand success\e[0m\n");
    return 1;
}

int main() {
    srand(time(0));
    Queue *q = initQueue(1);

    int cnt = 20;
    while(cnt--) {
        int val = rand() % 100;
        int opt = rand() % 4;
        switch(opt) {
            case 0:
            case 1:
            case 2:
                printf("push %d, res = %s\n", val, push(q, val) ? "SUC" : "ERR");
                break;
            case 3:
                isEmpty(q) ? printf("pop nothing\n") : printf("pop %d\n", pop(q));
        }
        showQueue(q);
    }

    freeQueue(q);
    return 0;
}
