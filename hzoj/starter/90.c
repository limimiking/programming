/*************************************************************************
	> File Name: 90.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 17:30:36 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", a / 100);
    printf("%d\n", a % 100 / 10);
    printf("%d\n", a % 10);
    return 0;
}
