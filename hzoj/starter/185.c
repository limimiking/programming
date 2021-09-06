/*************************************************************************
	> File Name: 185.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri 02 Jul 2021 02:44:57 PM CST
 ************************************************************************/

#include<stdio.h>

int fibonacci[30] = {0};

int init_f(int n) {
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
    }
}
int main() {
    int n;
    scanf("%d", &n);
    init_f(n);
    printf("%d\n", fibonacci[n - 1]);
    return 0;
}
