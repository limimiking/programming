/*************************************************************************
	> File Name: 135.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 20:45:09 2021
 ************************************************************************/

#include<stdio.h>

int is_leap_year(int year) {
    return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}

int main() {
    int x, y, m, d;
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d%d", &x, &y, &m, &d);
    if (is_leap_year(y)) day[2] = 29;
    for (int i = 0; i < x; i++) {
        d++;
        if (d > day[m]) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
                if (is_leap_year(y)) day[2] = 29;
                else day[2] = 28;
            }
        }
    }
    printf("%d %d %d\n", y, m, d);

    return 0;
}
