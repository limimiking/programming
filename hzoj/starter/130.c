/*************************************************************************
	> File Name: 130.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 15:56:41 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int m, n;
    double sum = 0;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++) {
        sum = (sum + m) * 1.00417;
    }
    printf("$%.2lf\n", sum);

    return 0;
}
