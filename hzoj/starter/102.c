/*************************************************************************
	> File Name: 102.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 20:32:07 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b, c, t;
    double ans;
    scanf("%d%d%d%d", &a, &b, &c, &t);
    ans = (double)(a * b * c - b * c * t - a * c * t) / (b * c + a * c - a * b) + t;
    printf("%.2lf\n", ans);
    return 0;
}
