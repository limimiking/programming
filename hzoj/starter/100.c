/*************************************************************************
	> File Name: 100.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 20:07:09 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < 6; i++) {
        sum = (n + sum) * 1.00417;
    }
    printf("$%.2lf\n", sum);
    return 0;
}
