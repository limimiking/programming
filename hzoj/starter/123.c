/*************************************************************************
	> File Name: 123.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 15:01:21 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a <= c && b >= d || a >= c && b <= d)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
