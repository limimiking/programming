/*************************************************************************
	> File Name: linear_table.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sun 29 Aug 2021 10:18:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


typedef struct Vector{
    int *data;
    int size;
    int len;
}Vec;

Vec *init(int n){
    Vec *v = (Vec *)malloc(sizeof(Vec));
    v->data  = (int *)malloc(sizeof(int) * n);
    v->size = n;
    v->len=0;
    printf("init size %d\n", v->size);
    return v;
}

void freeVec(Vec *v){
    if(v){
        free(v->data);
        free(v);
    }
    printf("free\n");
    return;
}

int expand(Vec *v);

int insert(Vec *v, int idx, int val) {
    if (!v)
        return 0;
    if (idx < 0 || idx > v->len) {
        return 0;
    }
    if (v->len == v->size) {
        if (!expand(v)) {
            return 0;
        }
        return 0;
    }
    memcpy(v->data + idx + 1, v->data + idx, sizeof(int) * (v->len - idx));
    v->data[idx] = val;
    v->len++;
    return 1;
}

int erase(Vec *v, int idx) {
    if (!v)
        return 0;

    if (idx < 0 || idx >= v->len)
        return 0;

    memcpy(v->data + idx, v->data + idx + 1, sizeof(int) * (v->len - idx - 1));
    v->len--;
    return 1;
}

void showVec(Vec *v) {
    if (!v)
        return ;
    printf("Vec:[");
    for (int i = 0; i < v->len; i++) {
        i && printf(",");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return ;
}

int expand(Vec *v) {
    if (!v)
        return 0;

    int expsize = v->size;
    int *tmp;
    while(expsize) {
        tmp = (int *)realloc(v->data, sizeof(int)*(v->size + expsize));
        if (tmp)
            break;

        expsize >>= 2;
    }

    if (!tmp) {
        printf("expand failed\n");
        return 0;
    }
    v->data = tmp;
    v->size = v->size + expsize;
    printf("expand success\n");
    return 1;
}
int main() {
    Vec *v = init(1);
    srand(time(0));
    int cnt = 20;
    while(cnt--) {
        int val = rand() % 100;
        int op = rand() % 8;
        int idx = rand() % (v->len + 3) - 1;

        switch(op) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                printf("insert %d at %d, res = %d\n", val, idx, insert(v, idx, val));
                break;
            case 7:
                printf("erase at %d, res = %d\n", idx, erase(v, idx));
                break;
        }

        showVec(v);
    
    }

    freeVec(v);
    return 0;
}
