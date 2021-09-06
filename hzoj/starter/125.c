/*************************************************************************
	> File Name: 125.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 15:12:03 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int h, m, s, t;
    double percentage;
    char * period;
    scanf("%d%d%d%d", &h, &m, &s, &t);
    percentage = 100.0 * t / 86400;
    s += t;
    m += s / 60;
    s = s % 60;
    h += m / 60;
    m = m % 60;
    if (h >= 24) h -= 24;
    if (h < 12) period = "am";
    else period = "pm";
    if (h > 12) h -= 12;
    if (h == 0) h = 12;
    printf("%d:%d:%d%s\n", h, m, s, period);
    printf("%.2lf%%\n", percentage);
    return 0;
}
