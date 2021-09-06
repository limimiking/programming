/*************************************************************************
	> File Name: 107.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 14:04:31 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n % 7 == 0 && n & 1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
