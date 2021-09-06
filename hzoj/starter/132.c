/*************************************************************************
	> File Name: 132.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 16:14:07 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, tmp;
    long long product = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        product *= tmp;
    }
    printf("%lld\n", product);
    return 0;
}
