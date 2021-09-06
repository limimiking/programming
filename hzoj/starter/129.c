/*************************************************************************
	> File Name: 129.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 15:52:31 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n,tmp = 0, min = 10000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp < min) min = tmp;
    }
    printf("%d\n", min);
    return 0;
}
