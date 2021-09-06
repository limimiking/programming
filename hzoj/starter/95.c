/*************************************************************************
	> File Name: 95.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 19:49:56 2021
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char n[3];
    scanf("%s", n);
    for (int i = strlen(n) - 1; i >= 0; i--) {
        printf("%c", n[i]);
    }
    printf("\n");
    return 0;
}
