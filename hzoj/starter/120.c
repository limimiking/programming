/*************************************************************************
	> File Name: 120.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 14:25:48 2021
 ************************************************************************/

#include<stdio.h>

int is_leap_year(int year) {
    return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}

int day_of_month(int year, int month) {
    if (month == 2) {
        if (is_leap_year(year)) return 29;
        return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } 
    return 31;
}
int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if (y < 0) {
        printf("NO\n");
        return 0;
    }
    if (m < 1 || m > 12) {
        printf("NO\n");
        return 0;
    }
    if (d < 1 || d > day_of_month(y, m)) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}
