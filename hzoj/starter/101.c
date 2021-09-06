/*************************************************************************
	> File Name: 101.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 20:30:02 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    printf("%d\n", sum);
    return 0;
}
