/*************************************************************************
	> File Name: 113.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jul 12 15:57:11 2021
 ************************************************************************/

#include<stdio.h>

int dom[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int main() {
    int y, m;
    scanf("%d%d", &y, &m);
    if (is_leap_year(y)) dom[2] += 1;
    printf("%d\n", dom[m]);
    return 0;
}
