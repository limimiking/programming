/*************************************************************************
	> File Name: 160.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 08:36:07 AM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    double r, h;
    scanf("%lf%lf", &r, &h);
    double c = 3.14 * r + 2 * r + 2 * sqrt(2) * r; 
    double a = 3.14 * r * r / 2.0 + 2 * r * r;
    printf("%.2lf\n", c * h + 2 * a);
    return 0;
}
