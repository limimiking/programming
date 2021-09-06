/*************************************************************************
	> File Name: 106.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 11:59:04 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    double n;
    scanf("%lf", &n);
    printf("%g\n", n >= 0 ? n : -n);
    return 0;
}
