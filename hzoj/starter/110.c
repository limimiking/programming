/*************************************************************************
	> File Name: 110.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 14:21:22 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    double X;
    double ans;
    scanf("%lf", &X);
    printf("%.2lf\n", X > 15 ? (90 + (X - 15) * 9) : X * 6);
    return 0;
}
