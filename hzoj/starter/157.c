/*************************************************************************
	> File Name: 157.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 22 11:32:47 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = n; i > 1; i--) {
        for (int j = 0; j < n - i; j++) printf(" ");
        for (int j = n - i; j < n; j++) printf("%c", 'A' + j);
        for (int j = n - 2; j > n - i - 1; j--) printf("%c", 'A' + j);
        printf("\n");
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) printf(" ");
        for (int j = n - i; j < n; j++) printf("%c", 'A' + j);
        for (int j = n - 2; j > n - i - 1; j--) printf("%c", 'A' + j);
        printf("\n");
    }
    return 0;
}
