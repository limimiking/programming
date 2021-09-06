/*************************************************************************
	> File Name: 122.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 14:50:42 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int t;
    int h, m, s;
    char *period;
    scanf("%d", &t);
    h = t / 3600;
    m = (t % 3600) / 60;
    s = t % 60;
    if (h < 12) period = "am";
    else if (h < 13) period = "midnoon";
    else {
        period = "pm";
        h -= 12;
    }
    printf("%02d:%02d:%02d %s\n", h, m, s, period);
    return 0;
}
