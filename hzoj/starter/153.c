/*************************************************************************
	> File Name: 152.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 07:30:25 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int y, m, q;
    int h, j, k;
    scanf("%d%d%d", &y, &m, &q);
    if (m == 1 || m == 2) {
        m += 12;
        y -= 1;
    }
    j = y / 100;
    k = y % 100;
    h = (q + 26 * (m + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
    h += 6;
    if (h > 7) h -= 7;
    printf("%d\n", h);
    return 0;
}
