/*************************************************************************
	> File Name: 158.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 08:12:28 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) printf(" ");
        printf("%d", n - i);
        for (int j = 0; j < 2 * n - 1 - 2 * i; j++) printf(" ");
        printf("%d", n - i);
        printf("\n");
    }
    for (int j = 0; j < n; j++) printf(" ");
    printf("0\n");
    for (int i = n - 1; i >= 0 ; i--){
        for (int j = 0; j < i; j++) printf(" ");
        printf("%d", n - i);
        for (int j = 0; j < 2 * n - 1 - 2 * i; j++) printf(" ");
        printf("%d", n - i);
        printf("\n");
    }
    return 0;
}
