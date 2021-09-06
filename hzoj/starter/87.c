/*************************************************************************
	> File Name: 87.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 17:09:42 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.2lf\n%.2lf\n", 2 * (a + b), a * b);
    return 0;
}
