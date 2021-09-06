/*************************************************************************
	> File Name: 136.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 22 11:18:09 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n / 7; i++) {
        if (i * 7 > n) break;
        printf("%d\n", i * 7);
    }
    return 0;
}
