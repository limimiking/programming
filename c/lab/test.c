/*************************************************************************
	> File Name: test.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sun 29 Aug 2021 08:33:11 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int a[2][3] = {0};
    //int (*b)[3] = a;
    int *b = a;
    //b[1][1] = 10;
    *(b + 4)= 10;
    printf("%d\n", a[1][1]);
    return 0;
}
