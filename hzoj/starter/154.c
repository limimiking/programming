/*************************************************************************
	> File Name: 154.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 07:48:29 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = n - i; j > 0; j--) {
            j == n - i || printf(" ");
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
