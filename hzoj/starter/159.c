/*************************************************************************
	> File Name: 159.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 08:23:31 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    char ch;
    int n;
    scanf("%c", &ch);
    n = ch - 'A' + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) printf(" ");
        for (int j = 0; j < n - i; j++) printf("%c", ch - j - i);
        for (int j = 0; j < n - i - 1; j++) printf("%c", 'A' + j);
        printf("\n");
    }
    return 0;
}
