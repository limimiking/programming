/*************************************************************************
	> File Name: 155.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 07:51:45 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num = i * (i + 1) + 3;
        sum += num;
        printf("%d\n", num);
    }
    printf("%d\n", sum);
    return 0;
}
