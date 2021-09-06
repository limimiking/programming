/*************************************************************************
	> File Name: 1.reverse_num.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 18:10:48 2021
 ************************************************************************/

#include<stdio.h>

long long reverse_num(long long n) {
    long long tmp = 0;
    while (n) {
        tmp = tmp * 10 + n % 10;
        n /= 10;
    }
    return tmp;
}

int main() {
    long long n;
    while (~scanf("%lld", &n)) {
        printf("%lld\n", reverse_num(n));
    }
    return 0;
}
