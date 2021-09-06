/*************************************************************************
	> File Name: 103.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 11:42:00 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a % b == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
