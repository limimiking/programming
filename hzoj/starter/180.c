/*************************************************************************
	> File Name: 180.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed 30 Jun 2021 05:06:42 PM CST
 ************************************************************************/

#include<stdio.h>

unsigned long long int my_pow(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%llu\n", my_pow(n));
    return 0;
}

unsigned long long int my_pow(int n) {
    unsigned long long int ans = 1;
    for (int i = 0; i < n; i++) ans *= 2;
    return ans;
}
