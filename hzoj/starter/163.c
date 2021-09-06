/*************************************************************************
	> File Name: 163.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 08:47:27 AM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    double a, b, theta;
    scanf("%lf%lf%lf", &a, &b, &theta);
    printf("%.6lf\n", sqrt(a * a + b * b - 2 * a * b * cos(theta / 180.0 * acos(-1))));
    return 0;
}
