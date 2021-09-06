/*************************************************************************
	> File Name: 94.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 19:46:47 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    double w,h;
    scanf("%lf%lf", &w, &h);
    printf("%.2lf\n", w / (h * h));
    return 0;
}
