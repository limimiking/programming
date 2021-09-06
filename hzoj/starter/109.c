/*************************************************************************
	> File Name: 109.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 14:13:33 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n) {
        if (!((n % 10) & 1)) {
            printf("YES\n");
            return 0;
        }
        n /= 10;
    }
    printf("NO\n");
    return 0;
}
