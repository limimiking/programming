/*************************************************************************
	> File Name: 108.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 14:07:18 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    char type;
    double m, n;
    scanf("%c", &type);
    scanf("%lf%lf", &m, &n);
    printf("%.2lf\n", type == 'r' ? m * n : m * n / 2);
    return 0;
}
