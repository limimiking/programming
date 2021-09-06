/*************************************************************************
	> File Name: stack.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sun Sep  5 22:39:17 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Stack {
    int *data;
    int top;
    int size;
}Stack;

Stack *initStack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;

    return s;
}

void freeStack(Stack **saddr) {
    if (!(*saddr)) return;
    free((*saddr)->data);
    free((*saddr));
    return;
}

int expand(Stack **saddr) {
    if (!(*saddr)) return 0;
    int expand_size = (*saddr)->size;
    int *tmp;
    while (expand_size) {
        tmp = (int *)realloc((*saddr)->data, sizeof(int) * ((*saddr)->size + expand_size));
        if (*saddr) break;
        expand_size >> 2;
    }
    if (!(*saddr)) {
        printf("\e[0m\e[31mexpand failed\e[0m\n");
        return 0;
    } 
    (*saddr)->data = tmp; 
    (*saddr)->size += expand_size;
    printf("\e[0m\e[32mexpand success\e[0m\n");
    printf("new size is %d\n", (*saddr)->size);
    return 1;
}

int push(Stack *s, int val) {
    if (!s) return 0;
    if (s->top == s->size - 1) {
        if (!expand(&s)) return 0;
    }
    s->data[++s->top] = val;
    return 1;
}

int isEmpty(Stack *s) {
    return !s || s->top == -1;
}

int pop(Stack *s) {
    return s->data[s->top--];
}


void showStack(Stack *s) {
    if (!s) return;
    printf("Stack:[");
    for (int i = 0; i <= s->top; i++) {
        i && printf(",");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    printf("---------------\n");
}

int main() {
    srand(time(0));
    Stack *s = initStack(1);
    int cnt = 100;
    while (cnt--) {
        int val = rand() % 100;
        int opt = rand() % 4;
        switch(opt) {
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
    freeStack(&s);
    return 0;
}
