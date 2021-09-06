/*************************************************************************
	> File Name: 184.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri 02 Jul 2021 02:39:33 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    int ans = 1;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        ans = 2 * (ans + 1);
    }
    printf("%d\n", ans);
    return 0;
}
