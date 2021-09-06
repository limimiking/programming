/*************************************************************************
	> File Name: 98.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 20:01:40 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    double r, h;
    scanf("%lf%lf", &r, &h);
    printf("%.2lf\n%.2lf\n", r * r * 3.14, r * r * 3.14 * h);
    return 0;
}
