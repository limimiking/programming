/*************************************************************************
	> File Name: 126.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 15:27:57 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    double r1, r2;
    scanf("%lf%lf", &r1, &r2);
    printf("%.2lf\n", 3.14 * (r1 * r1 - r2 * r2));
    return 0;
}
