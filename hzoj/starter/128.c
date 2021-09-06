/*************************************************************************
	> File Name: 128.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 15:48:49 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, tmp = 0;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        sum += tmp;
    }
    printf("%.2lf\n", sum /= n);
    return 0;
}
