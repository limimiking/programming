/*************************************************************************
	> File Name: 99.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 20:04:30 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    double v, a;
    scanf("%lf%lf", &v, &a);
    printf("%.2lf\n", v * v / (2 * a));
    return 0;
}
