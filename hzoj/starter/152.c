/*************************************************************************
	> File Name: 152.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 07:30:25 AM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    char day[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int n;
    scanf("%d", &n);
    n += 3;
    if (n > 7) n -= 7;
    printf("%s\n", day[n-1]);
    return 0;
}
