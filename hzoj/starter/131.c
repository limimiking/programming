/*************************************************************************
	> File Name: 131.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 16:01:16 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, tmp, max = 0, min = 10000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp < min) min = tmp;
        if (tmp > max) max = tmp;
    }
    printf("%d\n", max - min);
    return 0;
}
