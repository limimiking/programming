/*************************************************************************
	> File Name: 90-3.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 19:19:06 2021
 ************************************************************************/

#include<stdio.h>

int reverse_num(int n) {
    int tmp = 0;
    while (n) {
        tmp = tmp * 10 + n % 10;
        n /= 10;
    }
    return tmp;
}

int main() {
    int n;
    scanf("%d", &n);
    n = reverse_num(n);
    while(n) {
        printf("%d\n", n % 10);
        n /= 10;
    }
    return 0;
}
