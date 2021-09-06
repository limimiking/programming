/*************************************************************************
	> File Name: 165.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 08:55:35 AM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    long long c;
    int cnt = 0;
    scanf("%lld", &c);
    for (long long a = 1; a <= (double)c / sqrt(2.0); a++) {
        long long b = sqrt(c * c - a * a);
        if (a * a + b * b == c * c) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
