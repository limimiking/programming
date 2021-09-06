/*************************************************************************
	> File Name: 187.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri 02 Jul 2021 09:36:05 PM CST
 ************************************************************************/

#include<stdio.h>

long long int hanoi_least_step(int n) {
    if (n == 1) return 1;
    return 2 * hanoi_least_step(n - 1) + 1;
}

long long int hanoi_least_power(int n) {
    if (n == 1) return 1;
    return 2 * hanoi_least_power(n - 1) + n;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld %lld\n", hanoi_least_step(n), hanoi_least_power(n));
    return 0;
}
