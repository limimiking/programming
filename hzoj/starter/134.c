/*************************************************************************
	> File Name: 134.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 20:34:43 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int start, end;
    start = a % 11 ? a / 11 + 1 : a / 11;
    end = b / 11;
    for (int i = start; i <= end; i++) {
        i == start || printf(" ");
        printf("%d", i * 11);
    }
    printf("\n");
    return 0;
}
